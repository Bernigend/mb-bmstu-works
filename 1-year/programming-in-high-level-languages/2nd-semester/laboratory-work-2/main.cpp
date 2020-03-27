#include <iostream>
#include "Fraction.h"

int main() {
    Fraction _fraction1 { 1, 4 };
    Fraction _fraction2 { 2, 5 };

    std::cout << _fraction1 + _fraction2 << std::endl;
    std::cout << _fraction1 - _fraction2 << std::endl;
    std::cout << _fraction1 * _fraction2 << std::endl;
    std::cout << _fraction1 / _fraction2 << std::endl;

    std::cout << (double)(_fraction1 + _fraction2) << std::endl;

    return 0;
}
