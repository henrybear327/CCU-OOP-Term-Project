#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


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
        friend BigInt operator+(const BigInt &a, const BigInt &b);
        friend BigInt operator-(const BigInt &a, const BigInt &b);
        friend BigInt operator*(const BigInt &a, const BigInt &b);
        friend BigInt operator/(const BigInt &a, const BigInt &b);
        friend BigInt operator%(const BigInt &a, const BigInt &b);
        BigInt& operator =(const BigInt& rightSide);//overload assignment
        const BigInt operator-() const;

        bool operator<(const BigInt &rightSide) const;
        bool operator<=(const BigInt &rightSide) const;
        bool operator==(const BigInt &rightSide) const;

        friend ostream &operator<<(ostream &out, const BigInt &a);

        // member function
        BigInt factorial() const;
        string toString() const;

    private:
        BigInt(vector<int> &data, bool isNegative);

        bool isNegative;
        vector<int> data;

        friend bool unsignedCmpLessThan(const BigInt &a, const BigInt &b);
        friend bool unsignedCmpLessThanOrEqualTo(const BigInt &a, const BigInt &b);
    };

    const BigInt gcd(const BigInt &a, const BigInt &b);
    int gcd(const int a, const int b);

} // namespace BigIntNamespace
#endif
