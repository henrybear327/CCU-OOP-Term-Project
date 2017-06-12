#include <bits/stdc++.h>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(int num);
    BigInt(const BigInt &other);

    ~BigInt();

    BigInt &operator=(const BigInt &other);

private:
    int data;
};

BigInt::BigInt()
{
    cout << "BigInt()" << endl;
    data = 0;
}

BigInt::BigInt(int num)
{
    cout << "BigInt(int num)" << endl;
    data = num;
}

BigInt::BigInt(const BigInt &other)
{
    cout << "BigInt(const BigInt& other)" << endl;
    data = other.data;
}

BigInt &BigInt::operator=(const BigInt &other)
{
    if (this == &other) {
        cout << "Same object" << endl;
        return *this;
    }
    cout << "BigInt(const BigInt& other)" << endl;
    data = other.data;

    return *this;
}

BigInt::~BigInt()
{
    cout << "delete " << data << endl;
}

BigInt foo()
{
    BigInt res = BigInt(100);

    return res;
}

void bar()
{
    cout << "I am something else" << endl;
}

BigInt &solve()
{
    return;
}

int main()
{
    // BigInt a = BigInt(10);
    //
    // BigInt b;

    // b = a;

    BigInt c = foo();
    bar();

    return 0;
}
