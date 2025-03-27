// functions.cpp
#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

void printRoots(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The equation has two distinct real roots:" << endl;
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "The equation has one real root:" << endl;
        cout << "Root: " << root << endl;
    } else {
        cout << "The equation has no real roots." << endl;
    }
}

void readCoefficients(double &a, double &b, double &c) {
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
}

