/*
Team 11
曾俊宏
403410033
資工系
大三
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include "color.h"

#include "Rational.h"
using namespace RationalNamespace;

namespace ComplexNamespace
{
class Complex
{
public:
    Complex();
    Complex(Rational a, Rational b);

    const Complex operator+(const Complex &other) const;
    const Complex operator-(const Complex &other) const;
    const Complex operator*(const Complex &other) const;
    const Complex operator/(const Complex &other) const;
    Complex &operator=(const Complex &other);

    friend ostream &operator<<(ostream &out, const Complex &other);

private:
    Rational real;
    Rational imaginary;
};
} // namespace ComplexNamespace

#endif
