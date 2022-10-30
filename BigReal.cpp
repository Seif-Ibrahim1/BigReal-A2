#include "BigReal.h"
// ahmed
// Default constructor
BigReal::BigReal (double realNum) {
    this->doubleNum = realNum;
}

// ahmed
BigReal::BigReal (string realNum) {
    this->number = realNum;
}

// ahmed
BigReal::BigReal (BigDecimalInt bigInt) {

}

// ahmed
// Copy constructor
BigReal::BigReal (const BigReal& other) {

}

// ahmed
// Move constructor
BigReal::BigReal (BigReal&& other) {

}

// ahmed
// Assignment operator
BigReal& BigReal::operator= (BigReal& other) {

}

// ahmed
// Move assignment
BigReal& BigReal::operator= (BigReal&& other) {

}

//seif
BigReal BigReal::operator+ (BigReal& other) {

}

//seif
BigReal BigReal::operator- (BigReal& other) {

}

//shahd
bool BigReal::operator< (BigReal anotherReal) {

}

//shahd
bool BigReal::operator> (BigReal anotherReal) {

}

//shahd
bool BigReal::operator== (BigReal anotherReal) {

}

//shahd
int BigReal::size() {

}

//shahd
int BigReal::sign() {

}

//shahd
ostream& operator << (ostream& out, BigReal num) {

}

//shahd
istream& operator >> (istream& out, BigReal num) {

}


