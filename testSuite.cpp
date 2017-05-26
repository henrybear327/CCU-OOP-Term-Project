#include <iostream>
using namespace std;

#include "color.h"

#include "BigInt.h"
using namespace BigIntNamespace;

int main()
{
    cout << "Project 5" << endl;
#ifdef DEBUG
    if (DEBUG > 0) {
        cout << RED "Debug mode is enabled" RESET << endl;
        cout << RED "Debug level is " << DEBUG << "" RESET << endl << endl;
    }
#endif

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

    return 0;
}
