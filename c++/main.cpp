#include "geometry.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
    tuple<double, double> vertices[4] = {
        tuple<double, double>(0,0),
        tuple<double, double>(0,2),
        tuple<double, double>(2,2),
        tuple<double, double>(2,0)
    };

    Square s(vertices);

    cout << s.getArea();

    return 0;
}