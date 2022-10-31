#include "BigReal.h"


// regex function that checks the validation of the input.
bool BigReal::checkValidInput(string input) {
    if (input == ".")
        return false;
    regex validInput("[-+]?[0-9]*.[0-9]*");
    return regex_match(input, validInput);
}

// ahmed
// Default constructor
BigReal::BigReal(double realNum) {
    this->doubleNum = realNum;
}

// ahmed
BigReal::BigReal(string realNum) {
//    this->number = realNum;

    bool validNumber = checkValidInput(realNum);
    if (validNumber) {

        //delete right fraction zeros
        while (realNum.back() == '0') {
            realNum.pop_back();
        }
        //delete left decimal zeros
        int signLength = (realNum[0] == '+' || realNum[0] == '-') ? 1 : 0;
        while (realNum[0 + signLength] == '0') {
            realNum.erase(0 + signLength, 1);
        }

        // separate decimal and fraction parts
        for (int i = 0; i < realNum.length(); i++) {
            if (realNum[i] == '.') {
                // check if any part == "" then put "0"
                string decimalPart = realNum.substr(0, i) != "" ? realNum.substr(0, i) : "0";
                decimalPart =
                        (realNum.substr(0, i) == "+") || (realNum.substr(0, i) == "-") ? realNum.substr(0, i) + "0"
                                                                                       : decimalPart;
                string fractionPart = realNum.substr(i + 1) != "" ? realNum.substr(i + 1) : "0";
                this->decimalPart = BigDecimalInt(decimalPart);
                this->fractionPart = BigDecimalInt(fractionPart);
                this->numSign = this->decimalPart.sign() == 1 ? '+' : '-';
                break;
            }
        }


    } else {
        cout << "Invalid Real Number" << "\n";
        exit(1);
    }
}

// ahmed
BigReal::BigReal(BigDecimalInt bigInt) {

}

// ahmed
// Copy constructor
BigReal::BigReal(const BigReal &other) {

}

// ahmed
// Move constructor
BigReal::BigReal(BigReal &&other) {

}

// ahmed
// Assignment operator
BigReal &BigReal::operator=(BigReal &other) {

}

// ahmed
// Move assignment
BigReal &BigReal::operator=(BigReal &&other) {

}

//seif
string BigReal::getNum() {
    number = (decimalPart.sign() == 0 ? "-" : "") + decimalPart.getNumber() + "." + fractionPart.getNumber();
    return number;
}

//seif
BigReal BigReal::operator+(BigReal &other) {

}

//seif
BigReal BigReal::operator-(BigReal &other) {

}

//shahd
bool BigReal::operator<(BigReal anotherReal) {
    if (decimalPart < anotherReal.decimalPart) {
        return true;
    }
    else if (decimalPart == anotherReal.decimalPart) {
        if (fractionPart < anotherReal.fractionPart) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

//shahd
bool BigReal::operator>(BigReal anotherReal) {
    if (decimalPart > anotherReal.decimalPart) {
        return true;
    }
    else if (decimalPart == anotherReal.decimalPart) {
        if (fractionPart > anotherReal.fractionPart) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

//shahd
bool BigReal::operator==(BigReal anotherReal) {
    if (decimalPart == anotherReal.decimalPart && fractionPart == anotherReal.fractionPart) {
        return true;
    }
    else {
        return false;
    }
}

//shahd
int BigReal::size() {
    return decimalPart.size() + fractionPart.size();
}

//shahd
int BigReal::sign() {
    return decimalPart.sign();
}


//shahd
ostream &operator<<(ostream &out, BigReal num) {

}

//shahd
istream &operator>>(istream &out, BigReal num) {

}


