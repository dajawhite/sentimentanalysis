#include "DSString.h"

//Constructors

DSString::DSString(){
    string = new char[1]; //new array use brackets instead of star
    *string = '\0'; //dereference the pointer to put stuff in the memory where string is
}

DSString::DSString(const char* userstr){ 
    string = new char[strlen(userstr) + 1];
    strcpy(string, userstr);
    for (int i = 0; userstr[i]!='\0';i++){
        string [i] = userstr[i];
    }
}

// copy constructor
DSString::DSString(const DSString & userstr){
    string = new char[strlen(userstr.string)+1];
    strcpy(string,userstr.string);
}

DSString::~DSString(){
    delete [] string;
}

DSString& DSString::operator=(const DSString & userstr){
    if(string == userstr.string){
        return *this; 
    }
    else{
        delete [] string;
        string = new char[strlen(userstr.string)+1];
        strcpy(string, userstr.string);
        return *this;
    }
}

DSString& DSString::operator=(const char * userstr){ 
    if(string == userstr){
        return *this;
    }
    else {
        delete [] string;
        string = new char[strlen(userstr) + 1];
        strcpy(string, userstr);
        return *this;
    }
}

DSString DSString::operator+(const DSString & str2) const{
    strcat(string, str2.string);
    return *this;
}

bool DSString::operator==(const DSString & str2) const{
    if (strlen(string)!= strlen(str2.string)){
        return false;
    }
    else{
        for (size_t i = 0; i < strlen(string); i++){
            if (string[i] != str2.string[i]){
                return false;
            }
            else{
                return true;
            }
        }
    }
}

bool DSString::operator<(const DSString & str2) const{
    return string < str2.string;
}

bool DSString::operator>(const DSString & str2) const{
    return string > str2.string;
}

DSString DSString::substring(int start, int numChars) const{
    DSString newstr;
    newstr.string = new char[numChars +1];
    int k = 0;
    for (int i = start; k < numChars; i++){
        newstr.string[k] = string[i];
        k++;
    }
    return newstr;
}

DSString DSString::substring(int start, char delim) const{
    DSString newstr;
    int k = 0;
    int numChars = 0;
    int i = 0;
    if (strlen(string) > 0){
        for (i = start; string[i]!=delim; i++){
        numChars++;
        }
    }
    newstr.string = new char[numChars + 1];
    for (int j = start; k < numChars; j++){
        newstr.string[k] = string[j];
        k++;
    }
    newstr.string[k]='\0';
    return newstr;
}

DSString DSString::substring(char start, char delim) const{
    DSString newstr;
    size_t k = 0;
    size_t numChars = 0;
    for (size_t l = 0; string[l]!=delim; l++){
        numChars++;
    }
    //find index of start
    int index = -1;
    for (int i = 0; string[i]!= '\0'; i++){
        if (string[i] == start){
            index = i;
        }
    }
    newstr.string = new char[numChars + 1];
    for (size_t j = index; k < numChars; j++){
        newstr.string[k] = string[j];
        k++;
    }
    newstr.string[k]='\0';
    return newstr;
}

//finds first instance of a character
int DSString::findChar(char find) const{
    int index;
    for (int i = 0; string[i]!= '\0'; i++){
        if (string[i] == find){
            index = i;
            return index;
        }
        else {
            index = -1;
        }
    }
    return index;
}

DSString DSString::cleanup(){
    size_t numChars = 0;
    for (size_t i = 0; string[i]!= '\0'; i++){
        if (!(ispunct(string[i]))){
            numChars++;
        }
    }
    DSString newStr;
    delete [] newStr.string;
    newStr.string = new char[numChars + 1];
    size_t i;
    size_t k =0;
    for (i = 0; k < numChars; i++){
        if (!(ispunct(string[i]))){ 
            newStr.string[k] = string[i];
        }
        else if (ispunct(string[i])){
            while (ispunct(string[i])){
                i++;
            }
            newStr.string[k] = string[i];
        }
        k++;
    }
    newStr.string[k]= '\0';
    return newStr;
}

void DSString::token(DSVector<DSString>& a){
    //https://cplusplus.com/reference/cstring/strtok/
    char * b;
    b = strtok (string," ,.!\"@#$&;?:()/=+-*");
    DSString w;
    w = b;
    a.push_back(w);
    while (b != NULL){
        b = strtok (NULL, " ,.!\"@#$&;?:()/=+-*");
        if (b != NULL){
            w = b;
            a.push_back(w);
        }
    }
}

std::ostream& operator<<(std::ostream& cout, const DSString & str){
    return cout << str.string;
}

std::istream &operator>>(std::istream & cin, const DSString & str){
    return cin >> str.string;
}




