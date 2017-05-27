#include <iostream>
using namespace std;

#include "color.h"

#include "BigInt.h"
using namespace BigIntNamespace;

inline string printTF(bool res)
{
    return res ? "true" : "false";
}

void testBigIntConstructors()
{
    cout << CYAN "Testing BigInt constructors" RESET << endl;

    {
        BigInt a;
        cout << GREEN "The result should be 0. " << BLUE "Result = " << a << RESET
             << endl;
    }

    {
        BigInt bp(12345), bn(-12345);
        cout << GREEN "The result should be 12345. " << BLUE "Result = " << bp
             << RESET << endl;
        cout << GREEN "The result should be -12345. " << BLUE "Result = " << bn
             << RESET << endl;
    }

    {
        BigInt bp("12345"), bn("-12345");
        cout << GREEN "The result should be 12345. " << BLUE "Result = " << bp
             << RESET << endl;
        cout << GREEN "The result should be -12345. " << BLUE "Result = " << bn
             << RESET << endl;
    }

    {
        BigInt bp(0);
        cout << GREEN "The result should be 0. " << BLUE "Result = " << bp << RESET
             << endl;
    }

    {
        BigInt bp("0");
        cout << GREEN "The result should be 0. " << BLUE "Result = " << bp << RESET
             << endl;
    }

    cout << endl;
}

void testBigIntComparators()
{
    cout << CYAN "Testing BigInt < comparator" RESET << endl;

    {
        BigInt a(0), b(100);
        cout << GREEN "The result should be true (0 < 100). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(0), b(-100);
        cout << GREEN "The result should be false (0 < -100). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(0), b(0);
        cout << GREEN "The result should be false (0 < 0). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(-10000), b(100);
        cout << GREEN "The result should be true (-10000 < 100). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(100), b(-10000);
        cout << GREEN "The result should be false (100 < -10000). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(100), b(20000);
        cout << GREEN "The result should be true (100 < 20000). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(200), b(10000);
        cout << GREEN "The result should be false (200 < 10000). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(-100), b(-2000);
        cout << GREEN "The result should be false (-100 < -2000). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    {
        BigInt a(-200), b(-100);
        cout << GREEN "The result should be true (-200 < -100). "
             << BLUE "Result = " << printTF((a < b)) << RESET << endl;
    }

    cout << endl;
}

void testBigIntAddition()
{
    {
        BigInt a(123), b(1234567);
        cout << GREEN "123 + 1234567 = 1234690. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        BigInt a(-123), b(-1234567);
        cout << GREEN "-123 + -1234567 = -1234690. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        BigInt a(-123), b(1234567);
        cout << GREEN "-123 + 1234567 = 1234444. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        BigInt a(123), b(-1234567);
        cout << GREEN "123 + -1234567 = -1234444. " << BLUE "Result = " << a + b
             << RESET << endl;
    }
}

void testBigIntSubtraction()
{
    {
        BigInt a(123), b(1234567);
        cout << GREEN "123 - 1234567 = -1234444. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        BigInt a(-123), b(-1234567);
        cout << GREEN "-123 - -1234567 = 1234444. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        BigInt a(-123), b(1234567);
        cout << GREEN "-123 - 1234567 = -1234690. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        BigInt a(123), b(-1234567);
        cout << GREEN "123 - -1234567 = 1234690. " << BLUE "Result = " << a - b
             << RESET << endl;
    }
}

int main()
{
    cout << "Project 5" << endl;
#ifdef DEBUG
    if (DEBUG > 0) {
        cout << RED "Debug mode is enabled" RESET << endl;
        cout << RED "Debug level is " << DEBUG << "" RESET << endl << endl;
    }
#endif

    testBigIntConstructors();
    testBigIntComparators();
    testBigIntAddition();
    testBigIntSubtraction();

    return 0;
}
