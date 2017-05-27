#include "BigInt.h"
#include "color.h"

namespace BigIntNamespace
{
// constructor
BigInt::BigInt()
{
    // set to 0
    sz = 1;
    data = new int[sz];
    data[0] = 0;
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

    sz = 0;
    int tmp = number;
    // get number
    do {
        tmp /= 10;
        sz++;
    } while (tmp > 0);

    data = new int[sz];
    int idx = 0;
    do {
        data[idx++] = number % 10;
        number /= 10;
    } while (number > 0);
}

BigInt::BigInt(string number)
{
    if (number[0] == '-')
        isNegative = true;
    else
        isNegative = false;

    sz = number.length() - (isNegative ? 1 : 0);
    data = new int[sz];

    // get number
    int idx = 0;
    for (int i = number.length() - 1; i >= (isNegative ? 1 : 0); i--)
        data[idx++] = number[i] - '0';
}

BigInt::~BigInt()
{
    // cout << "Free " << *this << " " << this << " " << data <<  endl;
    // cout.flush();
    delete[] data;
}

BigInt::BigInt(int *newData, int newSz, bool newIsNegative)
{
    // trim leading zero
    int ok = -1;
    for (int i = newSz - 1; i >= 0; i--) {
        if (newData[i] == 0)
            continue;
        else {
            ok = i;
            break;
        }
    }

    sz = ok + 1;
    if (sz == 0) {
        sz = 1;
        data = new int[sz];
        data[0] = 0;
        this->isNegative = false;
    } else {
        data = new int[sz];
        for (int i = 0; i < sz; i++)
            data[i] = newData[i];
        this->isNegative = newIsNegative;
    }
}

BigInt &BigInt::operator=(const BigInt &other)
{
    if (this == &other) // self, just return your self
        return *this;

    this->isNegative = other.isNegative;
    delete[] this->data;
    this->sz = other.sz;
    this->data = new int[this->sz];
    for (int i = 0; i < this->sz; i++)
        this->data[i] = other.data[i];

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
        int mx = max(this->sz, other.sz);
        int res[mx + 1];
        for (int i = 0; i < mx + 1; i++)
            res[i] = 0;

        int carry = 0;
        for (int i = 0; i < mx; i++) {
            int sum = 0;
            if (i < this->sz)
                sum += this->data[i];
            if (i < other.sz)
                sum += other.data[i];

            sum += carry;
            res[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry)
            res[mx] = carry;

        return BigInt(res, mx + 1, this->isNegative);
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

        int len = max(this->sz, other.sz);
        if (*this < other)
            return -(other - *this);

        int res[len + 1];
        for (int i = 0; i < len + 1; i++)
            res[i] = 0;

        int borrow = 0;
        for (int i = 0; i < len; i++) {
            int diff = this->data[i] + borrow;
            if (i < other.sz)
                diff -= other.data[i];
            if (diff < 0) {
                borrow = -1;
                diff += 10;
            } else
                borrow = 0;

            res[i] = diff;
        }
#if DEBUG > 0
        assert(borrow == 0);
#endif
        return BigInt(res, len + 1, false);
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

    int mx = 2 * max(this->sz, other.sz);
    int res[mx];
    for (int i = 0; i < mx; i++)
        res[i] = 0;

    for (int i = 0; i < (int)this->sz; i++)
        for (int j = 0; j < (int)other.sz; j++)
            res[i + j] += this->data[i] * other.data[j];

    for (int i = 0; i < mx - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
#if DEBUG > 0
    assert(res[mx - 1] < 10);
#endif

    return BigInt(res, mx, sign);
}

const BigInt BigInt::operator/(const BigInt &other) const
{
    int sign = (this->isNegative == other.isNegative) ? false : true;
    int res[this->sz];
    for (int i = 0; i < this->sz; i++)
        res[i] = 0;

    // be aware about the negative BigInt screwing up the calculation later on
    BigInt otherPos;
    otherPos = other; // WTF??!!
    otherPos.isNegative = false;

    BigInt tmp(0);
    for (int i = this->sz - 1; i >= 0; i--) {
        tmp = tmp * BigInt(10) + BigInt(this->data[i]);

        for (int j = 1; j <= 10; j++) {
            BigInt scale = otherPos * BigInt(j);
            // cout << i << " " << j << " " << scale << " " << tmp << endl;

            if (scale <= tmp)
                continue;
            else {
                // cout << "j = " << j - 1 << endl;
                res[i] = (j - 1);
                // cout << tmp << " " << otherPos * BigInt(j - 1) << endl;
                tmp = tmp - otherPos * BigInt(j - 1);
                // cout << tmp << endl;
                break;
            }
        }
    }

    return BigInt(res, this->sz, sign);
}

const BigInt BigInt::operator%(const BigInt &other) const
{
    return *this - (*this / other) * other;
}

const BigInt BigInt::operator-() const // negation
{
    BigInt res;
    res = *this;
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

    for (int i = 0; i < len - sz; i++)
        res += "0";
    for (int i = sz - 1; i >= 0; i--)
        res += data[i] + '0';

#if DEBUG == 2
    cout << YELLOW << res << RESET << endl;
#endif

    return res;
}

bool BigInt::operator<(const BigInt &other) const
{
    int len = max((*this).sz, other.sz);
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
    int len = max((*this).sz, other.sz);
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

    if (this->sz != other.sz)
        return false;

    for (int i = 0; i < (int)this->sz; i++)
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
    for (int i = sz - 1; i >= 0; i--)
        res += data[i] + '0';

    return res;
}

const BigInt gcd(const BigInt a, const BigInt b)
{
    return a == BigInt(0) ? b : gcd(b % a, a);
}

int gcd(const int a, const int b)
{
    return a == 0 ? b : gcd(b % a, a);
}
} // namespace BigIntNamespace
