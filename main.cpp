#include <iostream>
using namespace std;

#include "color.h"

#include "Complex.h"
using namespace ComplexNamespace;

int main()
{
// cout << "Project 5" << endl;
#ifdef DEBUG
    if (DEBUG > 0) {
        cout << RED "Debug mode is enabled" RESET << endl;
        cout << RED "Debug level is " << DEBUG << "" RESET << endl;

        cout << Rational(1, 3) << endl;
        cout << Rational(-6, 17) << endl;
        cout << BigInt(81).factorial() << endl;
        cout << BigInt(320).factorial() << endl;
        cout << BigInt(128).factorial() << endl;
        cout << BigInt(520).factorial() << endl;
        cout << Rational(BigInt(81).factorial(), BigInt(320).factorial()) << endl;
        cout << Rational(BigInt(128).factorial(), BigInt(520).factorial()) << endl;
        cout << Complex(Rational(BigInt(81).factorial(), BigInt(320).factorial()),
                        Rational(BigInt(128).factorial(), BigInt(520).factorial()))
             << endl;
    }
#endif

    Complex c1(Rational(1, 3), Rational(-6, 17));
    // cout << c1 << endl;

    Complex c2(Rational(BigInt(81).factorial(), BigInt(320).factorial()),
               Rational(BigInt(128).factorial(), BigInt(520).factorial()));
    // cout << c2 << endl;

    cout << c1 / c2 << endl;
    return 0;
}
