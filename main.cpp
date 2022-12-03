#include "BigReal.h"

int main() {
    BigReal num1("123.456");
    BigReal num2(".456");
    BigReal num3("-123.456");
    BigReal num4("+123.456");
    BigReal num5("-0000000500000.456");
    BigReal num6("-.456");
    BigReal num7("123.456");
    BigReal num8;
    BigReal num9;
    BigReal num12("100.9088");
    BigReal num13("-1000.8500");
    BigReal num15("0");
    BigReal num16("99.");
    Bigreal num17("1.2");
    Bigreal num18("1.20");

    // check the copy constructor
    BigReal num10(num1);
    cout << "num10: " << num10 << endl;


    // check the move constructor
    BigReal num11(move(num1));
    cout << "num11: " << num11 << endl;


    // check the assignment operator
    num8 = num2;
    cout << "num8: " << num8 << endl;


    // check the move assignment operator
    num9 = move(num3);
    cout << "num9: " << num9 << endl;


    // check the + operator
    cout << "num1 + num2: " << (num1 + num2) << endl;
    cout << "num1 + num12: " << (num1 + num12) << endl;
    cout << "num7 + num12: " << (num7 + num12) << endl;


    // check the - operator
    cout << "num1 - num2: " << (num1 - num2) << endl;
    cout << "num12 - num1 : " << (num12 - num1) << endl;


    //check operator >
    cout << "num1 > num2: " << (num1 > num2) << endl;
    cout << "num1 > num3: " << (num1 > num3) << endl;
    cout << "num2 > num4: " << (num2 > num4) << endl;
    cout << "num6 > num5: " << (num6 > num5) << endl;

    //check operator <
    cout << "num1 < num2: " << (num1 < num2) << endl;
    cout << "num2 < num5: " << (num2 < num5) << endl;
    cout << "num6 < num5: " << (num6 < num5) << endl;

    //check operator ==
    cout << "num1 == num2: " << (num1 == num2) << endl;
    cout << "num1 == num7: " << (num1 == num7) << endl;
    cout << "num17 == num18:" << (num17 == num18) << endl;

    // check sign function
    cout << "num1 sign: " << num1.sign() << endl;
    cout << "num3 sign: " << num3.sign() << endl;

    // check size function
    cout << "num5 size: " << num5.size() << endl;
    cout << "num6 size: " << num6.size() << endl;

    //invalid input
    BigReal num14("- 123.456");
    return 0;
}



