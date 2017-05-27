#include <algorithm>
#include <iostream>
using namespace std;

#include "color.h"

#include "BigInt.h"
using namespace BigIntNamespace;

#include "Rational.h"
using namespace RationalNamespace;

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
    cout << CYAN "Testing BigInt addition" RESET << endl;

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

    cout << endl;
}

void testBigIntSubtraction()
{
    cout << CYAN "Testing BigInt subtraction" RESET << endl;

    {
        BigInt a(123), b(1234567);
        cout << GREEN "123 - 1234567 = -1234444. " << BLUE "Result = " << RESET
             << a - b << endl;
    }

    {
        BigInt a(-123), b(-1234567);
        cout << GREEN "-123 - -1234567 = 1234444. " << BLUE "Result = " << RESET
             << a - b << endl;
    }

    {
        BigInt a(-123), b(1234567);
        cout << GREEN "-123 - 1234567 = -1234690. " << BLUE "Result = " << RESET
             << a - b << endl;
    }

    {
        BigInt a(123), b(-1234567);
        cout << GREEN "123 - -1234567 = 1234690. " << BLUE "Result = " << RESET
             << a - b << endl;
    }

    cout << endl;
}

void testBigIntMultiplication()
{
    cout << CYAN "Testing BigInt multiplication" RESET << endl;

    {
        BigInt a(123), b(1234567);
        cout << GREEN "123 * 1234567 = 151851741. " << BLUE "Result = " << RESET
             << a * b << endl;
    }

    {
        BigInt a(-123), b(-1234567);
        cout << GREEN "-123 * -1234567 = 151851741. " << BLUE "Result = " << RESET
             << a * b << endl;
    }

    {
        BigInt a(-123), b(1234567);
        cout << GREEN "-123 * 1234567 = -151851741. " << BLUE "Result = " << RESET
             << a * b << endl;
    }

    {
        BigInt a(123), b(-1234567);
        cout << GREEN "123 * -1234567 = -151851741. " << BLUE "Result = " << RESET
             << a * b << endl;
    }

    {
        BigInt a(0), b(-1234567);
        cout << GREEN "0 * -1234567 = 0. " << BLUE "Result = " << RESET << a * b
             << endl;
    }

    cout << endl;
}

void testBigIntDivision()
{
    cout << CYAN "Testing BigInt division" RESET << endl;

    {
        BigInt a(123), b(1234567);
        cout << GREEN "1234567 / 123 = 10037. " << BLUE "Result = " << RESET
             << b / a << endl;
    }

    {
        BigInt a(-123), b(-1234567);
        cout << GREEN "-1234567 / -123 = 10037. " << BLUE "Result = " << RESET
             << b / a << endl;
    }

    {
        BigInt a(-123), b(1234567);
        cout << GREEN "1234567 / -123 = -10037. " << BLUE "Result = " << RESET
             << b / a << endl;
    }

    {
        BigInt a(123), b(-1234567);
        cout << GREEN "-1234567 / 123 = -10037. " << BLUE "Result = " << RESET
             << b / a << endl;
    }

    {
        BigInt a(1234567), b(0);
        cout << GREEN "0 / 1234567 = 0. " << BLUE "Result = " << RESET << b / a
             << endl;
    }

    cout << endl;
}

void testBigIntMod()
{
    cout << CYAN "Testing BigInt mod" RESET << endl;

    {
        BigInt a(5), b(3);
        cout << GREEN "5 % 3 = 2. " << BLUE "Result = " << RESET << a % b << endl;
    }

    {
        BigInt a(-5), b(-3);
        cout << GREEN "-5 % -3 = -2. " << BLUE "Result = " << RESET << a % b
             << endl;
    }

    {
        BigInt a(-5), b(3);
        cout << GREEN "-5 % 3 = -2. " << BLUE "Result = " << RESET << a % b << endl;
    }

    {
        BigInt a(5), b(-3);
        cout << GREEN "5 % -3 = 2. " << BLUE "Result = " << RESET << a % b << endl;
    }

    {
        BigInt a(0), b(5);
        cout << GREEN "0 % 5 = 0. " << BLUE "Result = " << RESET << b / a << endl;
    }

    cout << endl;
}

const int range = 1000;
void autoTestBigIntAddition()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d + %7d\n", i, j);

            string myStr = (BigInt(i) + BigInt(j)).toString();
            string answerStr = to_string(i + j);

            if (myStr != answerStr) {
                cout << RED << i << " + " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntSubtraction()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d - %7d\n", i, j);

            string myStr = (BigInt(i) - BigInt(j)).toString();
            string answerStr = to_string(i - j);

            if (myStr != answerStr) {
                cout << RED << i << " - " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntMultiplication()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d * %7d\n", i, j);

            string myStr = (BigInt(i) * BigInt(j)).toString();
            string answerStr = to_string(i * j);

            if (myStr != answerStr) {
                cout << RED << i << " * " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntDivision()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (j == 0)
                continue;

            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d / %7d\n", i, j);

            string myStr = (BigInt(i) / BigInt(j)).toString();
            string answerStr = to_string(i / j);

            if (myStr != answerStr) {
                cout << RED << i << " / " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntMod()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (j == 0)
                continue;

            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d %% %7d\n", i, j);

            string myStr = (BigInt(i) % BigInt(j)).toString();
            string answerStr = to_string(i % j);

            if (myStr != answerStr) {
                cout << RED << i << " % " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

long long fac(int num)
{
    long long res = 1;
    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

void autoTestBigIntFactorial()
{
    for (int i = 0; i < 20; i++) {
        BigInt num(i);

        string myStr = num.factorial().toString();
        string answerStr = to_string(fac(i));

        cout << GREEN << i << "!"
             << " = " << answerStr << RESET << endl;
        if (myStr != answerStr) {
            cout << RED << i << "!"
                 << " = " << answerStr << " != " << myStr << RESET << endl;
            exit(0);
        }
    }
}

void autoTestBigIntAdditionString()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d + %7d\n", i, j);

            string myStr = (BigInt(to_string(i)) + BigInt(to_string(j))).toString();
            string answerStr = to_string(i + j);

            if (myStr != answerStr) {
                cout << RED << i << " + " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntSubtractionString()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d - %7d\n", i, j);

            string myStr = (BigInt(to_string(i)) - BigInt(to_string(j))).toString();
            string answerStr = to_string(i - j);

            if (myStr != answerStr) {
                cout << RED << i << " - " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntMultiplicationString()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d * %7d\n", i, j);

            string myStr = (BigInt(to_string(i)) * BigInt(to_string(j))).toString();
            string answerStr = to_string(i * j);

            if (myStr != answerStr) {
                cout << RED << i << " * " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntDivisionString()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (j == 0)
                continue;

            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d / %7d\n", i, j);

            string myStr = (BigInt(to_string(i)) / BigInt(to_string(j))).toString();
            string answerStr = to_string(i / j);

            if (myStr != answerStr) {
                cout << RED << i << " / " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void autoTestBigIntModString()
{
    for (int i = -range; i <= range; i++)
        for (int j = -range; j <= range; j++) {
            if (j == 0)
                continue;

            if (abs(j) % 1000 == 0)
                // cout << GREEN << (i < 0 ? "-" : " ") << abs(i) << " + " << (j < 0 ?
                // "-" : " ") << abs(j) << endl;
                printf(GREEN "%7d %% %7d\n", i, j);

            string myStr = (BigInt(to_string(i)) % BigInt(to_string(j))).toString();
            string answerStr = to_string(i % j);

            if (myStr != answerStr) {
                cout << RED << i << " % " << j << " = " << answerStr << " != " << myStr
                     << RESET << endl;
                exit(0);
            }
        }
}

void testRationalConstructor()
{
        cout << CYAN "Testing Rational constructors" RESET << endl;

        {
            Rational a;
            cout << GREEN "The result should be 0 / 1. " << BLUE "Result = " << a << RESET
                 << endl;
        }

        {
            Rational a(2, 8);
            cout << GREEN "The result should be 1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            Rational a(-2, 8);
            cout << GREEN "The result should be -1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            Rational a(2, -8);
            cout << GREEN "The result should be -1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            Rational a(-2, -8);
            cout << GREEN "The result should be 1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            BigInt b(2), c(8);
            Rational a(b, c);
            cout << GREEN "The result should be 1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            BigInt b(-2), c(8);
            Rational a(b, c);
            cout << GREEN "The result should be -1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            BigInt b(2), c(-8);
            Rational a(b, c);
            cout << GREEN "The result should be -1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        {
            BigInt b(-2), c(-8);
            Rational a(b, c);
            cout << GREEN "The result should be 1 / 4. " << BLUE "Result = " << a
                 << RESET << endl;
        }

        cout << endl;
}

void testRationalAddition()
{
    cout << CYAN "Testing Rational addition" RESET << endl;

    {
        Rational a(2, 8), b(12, 16);
        cout << GREEN "The result should be 1 / 1. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        Rational a(2, 8), b(-12, 16);
        cout << GREEN "The result should be -1 / 2. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(12, 16);
        cout << GREEN "The result should be 1 / 2. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(-12, 16);
        cout << GREEN "The result should be -1 / 1. " << BLUE "Result = " << a + b
             << RESET << endl;
    }

    cout << endl;
}

void testRationalSubtraction()
{
    cout << CYAN "Testing Rational subtraction" RESET << endl;

    {
        Rational a(2, 8), b(12, 16);
        cout << GREEN "The result should be -1 / 2. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        Rational a(2, 8), b(-12, 16);
        cout << GREEN "The result should be 1 / 1. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(12, 16);
        cout << GREEN "The result should be -1 / 1. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(-12, 16);
        cout << GREEN "The result should be 1 / 2. " << BLUE "Result = " << a - b
             << RESET << endl;
    }

    cout << endl;
}

void testRationalMultiplication()
{
    cout << CYAN "Testing Rational multiplication" RESET << endl;

    {
        Rational a(2, 8), b(12, 16);
        cout << GREEN "The result should be 3 / 16. " << BLUE "Result = " << a * b
             << RESET << endl;
    }

    {
        Rational a(2, 8), b(-12, 16);
        cout << GREEN "The result should be -3 / 16. " << BLUE "Result = " << a * b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(12, 16);
        cout << GREEN "The result should be -3 / 16. " << BLUE "Result = " << a * b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(-12, 16);
        cout << GREEN "The result should be 3 / 16. " << BLUE "Result = " << a * b
             << RESET << endl;
    }

    cout << endl;
}

void testRationalDivision()
{
    cout << CYAN "Testing Rational division" RESET << endl;

    {
        Rational a(2, 8), b(12, 8);
        cout << GREEN "The result should be 1 / 6. " << BLUE "Result = " << a / b
             << RESET << endl;
    }

    {
        Rational a(2, 8), b(-12, 8);
        cout << GREEN "The result should be -1 / 6. " << BLUE "Result = " << a / b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(12, 8);
        cout << GREEN "The result should be -1 / 6. " << BLUE "Result = " << a / b
             << RESET << endl;
    }

    {
        Rational a(-2, 8), b(-12, 8);
        cout << GREEN "The result should be 1 / 6. " << BLUE "Result = " << a / b
             << RESET << endl;
    }

    cout << endl;
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

    // testBigIntConstructors();
    // testBigIntComparators();
    // testBigIntAddition();
    // testBigIntSubtraction();
    // testBigIntMultiplication();
    // testBigIntDivision();
    // testBigIntMod();
    //
    // autoTestBigIntAddition();
    // autoTestBigIntSubtraction();
    // autoTestBigIntMultiplication();
    // autoTestBigIntDivision();
    // autoTestBigIntMod();
    // autoTestBigIntFactorial();
    //
    // autoTestBigIntAdditionString();
    // autoTestBigIntSubtractionString();
    // autoTestBigIntMultiplicationString();
    // autoTestBigIntDivisionString();
    // autoTestBigIntModString();

    testRationalConstructor();
    testRationalAddition();
    testRationalSubtraction();
    testRationalMultiplication();
    testRationalDivision();

    return 0;
}
