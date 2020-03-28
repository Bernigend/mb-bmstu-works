//
// Created by Bernigend on 27.03.2020.
//

#include "Fraction.h"


Fraction::Fraction() : numerator{0}, denominator{0} { }


Fraction::Fraction(Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }


Fraction::Fraction(const Fraction& _fraction) : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }


Fraction::Fraction(int _numerator) : numerator {_numerator}, denominator {1} { }


Fraction::Fraction(int _numerator, int _denominator) : numerator{_numerator}, denominator{_denominator} { }


std::ostream& operator<< (std::ostream& _stream, const Fraction& _fraction)
{
    if (_fraction.getDenominator() != 1)
        return _stream << _fraction.getNumerator() << "/" << _fraction.getDenominator();
    else
        return _stream << _fraction.getNumerator();
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

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator+ (int _num)
{
    int _numerator   = this->numerator * 1 + this->denominator * _num;
    int _denominator = this->denominator * 1;

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator+ ()
{
    return *this;
}

Fraction Fraction::operator+= (const Fraction& _fraction)
{
    return *this + _fraction;
}

Fraction Fraction::operator+= (int _num)
{
    return *this + _num;
}

Fraction operator+ (int _num, Fraction& _fraction)
{
    return _fraction + _num;
}


Fraction Fraction::operator- (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator() - this->denominator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator- (int _num)
{
    int _numerator   = this->numerator * 1 - this->denominator * _num;
    int _denominator = this->denominator * 1;

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator- ()
{
    return Fraction { -this->getNumerator(), this->getDenominator() };
}

Fraction Fraction::operator-= (const Fraction& _fraction)
{
    return *this - _fraction;
}

Fraction Fraction::operator-= (int _num)
{
    return *this - _num;
}

Fraction operator- (int _num, Fraction& _fraction)
{
    return _fraction - _num;
}


Fraction Fraction::operator* (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getNumerator();
    int _denominator = this->denominator * _fraction.getDenominator();

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator* (int _num)
{
    int _numerator   = this->numerator * _num;
    int _denominator = this->denominator * 1;

    return Fraction { _numerator, _denominator };
}

Fraction operator* (int _num, Fraction& _fraction)
{
    return _fraction * _num;
}


Fraction Fraction::operator/ (const Fraction& _fraction)
{
    int _numerator   = this->numerator * _fraction.getDenominator();
    int _denominator = this->denominator * _fraction.getNumerator();

    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator/ (int _num)
{
    int _numerator   = this->numerator * 1;
    int _denominator = this->denominator * _num;

    return Fraction { _numerator, _denominator };
}

Fraction operator/ (int _num, Fraction& _fraction)
{
    return _fraction / _num;
}


bool Fraction::operator== (const Fraction& _fraction)
{
    return this->numerator == _fraction.getNumerator() && this->denominator == _fraction.getDenominator();
}

bool Fraction::operator> (const Fraction& _fraction)
{
    return !(*this < _fraction) && !(*this == _fraction);
}

bool Fraction::operator>= (const Fraction& _fraction)
{
    return !(*this < _fraction);
}

bool Fraction::operator< (const Fraction& _fraction)
{
    if(this->denominator == _fraction.getDenominator()) {
        if(this->numerator > _fraction.getNumerator())
            return false;
    }

    if(this->numerator == _fraction.getDenominator()) {
        if(this->denominator < _fraction.getDenominator())
            return false;
    }

    auto num1 = (float)*this;
    float num2 = float(_fraction.getNumerator()) / float(_fraction.getDenominator());
    return num1 <= num2;
}

bool Fraction::operator<= (const Fraction& _fraction)
{
    return *this < _fraction || *this == _fraction;
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