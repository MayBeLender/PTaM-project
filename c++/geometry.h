#pragma once
#include <vector>
#include <tuple>
using namespace std;

class Shape {
    protected:
        tuple<double, double>* centerPtr;
        vector<tuple<double, double>> vertices;
    public:
        virtual double getLength() = 0;
        virtual double getArea() = 0;
        const vector<tuple<double, double>>& getVertices();
        tuple<double, double> getCenter();
        void print();
        ~Shape();
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(tuple<double, double> pos, double radius, int resolution);
        double getLength() override;
        double getArea() override;
};

class Rectangle : public Shape {
    public:
        Rectangle(tuple<double, double> in_vertices[4]);
        double getLength() override;
        double getArea() override;
};

class Square : public Rectangle {
    public:
        Square(tuple<double, double> in_vertices[4]);
        double getLength() override;
};