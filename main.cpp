#include "BigReal.h"

int main() {
    BigReal num1("22.44");
    BigReal num2(".86");
    BigReal num3("9.");
    // BigReal num4("9.8.7"); // should print error
    BigReal num6("000055.540000000");
    BigReal num7("-34.86");
    BigReal num8("-34.86");

    cout<< num1.getNum() <<endl;
    cout<< num2.getNum() <<endl;
    cout<< num3.getNum() <<endl;

    cout << num6.size() << endl;
    cout << num6.sign() << endl;
    cout << num1.sign() << endl;

    cout << (num1 < num8) << endl;
    cout << (num7 == num8) << endl; 

    cout << "Worked" << endl;

    return 0;
}



