#include "BigInt.h"
#include "color.h"

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
    do {
        data.push_back(number % 10);
        number /= 10;
    } while (number > 0);
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

// operator overloading
// const BigInt operator+(const BigInt &other) const;
// const BigInt operator-(const BigInt &other) const;
// const BigInt operator*(const BigInt &other) const;
// const BigInt operator/(const BigInt &other) const;
// const BigInt operator%(const BigInt &other) const;

string BigInt::toString(int len) const
{
    /*
    Converts the data vector in to a string with designated length.

    Notice that the sign is **ignored**.

    Leading zeros will be added to the start of the string if the len requested
    is longer than data.size().
    */
    string res = "";

    for (int i = 0; i < len - (int)data.size(); i++)
        res += "0";
    for (int i = data.size() - 1; i >= 0; i--)
        res += data[i] + '0';

#if DEBUG == 2
    cout << YELLOW << res << RESET << endl;
#endif

    return res;
}

bool BigInt::operator<(const BigInt &other) const
{
    int len = max((*this).data.size(), other.data.size());
    string currentBigInt = (*this).toString(len);
    string otherBigInt = other.toString(len);

    if (this->isNegative == other.isNegative) {
        if (this->isNegative == true) { // - vs -
            return otherBigInt < currentBigInt;
        } else { // + vs +
            return currentBigInt < otherBigInt;
        }
    } else {
        if (this->isNegative == true) { // - vs +
            return true;
        } else { // + vs -
            return false;
        }
    }
}

ostream &operator<<(ostream &out, const BigInt &other)
{
    out << other.toString();
    return out;
}

// member function
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
}
