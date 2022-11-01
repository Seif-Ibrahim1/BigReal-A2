#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <regex>
#include <string>
#include <ctype.h>
#include "BigDecimalIntClass.cpp"


using namespace std;

class BigReal {
private:
    BigDecimalInt decimalPart;
    BigDecimalInt fractionPart;
    string number;
    double doubleNum; // for the default constructor
    char numSign;
    bool checkValidInput(string input);


public:
    BigReal (double realNum = 0.0); // Default constructor
    BigReal (string realNum);
    BigReal (BigDecimalInt bigInt);
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    string getNum();
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& out, BigReal num);
};

#endif