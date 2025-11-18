#include "bitString.h"
#include <iostream>
using namespace std;

int main()
{
    BitString a, b, result;

    a.input();

    b.input();

    result = a.conjaction(b);

    result.print();

    return 0;
}