#include <iostream>
#include <cmath>

double factorial(int n) {
    if (n == 0) return 1;
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    double lambda, t;

    // Ask the user to input the values of lambda and t
    std::cout << "Enter the value of lambda (λ): ";
    std::cin >> lambda;
    
    std::cout << "Enter the value of t: ";
    std::cin >> t;

    // Loop to calculate P(k) for k from 0 to 10
    for (int k = 0; k <= 10; k++) {
        double pk = (std::pow(lambda * t, k) / factorial(k)) * std::exp(-lambda * t);
        std::cout << "P(" << k << ") = " << pk << std::endl;
    }

    return 0;
}
