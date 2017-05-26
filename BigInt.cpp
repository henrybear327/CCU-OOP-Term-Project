#include "BigInt.h"

namespace BigIntNamespace
{
// constructor
BigInt::BigInt()
{
    // set to 0
    data.push_back(0);
    isNegative = false;
}
BigInt::BigInt(int number)
{
    // get sign
    if (number < 0) {
        isNegative = true;
        number *= -1;
    } else {
        isNegative = false;
    }

    // get number
    while (number > 0) {
        data.push_back(number % 10);
        number /= 10;
    }
}

BigInt::BigInt(string number)
{
    if (number[0] == '-')
        isNegative = true;
    else
        isNegative = false;

    // get number
    for (int i = number.length() - 1; i >= (isNegative ? 1 : 0); i--)
        data.push_back(number[i] - '0');
}

// // operator overloading
// const BigInt operator+(const BigInt &other) const;
// const BigInt operator-(const BigInt &other) const;
// const BigInt operator*(const BigInt &other) const;
// const BigInt operator/(const BigInt &other) const;
// const BigInt operator%(const BigInt &other) const;
//
// bool operator<(const BigInt &other) const;

// // member function
// BigInt factorial() const;

string BigInt::toString() const
{
    string res = "";

    if (isNegative)
        res += '-';
    for (int i = data.size() - 1; i >= 0; i--)
        res += data[i] + '0';

    return res;
}

ostream &operator<<(ostream &out, const BigInt &other)
{
    out << other.toString();
    return out;
}
}
