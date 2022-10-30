// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 2
// Program Name: BigDecimalReal
// Last Modification Date: 10/11/2022
// Author1 and ID : Ahmed Adel Mahmoud Hemdan , ID : 20210025
// Author2 and ID : Seif
// Author3 and ID : Shahd
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited Double values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <regex>
#include "BigDecimalIntClass.h"


using namespace std;

class BigReal {
public:
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