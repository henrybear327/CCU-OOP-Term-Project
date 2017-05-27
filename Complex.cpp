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
    Rational a = this->real;
    Rational b = this->imaginary;
    Rational c = other.real;
    Rational d = other.imaginary;

    Rational realPart(a * c + b * d);
    // cout << "Done with realPart" << endl;

    Rational imaginaryPart(b * c - a * d);
    // cout << "Done with imaginaryPart" << endl;

    Rational down(c * c + d * d);
    // cout << "Done with down" << endl;

    return Complex(realPart / down, imaginaryPart / down);
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
