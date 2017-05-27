#include "Rational.h"
#include "color.h"

namespace RationalNamespace
{
    Rational::Rational()
    {
        numerator = BigInt(0);
        denominator = BigInt(1);
    }

    Rational::Rational(int a, int b)
    {
        numerator = BigInt(a);
        denominator = BigInt(b);
    }

    Rational::Rational(BigInt a, BigInt b)
    {
        numerator = a;
        denominator = b;
    }

    // const Rational Rational::operator+(const Rational &other) const;
    // const Rational Rational::operator-(const Rational &other) const;
    // const Rational Rational::operator*(const Rational &other) const;
    // const Rational Rational::operator/(const Rational &other) const;
    // Rational &Rational::operator=(const Rational &other);
    //
    // ostream &Rational::operator<<(ostream &out, const Rational &other);
}
