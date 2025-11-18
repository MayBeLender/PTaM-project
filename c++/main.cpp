#include "bitString.h"
#include <iostream>
using namespace std;

int main()
{
    BitString a, b, result;

    try {
        a.input();

        b.input();

        result = a & b;
    } catch (const exception& e) {
        cout << e.what();
        exit(EXIT_FAILURE);
    }

    result.print();

    return 0;
}