//
// Created by Bernigend on 29.03.2020.
//

#include <iostream>

#ifndef LABORATORY_WORK_2_V2_FRACTION_H
#define LABORATORY_WORK_2_V2_FRACTION_H


class Fraction {
    // числитель
    int numerator;

    // знаменатель
    int denominator;

public:

    // конструктор с параметрами
    explicit Fraction(int, int = 1);
    // копирующий конструктор
    Fraction(const Fraction&);
    // конструктор по умолчанию
    Fraction();

    // перегрузка оператора вывода
    friend std::ostream& operator<< (std::ostream&, const Fraction&);
    // перегрузка оператора ввода
    friend std::istream& operator>> (std::istream&, Fraction&);

    // int + fraction
    friend Fraction operator+ (int, const Fraction&);
    // fraction + int
    friend Fraction operator+ (const Fraction&, int);
    // fraction + fraction
    friend Fraction operator+ (const Fraction&, const Fraction&);
    // +fraction
    Fraction operator+ ();

    // fraction += int
    Fraction operator+= (int);
    // fraction += fraction
    Fraction operator+= (const Fraction&);

    // int - fraction
    friend Fraction operator- (int, const Fraction&);
    // fraction - int
    friend Fraction operator- (const Fraction&, int);
    // fraction - fraction
    friend Fraction operator- (const Fraction&, const Fraction&);
    // -fraction
    Fraction operator- ();

    // fraction -= int
    Fraction operator-= (int);
    // fraction -= fraction
    Fraction operator-= (const Fraction&);

    // int * fraction
    friend Fraction operator* (int, const Fraction&);
    // fraction * int
    friend Fraction operator* (const Fraction&, int);
    // fraction * fraction
    friend Fraction operator* (const Fraction&, const Fraction&);

    // fraction *= int
    Fraction operator*= (int);
    // fraction *= fraction
    Fraction operator*= (const Fraction&);

    // int / fraction
    friend Fraction operator/ (int, const Fraction&);
    // fraction / int
    friend Fraction operator/ (const Fraction&, int);
    // fraction / fraction
    friend Fraction operator/ (const Fraction&, const Fraction&);

    // fraction /= int
    Fraction operator/= (int);
    // fraction /= fraction
    Fraction operator/= (const Fraction&);

    // fraction == int
    friend bool operator== (const Fraction&, int);
    // int == fraction
    friend bool operator== (int, const Fraction&);
    // fraction == fraction
    friend bool operator== (const Fraction&, const Fraction&);

    // fraction > int
    friend bool operator> (const Fraction&, int);
    // int > fraction
    friend bool operator> (int, const Fraction&);
    // fraction > fraction
    friend bool operator> (const Fraction&, const Fraction&);

    // fraction >= int
    friend bool operator>= (const Fraction&, int);
    // int >= fraction
    friend bool operator>= (int, const Fraction&);
    // fraction >= fraction
    friend bool operator>= (const Fraction&, const Fraction&);

    // fraction < int
    friend bool operator< (const Fraction&, int);
    // int < fraction
    friend bool operator< (int, const Fraction&);
    // fraction < fraction
    friend bool operator< (const Fraction&, const Fraction&);

    // fraction <= int
    friend bool operator<= (const Fraction&, int);
    // int <= fraction
    friend bool operator<= (int, const Fraction&);
    // fraction <= fraction
    friend bool operator<= (const Fraction&, const Fraction&);

    // fraction = fraction
    Fraction& operator= (const Fraction&);
    // fraction = int
    Fraction& operator= (int);

    // (double)fraction
    explicit operator double();
    // (float)fraction
    explicit operator float();

    inline int getNumerator() const;
    inline int getDenominator() const;

};


int Fraction::getNumerator() const {
    return this->numerator;
}

int Fraction::getDenominator() const {
    return this->denominator;
}

#endif //LABORATORY_WORK_2_V2_FRACTION_H
