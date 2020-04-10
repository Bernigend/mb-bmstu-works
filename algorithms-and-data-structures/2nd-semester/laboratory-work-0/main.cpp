#include <iostream>
#include "Complex/Complex.h"

int main() {

    Complex _complex { 3, 4 };

    // сложение
    std::cout << "+" << std::endl;
    std::cout << (_complex + _complex) << std::endl;
    std::cout << (_complex + 5) << std::endl;

    std::cout << std::endl;

    // вычитание
    std::cout << "-" << std::endl;
    std::cout << (_complex - _complex) << std::endl;
    std::cout << (_complex - 5) << std::endl;

    std::cout << std::endl;

    // умножение
    std::cout << "*" << std::endl;
    std::cout << (_complex * _complex) << std::endl;
    std::cout << (_complex * 5) << std::endl;

    std::cout << std::endl;

    // деление
    std::cout << "/" << std::endl;
    std::cout << (_complex / _complex) << std::endl;
    std::cout << (_complex / 5) << std::endl;

    std::cout << std::endl;

    // конструктор копирования
    std::cout << "Copy:" << std::endl;
    Complex _complex2 = _complex;
    std::cout << _complex2 << std::endl;

    return 0;
}
