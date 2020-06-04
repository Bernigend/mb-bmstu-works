#include <iostream>
#include "Fraction.h"

int main() {
    Fraction _fraction1 { 1, 4 };
    Fraction _fraction2;

    // ввод дроби
    std::cout << "Enter fraction num. 2: " << std::endl;
    std::cin >> _fraction2;

    std::cout << std::endl;

    // сложение
    std::cout << "+" << std::endl;
    std::cout << _fraction1 + _fraction2 << std::endl;
    std::cout << _fraction1 + 1 << std::endl;
    std::cout << 1 + _fraction2 << std::endl;

    std::cout << std::endl;

    // разность
    std::cout << "-" << std::endl;
    std::cout << _fraction1 - _fraction2 << std::endl;
    std::cout << _fraction1 - 1 << std::endl;
    std::cout << 1 - _fraction2 << std::endl;

    std::cout << std::endl;

    // произведение
    std::cout << "*" << std::endl;
    std::cout << _fraction1 * _fraction2 << std::endl;
    std::cout << _fraction1 * 1 << std::endl;
    std::cout << 1 * _fraction2 << std::endl;

    std::cout << std::endl;

    // частное
    std::cout << "/" << std::endl;
    std::cout << _fraction1 / _fraction2 << std::endl;
    std::cout << _fraction1 / 1 << std::endl;
    std::cout << 1 / _fraction2 << std::endl;

    std::cout << std::endl;

    // унарный минус и плюс
    std::cout << "- +" << std::endl;
    std::cout << -_fraction1 << std::endl;
    std::cout << +_fraction2 << std::endl;

    std::cout << std::endl;

    // операторы += и -=
    std::cout << "+= -=" << std::endl;
    std::cout << (_fraction1 += _fraction2) << std::endl;
    std::cout << (_fraction1 -= _fraction2) << std::endl;

    std::cout << std::endl;

    // приведение типов
    std::cout << "double float" << std::endl;
    std::cout << (double)(_fraction1 + _fraction2) << std::endl;
    std::cout << (float)(_fraction1 + _fraction2) << std::endl;

    return 0;
}
