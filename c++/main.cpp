#include "geometry.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
    tuple<double, double> vertices[4] = {
        tuple<double, double>(0,0),
        tuple<double, double>(0,1),
        tuple<double, double>(4,1),
        tuple<double, double>(4,0)
    };

    Rectangle r(vertices);

    cout << r.getLength();

    return 0;
}