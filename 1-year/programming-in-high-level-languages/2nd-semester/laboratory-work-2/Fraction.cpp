//
// Created by Bernigend on 27.03.2020.
//

#include "Fraction.h"


Fraction::Fraction() : numerator{0}, denominator{0} { }


Fraction::Fraction(Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }


Fraction::Fraction(const Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }


Fraction::Fraction(int _numerator, int _denominator) : numerator{_numerator}, denominator{_denominator} { }


std::ostream& operator<< (std::ostream& _stream, const Fraction& _fraction)
{
    return _stream << _fraction.getNumerator() << "/" << _fraction.getDenominator();
}


std::istream& operator>> (std::istream& _stream, Fraction& _fraction)
{
    _stream >> _fraction.numerator;
    _stream >> _fraction.denominator;
    return _stream;
}


Fraction Fraction::operator+ (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator() + this->denominator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

Fraction Fraction::operator+ (int _num)
{
    int _numerator   = this->numerator * 1 + this->denominator * _num;
    int _denominator = this->denominator * 1;

    Fraction temp { _numerator, _denominator };
    return temp;
}


Fraction Fraction::operator- (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator() - this->denominator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

Fraction Fraction::operator- (int _num)
{
    int _numerator   = this->numerator * 1 - this->denominator * _num;
    int _denominator = this->denominator * 1;

    Fraction temp { _numerator, _denominator };
    return temp;
}


Fraction Fraction::operator* (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

Fraction Fraction::operator* (int _num)
{
    int _numerator   = this->numerator * _num;
    int _denominator = this->denominator * 1;

    Fraction temp { _numerator, _denominator };
    return temp;
}


Fraction Fraction::operator/ (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator();
    int _denominator = this->denominator * _fraction.getNumerator();

    Fraction temp { _numerator, _denominator };
    return temp;
}

Fraction Fraction::operator/ (int _num)
{
    int _numerator   = this->numerator * 1;
    int _denominator = this->denominator * _num;

    Fraction temp { _numerator, _denominator };
    return temp;
}


bool Fraction::operator== (const Fraction& _fraction)
{
    return this->numerator == _fraction.getNumerator() && this->denominator == _fraction.getDenominator();
}


Fraction& Fraction::operator= (const Fraction& _fraction)
{
    if (&_fraction != this) {
        this->numerator = _fraction.getNumerator();
        this->denominator = _fraction.getDenominator();
    }
    return *this;
}


Fraction::operator double() {
    return double(this->numerator) / denominator;
}


Fraction::operator float() {
    return float(this->numerator) / float(denominator);
}