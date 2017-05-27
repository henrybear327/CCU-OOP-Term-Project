#include "Rational.h"
#include "color.h"

#include <algorithm>
using namespace std;

#include "BigInt.h"
using namespace BigIntNamespace;

namespace RationalNamespace
{
Rational::Rational()
{
    numerator = BigInt(0);
    denominator = BigInt(1);
}

Rational::Rational(int a, int b)
{
    bool isNegativeSign = (long long)a * b >= 0 ? false : true;
    a = abs(a);
    b = abs(b);
    int g = gcd(a, b);

    if (isNegativeSign)
        a *= -1;
    numerator = BigInt(a / g);
    denominator = BigInt(b / g);
}

Rational::Rational(BigInt a, BigInt b)
{
    bool isNegativeSign = BigInt(0) <= a * b ? false : true;
    if (a < BigInt(0))
        a = a * BigInt(-1);
    if (b < BigInt(0))
        b = b * BigInt(-1);

    BigInt g = gcd(a, b);
    numerator = a / g;
    if (isNegativeSign)
        numerator = numerator * BigInt(-1);
    denominator = b / g;
}
//
// const BigInt Rational::getNumerator() const
// {
//     return numerator;
// }
//
// const BigInt Rational::getDenominator() const
// {
//     return denominator;
// }

bool Rational::isNegative() const
{
    return numerator < BigInt(0);
}

const Rational Rational::operator+(const Rational &other) const
{
    BigInt a = this->numerator;
    BigInt b = this->denominator;
    BigInt c = other.numerator;
    BigInt d = other.denominator;

    BigInt ra = a * d + b * c;
    BigInt rb = b * d;

    return Rational(ra, rb);
}

const Rational Rational::operator-(const Rational &other) const
{
    BigInt a = this->numerator;
    BigInt b = this->denominator;
    BigInt c = other.numerator;
    BigInt d = other.denominator;

    BigInt ra = a * d - b * c;
    BigInt rb = b * d;

    return Rational(ra, rb);
}

const Rational Rational::operator*(const Rational &other) const
{
    BigInt a = this->numerator;
    BigInt b = this->denominator;
    BigInt c = other.numerator;
    BigInt d = other.denominator;

    BigInt ra = a * c;
    BigInt rb = b * d;

    return Rational(ra, rb);
}

const Rational Rational::operator/(const Rational &other) const
{
    BigInt a = this->numerator;
    BigInt b = this->denominator;
    BigInt c = other.numerator;
    BigInt d = other.denominator;

    BigInt ra = a * d;
    BigInt rb = b * c;

    return Rational(ra, rb);
}

Rational &Rational::operator=(const Rational &other)
{
    if (this == &other) // self, just return your self
        return *this;

    this->numerator = other.numerator;
    this->denominator = other.denominator;

    return *this;
}

ostream &operator<<(ostream &out, const Rational &other)
{
    out << other.numerator << " / " << other.denominator;
    return out;
}
} // namespace RationalNamespace
