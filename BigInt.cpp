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

    data.reserve(number.length() - (isNegative ? 1 : 0));
    // get number
    for (int i = number.length() - 1; i >= (isNegative ? 1 : 0); i--)
        data.push_back(number[i] - '0');
}

BigInt::BigInt(vector<int> &newData, bool newIsNegative)
{
    this->data = newData;
    // trim leading zero
    for (int i = (int)this->data.size() - 1; i >= 0; i--) {
        if (data[i] == 0)
            data.pop_back();
        else
            break;
    }

    if (data.size() == 0) {
        data.push_back(0);
        this->isNegative = false;
    } else {
        this->isNegative = newIsNegative;
    }
}

BigInt &BigInt::operator=(const BigInt &other)
{
    if (this == &other) // self, just return your self
        return *this;

    this->isNegative = other.isNegative;
    this->data = other.data;

    return *this;
}

// const BigInt BigInt::negate() const // replaced with overloading -
// {
//     BigInt res = *this;
//     res.isNegative = !isNegative;
//
//     return res;
// }

// operator overloading
const BigInt BigInt::operator+(const BigInt &other) const
{
    if (this->isNegative == other.isNegative) {
        vector<int> res;
        int mx = max(this->data.size(), other.data.size());
        res.reserve(mx + 1);

        int carry = 0;
        for (int i = 0; i < mx; i++) {
            int sum = 0;
            if (i < (int)this->data.size())
                sum += this->data[i];
            if (i < (int)other.data.size())
                sum += other.data[i];

            sum += carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry)
            res.push_back(carry);

        return BigInt(res, this->isNegative);
    } else {
        if (this->isNegative) { // -5 + 3
            return other - -(*this);
        } else { // 3 + -5
            return (*this) - -other;
        }
    }
}

const BigInt BigInt::operator-(const BigInt &other) const
{
    if (this->isNegative == other.isNegative) {
        if (this->isNegative) { // -3 - -5 = -3 + 5
            return *this + -other;
        }

        int len = max(this->data.size(), other.data.size());
        if (*this < other)
            return -(other - *this);

        vector<int> res;
        res.reserve(len + 1);

        int borrow = 0;
        for (int i = 0; i < len; i++) {
            int diff = this->data[i] + borrow;
            if (i < (int)other.data.size())
                diff -= other.data[i];
            if (diff < 0) {
                borrow = -1;
                diff += 10;
            } else
                borrow = 0;

            res.push_back(diff);
        }
#if DEBUG > 0
        assert(borrow == 0);
#endif
        return BigInt(res, false);
    } else {
        if (this->isNegative) { // -3 - 5
            return -(-(*this) + other);
        } else { // 3 - -5
            return (*this + -other);
        }
    }
}

const BigInt BigInt::operator*(const BigInt &other) const
{
    int sign = (this->isNegative == other.isNegative) ? false : true;

    int mx = 2 * max(this->data.size(), other.data.size());
    vector<int> res(mx, 0);
    for (int i = 0; i < (int)this->data.size(); i++)
        for (int j = 0; j < (int)other.data.size(); j++)
            res[i + j] += this->data[i] * other.data[j];

    for (int i = 0; i < mx - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
#if DEBUG > 0
    assert(res[mx - 1] < 10);
#endif

    return BigInt(res, sign);
}

const BigInt BigInt::operator/(const BigInt &other) const
{
    int sign = (this->isNegative == other.isNegative) ? false : true;
    vector<int> res;
    res.reserve(this->data.size());

    // be aware about the negative BigInt screwing up the calculation later on
    BigInt otherPos = other;
    otherPos.isNegative = false;

    BigInt tmp(0);
    for (int i = this->data.size() - 1; i >= 0; i--) {
        tmp = tmp * BigInt(10) + BigInt(this->data[i]);

        for (int j = 1; j <= 10; j++) {
            BigInt scale = otherPos * BigInt(j);

            if (scale <= tmp)
                continue;
            else {
                res.push_back(j - 1);
                tmp = tmp - otherPos * BigInt(j - 1);
                break;
            }
        }
    }

    reverse(res.begin(), res.end());
    return BigInt(res, sign);
}

const BigInt BigInt::operator%(const BigInt &other) const
{
    return *this - (*this / other) * other;
}

const BigInt BigInt::operator-() const // negation
{
    BigInt res = *this;
    res.isNegative = !isNegative;

    return res;
}

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

bool BigInt::operator<=(const BigInt &other) const
{
    int len = max((*this).data.size(), other.data.size());
    string currentBigInt = (*this).toString(len);
    string otherBigInt = other.toString(len);

    if (this->isNegative == other.isNegative) {
        if (this->isNegative == true) { // - vs -
            return otherBigInt <= currentBigInt;
        } else { // + vs +
            return currentBigInt <= otherBigInt;
        }
    } else {
        if (this->isNegative == true) { // - vs +
            return true;
        } else { // + vs -
            return false;
        }
    }
}

bool BigInt::operator==(const BigInt &other) const
{
    if (this->isNegative != other.isNegative)
        return false;

    if (this->data.size() != other.data.size())
        return false;

    for (int i = 0; i < (int)this->data.size(); i++)
        if (this->data[i] != other.data[i])
            return false;

    return true;
}

ostream &operator<<(ostream &out, const BigInt &other)
{
    out << other.toString();
    return out;
}

// member function
BigInt BigInt::factorial() const
{
    BigInt res(1);
    for (BigInt i(1); i <= *this; i = i + BigInt(1)) {
        res = res * i;
    }
    return res;
}

string BigInt::toString() const
{
    string res = "";

    if (isNegative)
        res += '-';
    for (int i = data.size() - 1; i >= 0; i--)
        res += data[i] + '0';

    return res;
}

const BigInt gcd(const BigInt &a, const BigInt &b)
{
    return a == BigInt(0) ? b : gcd(b % a, a);
}

int gcd(const int a, const int b)
{
    return a == 0 ? b : gcd(b % a, a);
}
} // namespace BigIntNamespace
