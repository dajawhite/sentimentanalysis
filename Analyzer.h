#ifndef ANALYZER_H
#define ANALYZER_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>

#include "DSString.h"
#include "DSVector.h"
#include "DSTweet.h"

const int BUFFER = 500;

using namespace std;

//This object can train, classify, and evaluate.
class Analyzer{
    private:
        DSVector <DSString> negWords, posWords;
        DSVector <DSTweet> testData, answers;
        double accuracy = 0.0;
        DSVector <int> wrongIndx;
        

    public:
        //Default constructor
        Analyzer(){
            negWords.resize(0);
            posWords.resize(0);
            testData.resize(0);
            answers.resize(0);
        }

        //Trainer makes a list of + & - words from training data.
        void Train(const char** argv){
            ifstream inFile;
            char line[BUFFER];  
            DSString info; 
            DSVector <DSString> data;

            //Open the train_dataset_20k.csv
            inFile.open(argv[1]);

            //Add each line of the file to data vector
            if (inFile.is_open()){
                while (!inFile.eof()){
                    inFile.getline(line, 15000);
                    info = line;
                    data.push_back(info);
                }
            }    
            else{
                cout << "Error: File Not Open." << endl;
            }

            //Close the file
            inFile.close();

            DSVector<DSTweet> s_i_t;
            s_i_t.resize(data.size());

            //Extract key info from data, store in s_i_t vector 
            for (size_t i = 0; i < data.size(); i++){
                s_i_t[i].setGround(data[i].substring(0, 1));
                s_i_t[i].setId(data[i].substring(2, 10));

                DSString t = data[i].substring(51, '\0');
            
                int start = t.findChar(',');

                DSString tmp = t.substring(start + 1,'\0');
                tmp.cleanup();

                s_i_t[i].setTweet(tmp);
            }
    
            //Training 
            for (size_t i = 0; i < s_i_t.size(); i++){
                DSString sentiment;
                sentiment = s_i_t[i].getGround(); //what's the sentiment for the tweet?

                //tokenize & add words to library
                if (sentiment == "4"){
                    s_i_t[i].getTweet().token(posWords);
                }
                else if (sentiment == "0"){
                    s_i_t[i].getTweet().token(posWords);
                }
            }
            return;
        }

        //Processes the data from the test file
        void ProcessTestData(const char** argv){
            ifstream inFile;
            char line[BUFFER];  
            DSString info; 
            DSVector <DSString> data;

            //Open the test_dataset_10k.csv
            inFile.open(argv[2]);

            //Add each line of the file to data vector
            if (inFile.is_open()){
                while (!inFile.eof()){
                    inFile.getline(line, 15000);
                    info = line;
                    data.push_back(info);
                }
            }    
            else{
                cout << "Error: File Not Open." << endl;
            }

            //Close the file
            inFile.close();

            testData.resize(data.size());

            //Extract key info from data, store in testData 
            for (size_t i = 0; i < data.size(); i++){
                testData[i].setId(data[i].substring(0, 10));
                DSString t = data[i].substring(49, '\0');
            
                int start = t.findChar(',');

                DSString tmp = t.substring(start + 1,'\0');
                tmp.cleanup();

                testData[i].setTweet(tmp);
            }
            return;
        }

        //Classifies the test data
        void Classify(const char** argv){
            for (size_t i = 0; i < testData.size(); i++){
                DSVector<DSString> tokens;
                ofstream outFile;

                int posCount = 0;
                int negCount = 0;

                testData[i].getTweet().token(tokens);

                for (size_t k = 0; k < tokens.size(); k++){
                    DSString *ptr = find(posWords.begin(), posWords.end(), tokens[k]);
                    if (ptr != posWords.end()){
                        posCount++;
                    }
                }
                for (size_t j = 0; j < tokens.size(); j++){
                    DSString *ptr = find(negWords.begin(), negWords.end(), tokens[j]);
                    if (ptr != negWords.end()){
                        negCount++;
                    }
                }

                if (posCount > negCount){
                    testData[i].setPredict("4");
                }
                else if (negCount > posCount){
                    testData[i].setPredict("0");
                }
                else if (posCount == negCount){
                    testData[i].setPredict("4");
                }

                outFile.open(argv[4]);
                for (size_t i = 0; i < testData.size(); i++){
                    DSString p = testData[i].getPredict();
                    DSString ID = testData[i].getId();
                    outFile << p << ", " << ID << endl;
                }
                outFile.close();
            }
        }

        //Stores data from test file with sentiments
        void StoreAnswers(const char** argv){
            ifstream inFile;
            char line[BUFFER];  
            DSString info; 
            DSVector <DSString> data;

            //Open the test_dataset_sentiment_10k.csv
            inFile.open(argv[3]);

            //Add each line of the file to data vector
            if (inFile.is_open()){
                while (!inFile.eof()){
                    inFile.getline(line, 15000);
                    info = line;
                    data.push_back(info);
                }
            }    
            else{
                cout << "Error: File Not Open." << endl;
            }

            //Close the file
            inFile.close();

            answers.resize(testData.size());

            //Extract key info from data, store in testData 
            for (size_t i = 0; i < data.size(); i++){
                answers[i].setGround(data[i].substring(0, 1));
                answers[i].setId(data[i].substring(2,10));
            }
        }

        //Evaluates the predictions made
        void Evaluate(const char** argv){
            double correct = 0;
            double numTweets = 0;
            ofstream outFile;
            for (size_t i = 0; i < testData.size(); i++){
                DSString tID = testData[i].getId();
                DSString aID = answers[i].getId();

                DSString p = testData[i].getPredict();
                DSString g = answers[i].getGround();

                if ((tID == aID) && (p == g)){
                    correct++;
                }
                else if ((tID == aID) && (!(p == g))){
                    wrongIndx.push_back(i);
                }
                numTweets++;
            }
            accuracy = correct / numTweets; 
            cout << "Accuracy: " << accuracy << endl;

            outFile.open(argv[5]);
            cout << fixed << setprecision(3);
            cout << accuracy << endl;
            for (size_t i = 0; wrongIndx.size(); i++){
                int k = wrongIndx[i];
                DSString p = testData[k].getPredict();
                DSString id = testData[k].getPredict();
                DSString g = answers[k].getGround();

                cout << p << ", " << g << ", " << id << endl;
            }
            outFile.close();
            return;
        }

};


#endif

