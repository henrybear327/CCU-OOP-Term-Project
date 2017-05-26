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
        cout << RED "Debug level is " << DEBUG << "" RESET << endl;
    }
#endif

    return 0;
}
