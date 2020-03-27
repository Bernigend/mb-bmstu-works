//
// Created by Bernigend on 27.03.2020.
//

#include "Fraction.h"

/**
     * Конструктор по умолчанию
     */
Fraction::Fraction() : numerator{0}, denominator{0} { }

/**
 * Конструктор копирования
 *
 * @param _fraction
 */
Fraction::Fraction(Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }

/**
 * Конструктор копирования
 *
 * @param _fraction
 */
Fraction::Fraction(const Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }

/**
 * Конструктор с параметрами
 *
 * @param _numerator
 * @param _denominator
 */
Fraction::Fraction(int _numerator, int _denominator) : numerator{_numerator}, denominator{_denominator} { }

/**
 * Перегрузка оператора вывода
 *
 * @param _stream
 * @param _fraction
 *
 * @return
 */
std::ostream& operator<< (std::ostream& _stream, const Fraction& _fraction)
{
    return _stream << _fraction.getNumerator() << "/" << _fraction.getDenominator();
}

/**
 * Перегрузка оператора ввода
 *
 * @param _stream
 * @param _fraction
 *
 * @return
 */
std::istream& operator>> (std::istream& _stream, Fraction& _fraction)
{
    _stream >> _fraction.numerator;
    _stream >> _fraction.denominator;
    return _stream;
}

/**
 * Обрабатывает сложение двух объектов класса
 *
 * @param _fraction
 *
 * @return
 */
Fraction Fraction::operator+ (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator() + this->denominator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

/**
 * Обрабатывает разность двух объектов класса
 *
 * @param _fraction
 *
 * @return
 */
Fraction Fraction::operator- (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator() - this->denominator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

/**
 * Обрабатывает произведение двух объектов класса
 *
 * @param _fraction
 *
 * @return
 */
Fraction Fraction::operator* (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

/**
 * Обрабатывает частное двух объектов класса
 *
 * @param _fraction
 *
 * @return
 */
Fraction Fraction::operator/ (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator();
    int _denominator = this->denominator * _fraction.getNumerator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

/**
 * Обрабатывает сравнение двух объектов класса
 *
 * @param _fraction
 *
 * @return
 */
bool Fraction::operator== (const Fraction& _fraction)
{
    return this->numerator == _fraction.getNumerator() && this->denominator == _fraction.getDenominator();
}

/**
 * Перегрузка оператора присваивания
 *
 * @param _fraction
 *
 * @return
 */
Fraction& Fraction::operator= (const Fraction& _fraction)
{
    if (&_fraction != this) {
        this->numerator = _fraction.getNumerator();
        this->denominator = _fraction.getDenominator();
    }
    return *this;
}

/**
 * Обрабатывает приведение объекта класса к типу double
 *
 * @return
 */
Fraction::operator double() {
    return double(this->numerator) / denominator;
}

/**
 * Обрабатывает приведение объекта класса к типу float
 *
 * @return
 */
Fraction::operator float() {
    return float(this->numerator) / float(denominator);
}