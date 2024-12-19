// Implementing Polymorphism for Shape Hierarchies.

// Objective
// Write a program to demonstrate runtime polymorphism in C++ using a base class Shape and derived classes Circle, Rectangle, and Triangle. The program should use virtual functions to calculate and print the area of each shape based on user input.

// Input Format
// The program should accept:
// 1.	Radius of the circle for the first derived class.
// 2.	Length and breadth of the rectangle for the second derived class.
// 3.	Base and height of the triangle for the third derived class.
#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r) : radius(r) {}
    void calculateArea() override {
        double area = 3.14159 * radius * radius;
        cout << "Area of Circle: " << fixed << setprecision(5) << area << endl;
    }
};

class Rectangle : public Shape {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {}
    void calculateArea() override {
        int area = length * breadth;
        cout << "Area of Rectangle: " << area << endl;
    }
};

class Triangle : public Shape {
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}
    void calculateArea() override {
        double area = 0.5 * base * height;
        cout << "Area of Triangle: " << fixed << setprecision(1) << area << endl;
    }
};

int main() {
    double radius;
    cin >> radius;

    int length, breadth;
    cin >> length >> breadth;
    double base, height;
    Shape* circle = new Circle(radius);
    Shape* rectangle = new Rectangle(length, breadth);
    Shape* triangle = new Triangle(base, height);

    circle->calculateArea();
    rectangle->calculateArea();
    triangle->calculateArea();

    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}
