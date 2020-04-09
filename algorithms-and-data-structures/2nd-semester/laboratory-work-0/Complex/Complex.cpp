//
// Created by Bernigend on 09.04.2020.
//

#include "Complex.h"

// конструктор с параметрами по умолчанию
Complex::Complex(double _re, double _im) : re{_re}, im{_im} {}
// конструктор копирования
Complex::Complex(const Complex& complex) : re{complex.getRe()}, im{complex.getIm()} {}

// оператор сложения
Complex operator+ (const Complex& complex1, const Complex& complex2)
{
    return Complex {complex1.re + complex2.re, complex1.im + complex2.im};
}

Complex Complex::operator+ (const Complex& complex)
{
    return (*this) + complex;
}

// оператор вычитания
Complex operator- (const Complex& complex1, const Complex& complex2)
{
    return Complex {complex1.re - complex2.re, complex1.im - complex2.im};
}

Complex Complex::operator- (const Complex& complex)
{
    return (*this) - complex;
}

// оператор умножения
Complex operator* (const Complex& complex1, const Complex& complex2)
{
    return Complex {
            complex1.re * complex2.re - complex1.im * complex2.im,
            complex1.re * complex2.im + complex1.im * complex2.re
    };
}

Complex Complex::operator* (const Complex& complex)
{
    return (*this) * complex;
}

// оператор деления
Complex operator/ (const Complex& complex1, const Complex& complex2)
{
    double r = complex2.re * complex2.re + complex2.im * complex2.im;
    return Complex{
            ((complex1.re * complex2.re + complex1.im * complex2.im) / r),
            ((complex1.im * complex2.re - complex1.re * complex2.im) / r)
    };
}

Complex Complex::operator/ (const Complex& complex)
{
    return (*this) / complex;
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