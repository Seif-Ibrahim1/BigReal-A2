#include "BigReal.h"

int main() {
    BigReal num1("22.44");
    BigReal num2(".86");
    BigReal num3("-00.9");
    BigReal num4("-000055.000540000000");
    BigReal num5("34.86");
//        BigReal num6("9.8.7"); // should print error

    cout << num1.getNum() << endl;
    cout << num2.getNum() << endl;
    cout << num3.getNum() << endl;
    cout << num4.getNum() << endl;
    cout << num5.getNum() << endl;

    cout << "Worked" << endl;

    return 0;
}



