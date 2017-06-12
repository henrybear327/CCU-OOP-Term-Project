/*
Team 11
曾俊宏
403410033
資工系
大三
*/

#include <iostream>
using namespace std;

#include "color.h"

#include "Complex.h"
using namespace ComplexNamespace;

int main()
{
    Complex c1(Rational(1, 3), Rational(-6, 17));
    // cout << c1 << endl;

    Complex c2(Rational(BigInt(81).factorial(), BigInt(320).factorial()),
               Rational(BigInt(128).factorial(), BigInt(520).factorial()));
    // cout << c2 << endl;

    cout << c1 / c2 << endl;

    // // 1/10000! + 2/10000!
    // Rational c1(1, BigInt(10000).factorial());
    // Rational c2(1, BigInt(20000).factorial());
    //
    // cout << c1 / c2 << endl;

    return 0;
}
