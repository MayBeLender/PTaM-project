#pragma once
#include <vector>
#include <tuple>
using namespace std;

class Shape {
    public:
        tuple<double, double> center;
        vector<tuple<double, double>> vertices;
        const vector<tuple<double, double>>& getVertices();
        tuple<double, double> getCenter();
        void print();
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(tuple<double, double> pos, double radius, int resolution);
        double getLength();
};

class Rectangle : public Shape {
    public:
        Rectangle(tuple<double, double> in_vertices[4]);
        double getLength();
};

class Square : public Rectangle {
    public:
        Square(tuple<double, double> in_vertices[4]);
        double getLength();
};