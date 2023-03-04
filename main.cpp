#include <iostream>
#include "point.h"
#include "matrix.h"


using namespace std;

int main()
{
    Point p1;
    Point p2(3, 4);

    p1.set(1, 2);

    cout << "p1: (" << p1.getx() << ", " << p1.gety() << ")" << endl;
    cout << "p2: (" << p2.getx() << ", " << p2.gety() << ")" << endl;

    Point p3 = p1 + p2;
    Point p4 = p1 - p2;
    Point p5 = p2 * 2;

    cout << "p3: (" << p3.getx() << ", " << p3.gety() << ")" << endl;
    cout << "p4: (" << p4.getx() << ", " << p4.gety() << ")" << endl;
    cout << "p5: (" << p5.getx() << ", " << p5.gety() << ")" << endl;

    float dist = p1.distance(p2);
    cout << "Distance between p1 and p2: " << dist << endl;

    Matrix mat1(2, 3);
    Matrix mat2(3, 2);

    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[0][2] = 3;
    mat1[1][0] = 4;
    mat1[1][1] = 5;
    mat1[1][2] = 6;

    mat2[0][0] = 7;
    mat2[0][1] = 8;
    mat2[1][0] = 9;
    mat2[1][1] = 10;
    mat2[2][0] = 11;
    mat2[2][1] = 12;

    std::cout << "Matrix 1:\n" << mat1 << std::endl;
    std::cout << "Matrix 2:\n" << mat2 << std::endl;

    Matrix mat3 = mat1 * mat2;

    std::cout << "Result:\n" << mat3 << std::endl;

    std::cout << "Number of rows: " << mat3.get_rows() << std::endl;
    std::cout << "Number of columns: " << mat3.get_cols() << std::endl;

    return 0;
}
