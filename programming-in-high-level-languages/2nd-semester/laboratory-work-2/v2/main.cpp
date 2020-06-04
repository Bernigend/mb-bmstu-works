#include <iostream>
#include "Fraction.h"

int main() {

    Fraction _fraction1 { 1, 4 };
    Fraction _fraction2 { 3, 4 };
    Fraction _fraction3;

    // вывод
    std::cout << _fraction1 << std::endl;
    std::cout << std::endl;

    // ввод
    std::cout << "Enter 3rd fraction: " << std::endl;
    std::cin >> _fraction3;
    std::cout << std::endl;

    // +
    std::cout << "+" << std::endl;
    std::cout << (1 + _fraction2) << std::endl;
    std::cout << (_fraction1 + 1) << std::endl;
    std::cout << (_fraction1 + _fraction2) << std::endl;
    std::cout << (+_fraction2) << std::endl;
    std::cout << std::endl;

    // +=
    std::cout << "+=" << std::endl;
    _fraction3 += 1;
    std::cout << _fraction3 << std::endl;
    std::cout << std::endl;

    // -
    std::cout << "-" << std::endl;
    std::cout << (1 - _fraction2) << std::endl;
    std::cout << (_fraction1 - 1) << std::endl;
    std::cout << (_fraction1 - _fraction2) << std::endl;
    std::cout << (-_fraction2) << std::endl;
    std::cout << std::endl;

    // -=
    std::cout << "-=" << std::endl;
    _fraction3 -= 1;
    std::cout << _fraction3 << std::endl;
    std::cout << std::endl;

    // *
    std::cout << "*" << std::endl;
    std::cout << (2 * _fraction2) << std::endl;
    std::cout << (_fraction1 * 2) << std::endl;
    std::cout << (_fraction1 * _fraction2) << std::endl;
    std::cout << std::endl;

    // *=
    std::cout << "*=" << std::endl;
    _fraction3 *= 2;
    std::cout << _fraction3 << std::endl;
    std::cout << std::endl;

    // /
    std::cout << "/" << std::endl;
    std::cout << (2 / _fraction2) << std::endl;
    std::cout << (_fraction1 / 2) << std::endl;
    std::cout << (_fraction1 / _fraction2) << std::endl;
    std::cout << std::endl;

    // /=
    std::cout << "/=" << std::endl;
    _fraction3 /= 2;
    std::cout << _fraction3 << std::endl;
    std::cout << std::endl;

    // ==
    std::cout << "==" << std::endl;
    std::cout << (1 == _fraction2) << std::endl;
    std::cout << (_fraction1 == 1) << std::endl;
    std::cout << (_fraction1 == _fraction2) << std::endl;
    std::cout << std::endl;

    // >
    std::cout << ">" << std::endl;
    std::cout << (1 > _fraction2) << std::endl;
    std::cout << (_fraction1 > 1) << std::endl;
    std::cout << (_fraction1 > _fraction2) << std::endl;
    std::cout << std::endl;

    // >=
    std::cout << ">=" << std::endl;
    std::cout << (1 >= _fraction2) << std::endl;
    std::cout << (_fraction1 >= 1) << std::endl;
    std::cout << (_fraction1 >= _fraction2) << std::endl;
    std::cout << std::endl;

    // <
    std::cout << "<" << std::endl;
    std::cout << (1 < _fraction2) << std::endl;
    std::cout << (_fraction1 < 1) << std::endl;
    std::cout << (_fraction1 < _fraction2) << std::endl;
    std::cout << std::endl;

    // <=
    std::cout << "<=" << std::endl;
    std::cout << (1 <= _fraction2) << std::endl;
    std::cout << (_fraction1 <= 1) << std::endl;
    std::cout << (_fraction1 <= _fraction2) << std::endl;
    std::cout << std::endl;

    // double
    std::cout << (double)_fraction1 << std::endl;
    // float
    std::cout << (float)_fraction1 << std::endl;

    return EXIT_SUCCESS;
}
