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
    friend Complex operator+ (const Complex&, const Complex&);
    Complex operator+ (const Complex&);
    // оператор вычитания
    friend Complex operator- (const Complex&, const Complex&);
    Complex operator- (const Complex&);
    // оператор умножения
    friend Complex operator* (const Complex&, const Complex&);
    Complex operator* (const Complex&);
    // оператор деления
    friend Complex operator/ (const Complex&, const Complex&);
    Complex operator/ (const Complex&);

    // оператор вывода
    friend std::ostream& operator<< (std::ostream&, const Complex&);
    // оператор ввода
    friend std::istream& operator>> (std::istream&, Complex&);

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
