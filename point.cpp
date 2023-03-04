#include "point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() {
    cout << "Default constructor called." << endl;
    x = 0;
    y = 0;
}

Point::Point(int x_, int y_) {
    cout << "Initialization constructor called." << endl;
    x = x_;
    y = y_;
}

void Point::set(int x_, int y_) {
    x = x_;
    y = y_;
}

int Point::getx() {
    return x;
}

int Point::gety() {
    return y;
}

Point Point::operator+(Point p) {
    Point tmp;
    tmp.x = x + p.x;
    tmp.y = y + p.y;
    return tmp;
}

Point Point::operator-(Point p) {
    Point tmp;
    tmp.x = x - p.x;
    tmp.y = y - p.y;
    return tmp;
}

Point Point::operator*(int c) {
    Point tmp;
    tmp.x = x * c;
    tmp.y = y * c;
    return tmp;
}

float Point::distance(Point p) {
    float dist = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    return dist;
}
