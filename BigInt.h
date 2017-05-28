#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "color.h"

namespace BigIntNamespace
{
class BigInt
{
public:
    // constructor
    BigInt();
    BigInt(int number);
    BigInt(string number);

    // operator overloading
    const BigInt operator+(const BigInt &other) const;
    const BigInt operator-(const BigInt &other) const;
    const BigInt operator*(const BigInt &other) const;
    const BigInt operator/(const BigInt &other) const;
    const BigInt operator%(const BigInt &other) const;
    const BigInt operator-() const;

    // const BigInt operator=(const BigInt &other) const; // wrong
    BigInt &operator=(const BigInt &other);

    bool operator<(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;
    bool operator==(const BigInt &other) const;

    friend ostream &operator<<(ostream &out, const BigInt &other);

    // member function
    BigInt factorial() const;
    string toString() const;

private:
    BigInt(vector<int> &data, bool isNegative);

    bool isNegative;
    vector<int> data;

    // const BigInt negate() const;
    string toString(int len) const;
};

const BigInt gcd(const BigInt &a, const BigInt &b);
int gcd(const int a, const int b);

} // namespace BigIntNamespace
#endif
