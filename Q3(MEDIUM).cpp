// 	Function Overloading for Calculating Area.
// Objective

// Write a program to calculate the area of different shapes using function overloading. Implement overloaded functions to compute the area of a circle, a rectangle, and a triangle.  

// Input Format 
// The program should accept:  
// 1. Radius of the circle for the first function.  
// 2. Length and breadth of the rectangle for the second function.  
// 3. Base and height of the triangle for the third function.  
#include <iostream>
#include <iomanip>
using namespace std;

double area(double radius) {
    return 3.14159 * radius * radius;
}

int area(int length, int breadth) {
    return length * breadth;
}

double area(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    double radius;
    int length, breadth;
    double base, height;

    cin >> radius;
    cin >> length >> breadth;
    cin >> base >> height;
    cout << fixed << setprecision(5) << area(radius) << endl;
    cout << area(length, breadth) << endl;
    cout << fixed << setprecision(1) << area(base, height) << endl;

    return 0;
}
