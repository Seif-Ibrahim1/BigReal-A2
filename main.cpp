#include "BigReal.h"

int main() {
    BigReal num1("22.44");
    BigReal num2(".86");
    BigReal num3("9.");
    // BigReal num4("9.8.7"); // should print error
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



