#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>
#include "DSVector.h"
#include <algorithm>

using namespace std;

class DSString
{

private:
    char * string;  // a pointer to a character array containing the string

public:

    //Default constructor
    DSString();

    //constructor that converts a cstring
    DSString(const char *);
    
    // rule of 3
    DSString(const DSString &);  // copy constructor
    ~DSString();  // destructor -- means we need to use new
    DSString &operator=(const DSString &);
    DSString &operator=(const char *); 


    /**
     * Overloaded non-modifying string concat
     */
    DSString operator+(const DSString &) const;

    /**
     * Standard relational operators to compare and order your strings.  
     * Feel free to add additional.
     **/
    bool operator==(const DSString &) const;
    bool operator<(const DSString &) const;
    bool operator>(const DSString &) const;

    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int start, int numChars) const;
    DSString substring(int start, char delim) const;
    DSString substring(char start, char delim) const;

    //findChar finds first instance of char & returns the index
    int findChar(char) const;

    //Tokenizes a DSString and places the "tokens" in a vector
    void token(DSVector<DSString>&);

    //Removes all punctuation & most non-alnum characters from a DSString
    DSString cleanup();
    
    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. It would be smart to always have an extra `\0`
     * at the end of the string in DSString so you can just return a pointer to the
     * objects. 
     **/
    const char *c_str() const;

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
    friend std::ostream &operator<<(std::ostream &, const DSString &);

    /**
     * Overloaded stream extraction operator to get the contents of this
     * string from the input stream in the first argument.
     **/
    friend std::istream &operator>>(std::istream &, const DSString &);

};

#endif