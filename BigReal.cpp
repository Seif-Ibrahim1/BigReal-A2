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
    this->decimalPart = bigInt;
    this->fractionPart = BigDecimalInt("0");
    this->numSign = bigInt.sign() == 1 ? '+' : '-';
}

// ahmed
// Copy constructor
BigReal::BigReal(const BigReal &other) {
    this->decimalPart  = other.decimalPart ;
    this->fractionPart = other.fractionPart;
    this->number = other.number;
    this->doubleNum = other.doubleNum; // for the default constructor
    this->numSign = other.numSign;
}

// ahmed
// Move constructor
BigReal::BigReal(BigReal &&other) {
    this->decimalPart  = move(other.decimalPart) ;
    this->fractionPart = move(other.fractionPart);
    this->number = move(other.number);
    this->doubleNum = move(other.doubleNum); // for the default constructor
    this->numSign = move(other.numSign);
}

// ahmed
// Assignment operator
BigReal &BigReal::operator=(BigReal &other) {
    if(this != &other){
        this->decimalPart  = other.decimalPart ;
        this->fractionPart = other.fractionPart;
        this->number = other.number;
        this->doubleNum = other.doubleNum; // for the default constructor
        this->numSign = other.numSign;
    }
    return *this;
}

// ahmed
// Move assignment
BigReal &BigReal::operator=(BigReal &&other) {
    if(this != &other){
        this->decimalPart  = move(other.decimalPart) ;
        this->fractionPart = move(other.fractionPart);
        this->number = move(other.number);
        this->doubleNum = move(other.doubleNum); // for the default constructor
        this->numSign = move(other.numSign);
    }
    return *this;
}

// seif
string BigReal::getNum() {
    number = (decimalPart.sign() == 0 ? "-" : "") + decimalPart.getNumber() + "." + fractionPart.getNumber();
    return number;
}

// seif
string BigReal::changeNumSign(BigReal num, int sign) {
    string newNum = sign == 1 ? "+" : "-" ;
    newNum += num.decimalPart.getNumber() + "." + num.fractionPart.getNumber();
    return newNum;
}

//seif
BigReal BigReal::operator+(BigReal &other) {

    BigReal sum;
    
    // 1 == + && 0 == - 
    if(this->decimalPart.sign() == 1 && other.decimalPart.sign() == 0) {
        BigReal newNum(changeNumSign(other, 1));
        return *this - newNum;
    } else if (this->decimalPart.sign() == 0 && other.decimalPart.sign() == 1) {
        BigReal newNum = BigReal(changeNumSign(*this, 1));
        return other - newNum;
    } else {
        
        bool isNegative;
        if(this->decimalPart.sign() == 1 && other.decimalPart.sign() == 1) {
            isNegative = false;
        } else if (this->decimalPart.sign() == 0 && other.decimalPart.sign() == 0) {
            isNegative = true;
        }

        string fraction1 =  this->fractionPart.getNumber();
        string fraction2 =  other.fractionPart.getNumber();
        string fractionSum = "";
        string num1, num2, strSum;
        int reminder = 0 , intSum;
        while(fraction1.length() > fraction2.length()) {
            fraction2 += '0';
        }
        while(fraction2.length() > fraction1.length()) {
            fraction1 += '0';
        }
        for(int i = fraction1.length() - 1; i >= 0; i--) {
            num1 = fraction1[i];
            num2 = fraction2[i];
            intSum = stoi(num1) + stoi(num2) + reminder;
            strSum = to_string(intSum);
            reminder = 0;
            if(strSum.length() > 1) {
                reminder = 1;
                fractionSum.insert(fractionSum.begin(), strSum[1]);
            } else {
                fractionSum.insert(fractionSum.begin(), strSum[0]);
            }
            
        }
        
        sum.decimalPart = this->decimalPart + other.decimalPart;
        if (reminder != 0) {

            sum.decimalPart = isNegative ? sum.decimalPart + BigDecimalInt("-1") : sum.decimalPart + BigDecimalInt("1");
        }
        sum.fractionPart = BigDecimalInt(fractionSum);

        return sum;
    }
     
    
}

// seif
BigReal BigReal::operator-(BigReal &other) {
    BigReal dif;
    
    // 1 == + && 0 == - 
    if(this->decimalPart.sign() == 1 && other.decimalPart.sign() == 0) {
        BigReal newNum(changeNumSign(other, 1));
        return *this + newNum;
    } else if (this->decimalPart.sign() == 0 && other.decimalPart.sign() == 1) {
        BigReal newNum(changeNumSign(other, 0));
        return *this + newNum;
    } else if (this->decimalPart.sign() == 0 && other.decimalPart.sign() == 0) {
        BigReal newNum = BigReal(changeNumSign(other, 1));
        return newNum + *this;
    } else  {
        bool isReversed;
        BigReal num1;
        BigReal num2;
        if(*this < other) {
            num1 = other;
            num2 = *this;
            isReversed = true;
        } else {
            num1 = *this;
            num2 = other;
            isReversed = false;
        }
        string fraction1 =  num1.fractionPart.getNumber();
        string fraction2 =  num2.fractionPart.getNumber();
        while(fraction1.length() > fraction2.length()) {
            fraction2 += '0';
        }
        while(fraction2.length() > fraction1.length()) {
            fraction1 += '0';
        }
        BigDecimalInt decimalNum1("1" + fraction1);
        BigDecimalInt decimalNum2(fraction2);

        BigDecimalInt fractionDif = decimalNum1 - decimalNum2;
        string fractionDifStr = fractionDif.getNumber();


        if(fractionDifStr.length() < fraction1.length()) {
            while(fractionDifStr.length() < fraction1.length()) {
                fractionDifStr.insert(fractionDifStr.begin(), '0');
            }
            dif.decimalPart = num1.decimalPart - num2.decimalPart - BigDecimalInt("1");
            
        } else if (fractionDifStr.length() > fraction1.length()) {
            while(fractionDifStr.length() > fraction1.length()) {
                fractionDifStr.erase(fractionDifStr.begin());
            }
            dif.decimalPart = num1.decimalPart - num2.decimalPart;
        } else {
            dif.decimalPart = num1.decimalPart - num2.decimalPart - BigDecimalInt("1");
        }

        if(isReversed) {
            dif.decimalPart = BigDecimalInt("-" + dif.decimalPart.getNumber());
        }

        dif.fractionPart = BigDecimalInt(fractionDifStr);

        return dif;
        

    }
}

// shahd
bool BigReal::operator<(BigReal anotherReal) {
    if (decimalPart < anotherReal.decimalPart) {
        return true;
    }
    else if (decimalPart == anotherReal.decimalPart)
    {
        string fraction1 = fractionPart.getNumber();
        string fraction2 = anotherReal.fractionPart.getNumber();
        while (fraction1.length() > fraction2.length()) {
            fraction2 += '0';
        }
        while (fraction2.length() > fraction1.length()) {
            fraction1 += '0';
        }
        if(fraction1 < fraction2)
            return true;
        else
            return false;
    }
    else {
        return false;
    }
}

// shahd
bool BigReal::operator>(BigReal anotherReal) {
    if (decimalPart > anotherReal.decimalPart) {
        return true;
    } else if (decimalPart == anotherReal.decimalPart) {
        string fraction1 = fractionPart.getNumber();
        string fraction2 = anotherReal.fractionPart.getNumber();
        while (fraction1.length() > fraction2.length()) {
            fraction2 += '0';
        }
        while (fraction2.length() > fraction1.length()) {
            fraction1 += '0';
        }
        if (fraction1 > fraction2)
            return true;
        else
            return false;
    } else {
        return false;
    }
}


// shahd
bool BigReal::operator==(BigReal anotherReal) {
    if (decimalPart == anotherReal.decimalPart && fractionPart == anotherReal.fractionPart) {
        return true;
    } else {
        return false;
    }
}

// shahd
int BigReal::size() {
    return decimalPart.size() + fractionPart.size();
}

// shahd
int BigReal::sign() {
    return decimalPart.sign();
}


// shahd
ostream &operator<<(ostream &out, BigReal num) {
    out << num.decimalPart << "." << num.fractionPart;
    return out;
}

// shahd
istream &operator>>(istream &in, BigReal &num) {
    in >> num.number;
    num = BigReal(num.number);
    return in;
}


