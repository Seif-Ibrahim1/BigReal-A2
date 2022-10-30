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

#include "BigReal.h"

int main() {
    BigReal num1("22.44");
    BigReal num2(".86");
    BigReal num3("9.");
//    BigReal num4("9.8.7"); // should print error
    BigReal num6("000055.540000000");
    BigReal num7("34.86");

    cout<< num1.decimalPart<<endl;
    cout<< num1.fractionPart<<endl;
    cout<< num2.decimalPart<<endl;
    cout<< num2.fractionPart<<endl;
    cout<< num3.decimalPart<<endl;
    cout<< num3.fractionPart<<endl;
    cout << "Worked" << endl;

    return 0;
}



