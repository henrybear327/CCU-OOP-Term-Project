#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace BigInt
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

    bool operator<(const BigInt &other) const;

    friend ostream &operator<<(ostream &out,
                               const BigInt &other); // must be friend

    // member function
    BigInt factorial() const;

private:
    bool isNegative;
    vector<int> data;
};
}
#endif
