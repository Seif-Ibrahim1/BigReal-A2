#include "BigReal.h"

int main() {
    BigReal num1("22.44");
    BigReal num2(".86");
    BigReal num3("9.");
    BigReal num4("9.8.7"); // should print error 
    BigReal num6("000055.540000000");
    BigReal num7("34.86");

    cout << "Worked" << endl;

    return 0;
}



