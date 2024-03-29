/*
Team 11
曾俊宏
403410033
資工系
大三
*/

#ifndef RATIONAL_H
#define RATIONAL_H

// must include headers OUTSIDE of namespaces!
#include <iostream>
using namespace std;

#include "BigInt.h"
#include "color.h"
using namespace BigIntNamespace;

namespace RationalNamespace
{
class Rational
{
public:
    Rational();
    Rational(int a, int b);
    Rational(BigInt a, BigInt b);

    const Rational operator+(const Rational &other) const;
    const Rational operator-(const Rational &other) const;
    const Rational operator*(const Rational &other) const;
    const Rational operator/(const Rational &other) const;
    Rational &operator=(const Rational &other);

    friend ostream &operator<<(ostream &out, const Rational &other);

    // const BigInt getNumerator() const;
    // const BigInt getDenominator() const;
    bool isNegative() const;

private:
    BigInt numerator;
    BigInt denominator;
};
} // namespace RationalNamespace

#endif
