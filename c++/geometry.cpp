#define _USE_MATH_DEFINES
#include "geometry.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
using namespace std;

//Shape
const vector<tuple<double, double>>& Shape::getVertices() {
    return vertices;
}

tuple<double, double> Shape::getCenter() {
    return center;
}

void Shape::print() {
    for (auto vertex : vertices) {
        printf("X: %g | Y: %g\n", get<0>(vertex), get<1>(vertex));
    }
}

//Circle
Circle::Circle(tuple<double, double> pos, double radius, int resolution) {
    center = pos;
    this->radius = radius;

    for (int i = 0; i < resolution; i++) {
        double angle = (double)i / resolution * 2 * M_PI;

        tuple<double, double> vertex(
            get<0>(pos) + radius * cos(angle),
            get<1>(pos) + radius * sin(angle));

        vertices.push_back(vertex);
    }
}

double Circle::getLength() {
    return 2 * M_PI * radius;
}

//Square
Square::Square(tuple<double, double> in_vertices[4]) : Rectangle(in_vertices) {}

double Square::getLength() {
    return sqrt(pow(get<0>(vertices[0]),2) + pow(get<1>(vertices[0]),2)) * 4;
}

//Rectangle
Rectangle::Rectangle(tuple<double, double> in_vertices[4]) {
    double x = 0, y = 0;

    for (int i = 0; i < 4; i++) {
        vertices.push_back(in_vertices[i]);

        x += get<0>(in_vertices[i]);
        y += get<1>(in_vertices[i]);
    }

    center = tuple<double, double> (x/4, y/4);
}

double Rectangle::getLength() {
    double length = 0;

    for (int i = 0; i < 2; i++) {
        double x = 0, y = 0;

        x = get<0>(vertices[i + 1]) - get<0>(vertices[i]);
        y = get<1>(vertices[i + 1]) - get<1>(vertices[i]);

        length += sqrt(pow(x,2) + pow(y,2));
    }

    return length * 2;
}
