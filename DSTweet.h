#ifndef DSTWEET_H
#define DSTWEET_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "DSString.h"
#include "DSVector.h"

using namespace std;


class DSTweet{
    private:
        DSString ground;
        DSString predict;
        DSString id;
        DSString tweet;
    public:

    //default constructor
    DSTweet(){
        ground = "-1";
        id = "1111";
        tweet = "empty";
        predict = "-1";
    }

    //set functions
    void setGround(DSString s){
        ground = s;
    }
    void setId(DSString i){
        id = i;
    }
    void setTweet(DSString t){
        tweet = t;
    }
    void setPredict(DSString p){
        predict = p;
    }

    //get functions
    DSString getGround() {
        return ground;
    }
    DSString getId() {
        return id;
    }
    DSString getTweet() {
        return tweet;
    }
    DSString getPredict() {
        return predict;
    }
};

#endif