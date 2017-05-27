#include "Complex.h"

#include "Rational.h"
#include "color.h"
using namespace RationalNamespace;

namespace ComplexNamespace
{
Complex::Complex()
{
    real = Rational(0, 1);
    imaginary = Rational(0, 1);
}

Complex::Complex(Rational a, Rational b)
{
    real = a;
    imaginary = b;
}

const Complex Complex::operator+(const Complex &other) const
{
    Complex res;
    res.real = this->real + other.real;
    res.imaginary = this->imaginary + other.imaginary;
    return res;
}

const Complex Complex::operator-(const Complex &other) const
{
    Complex res;
    res.real = this->real - other.real;
    res.imaginary = this->imaginary - other.imaginary;
    return res;
}

const Complex Complex::operator*(const Complex &other) const
{
    Complex res;
    res.real = this->real * other.real;
    res.imaginary = this->imaginary * other.imaginary;
    return res;
}

const Complex Complex::operator/(const Complex &other) const
{
    Complex res;

    BigInt a = this->real.getNumerator();
    BigInt b = this->imaginary.getDenominator();
    BigInt c = other.real.getNumerator();
    BigInt d = other.imaginary.getDenominator();

    return res;
}

Complex &Complex::operator=(const Complex &other)
{
    if (this == &other) // self, just return your self
        return *this;

    this->real = other.real;
    this->imaginary = other.imaginary;

    return *this;
}

ostream &operator<<(ostream &out, const Complex &other)
{
    out << "(" << other.real << ")";
    if (other.imaginary.isNegative())
        out << " - "
            << "(" << (other.imaginary * Rational(-1, 1)) << ") i";
    else
        out << " + "
            << "(" << other.imaginary << ") i";
    return out;
}
} // namespace ComplexNamespace
