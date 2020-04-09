//
// Created by Bernigend on 09.04.2020.
//

#include "iostream"

#ifndef LABORATORY_WORK_0_COMPLEX_H
#define LABORATORY_WORK_0_COMPLEX_H


class Complex {
protected:
    double re;
    double im;

public:
    // конструктор с параметрами по умолчанию
    Complex(double = 0.0, double = 0.0);
    // конструктор копирования
    Complex(const Complex&);

    // оператор сложения
    friend Complex operator+ (const Complex& complex1, const Complex& complex2);
    // оператор вычитания
    friend Complex operator- (const Complex& complex1, const Complex& complex2);
    // оператор умножения
    friend Complex operator* (const Complex& complex1, const Complex& complex2);
    // оператор деления
    friend Complex operator/ (const Complex& complex1, const Complex& complex2);

    // оператор вывода
    friend std::ostream& operator<< (std::ostream& stream, const Complex& complex);
    // оператор ввода
    friend std::istream& operator>> (std::istream& stream, Complex& complex);

    inline double getRe() const;
    inline double getIm() const;
};

double Complex::getRe() const
{
    return this->re;
}

double Complex::getIm() const
{
    return this->im;
}


#endif //LABORATORY_WORK_0_COMPLEX_H
