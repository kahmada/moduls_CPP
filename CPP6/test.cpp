#include <iostream>
#include <cmath>  // Pour NAN, INFINITY

int main() {
    double a = NAN;   // Not a Number
    double b = INFINITY;  // Infini positif
    double c = -INFINITY; // Infini négatif

    std::cout << "NaN: " << a << std::endl;
    std::cout << "Positive Infinity: " << b << std::endl;
    std::cout << "Negative Infinity: " << c << std::endl;

    return 0;
}
