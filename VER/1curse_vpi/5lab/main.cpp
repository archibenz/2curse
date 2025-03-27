#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile) {
        cerr << "Unable to open file input.txt" << endl;
        return 1;
    }

    double a, b, c;
    inputFile >> a >> b >> c;

    if (inputFile.fail()) {
        cerr << "Error reading coefficients from file. Make sure the file contains exactly three numbers." << endl;
        return 1;
    }

    cout << "Read coefficients: " << a << " " << b << " " << c << endl;

    inputFile.close();

    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The equation has two distinct real roots:" << endl;
        cout << "Root 1: " << setprecision(5) << root1 << endl;
        cout << "Root 2: " << setprecision(5) << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "The equation has one real root:" << endl;
        cout << "Root: " << setprecision(5) << root << endl;
    } else {
        cout << "The equation has no real roots." << endl;
    }

    return 0;
}

