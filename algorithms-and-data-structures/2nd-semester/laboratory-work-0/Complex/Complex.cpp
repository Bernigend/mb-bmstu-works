//
// Created by Bernigend on 09.04.2020.
//

#include "Complex.h"

// конструктор с параметрами по умолчанию
// Complex::Complex(double _re, double _im) : re{_re}, im{_im} {}
Complex::Complex(double _re, double _im)
{
    this->re = _re;
    this->im = _im;
}
// конструктор копирования
// Complex::Complex(const Complex& complex) : re{complex.getRe()}, im{complex.getIm()} {}
Complex::Complex(const Complex& complex)
{
    this->re = complex.getRe();
    this->im = complex.getIm();
}

// оператор сложения
Complex Complex::operator+ (const Complex& complex)
{
    return Complex {this->re + complex.re, this->im + complex.im};
}

// оператор вычитания
Complex Complex::operator- (const Complex& complex)
{
    return Complex {this->re - complex.re, this->im - complex.im};
}

// оператор умножения
Complex Complex::operator* (const Complex& complex)
{
    return Complex {
        this->re * complex.re - this->im * complex.im,
        this->re * complex.im + this->im * complex.re
    };
}

// оператор деления
Complex Complex::operator/ (const Complex& complex)
{
    double r = complex.re * complex.re + complex.im * complex.im;
    return Complex {
        ((this->re * complex.re + this->im * complex.im) / r),
        ((this->im * complex.re - this->re * complex.im) / r)
    };
}

// оператор вывода
std::ostream& operator<< (std::ostream& stream, const Complex& complex)
{
    stream << "z = " << complex.re;

    if (complex.im >= 0) {
        stream << " + " << complex.im << "*i";
    } else {
        stream << " - " << -complex.im << "*i";
    }

    return stream;
}

// оператор ввода
std::istream& operator>> (std::istream& stream, Complex& complex)
{
    stream >> complex.re;
    stream >> complex.im;
    return stream;
}