#include "BigReal.h"

int main() {
    BigReal num1("-22.44");
    BigReal num2(".86");
    BigReal num3("-00.9");
    BigReal num4("-000055.000540000000");
    BigReal num5("34.86");
    BigReal num6("96.");

    BigReal num7("-00.9");
    BigReal num8("-000055.000540000000");
    BigReal num9(BigDecimalInt("0"));
    BigReal num10 = num8;
//    num10 = num8;
//        BigReal num6("9.8.7"); // should print error

    cout << num10.getNum() << endl;
//    cout << num2.getNum() << endl;
//    cout << num3.getNum() << endl;
//    cout << num4.getNum() << endl;
//    cout << num5.getNum() << endl;
//
//    cout << num6.size() << endl;
//    cout << num6.sign() << endl;
//    cout << num1.sign() << endl;
//
//    // not working
//    if(num2 < num6) {
//        cout << "true" << endl;
//    } else {
//        cout << "False" << endl;
//    }
//
//    // not working
//    if(num7 > num8) {
//        cout << "true" << endl;
//    } else {
//        cout << "False" << endl;
//    }
//
//    cout << "Worked" << endl;

    return 0;
}



