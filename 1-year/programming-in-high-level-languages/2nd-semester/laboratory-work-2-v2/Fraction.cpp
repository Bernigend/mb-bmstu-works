//
// Created by Bernigend on 29.03.2020.
//

#include "Fraction.h"

/// --------

Fraction::Fraction(int _numerator, int _denominator)
    : numerator{_numerator}, denominator{_denominator} { }

Fraction::Fraction(const Fraction& _fraction)
    : numerator{_fraction.getNumerator()}, denominator{_fraction.getDenominator()} { }

Fraction::Fraction()
    : numerator{1}, denominator{1} { }

/// --------

std::ostream& operator<< (std::ostream& _stream, const Fraction& _fraction)
{
    if (_fraction.getDenominator() == 1)
        _stream << _fraction.numerator;
    else
        _stream << _fraction.numerator << "/" << _fraction.denominator;
    return _stream;
}

std::istream& operator>> (std::istream& _stream, Fraction& _fraction)
{
    _stream >> _fraction.numerator;
    _stream >> _fraction.denominator;
    return _stream;
}

/// --------

Fraction operator+ (int _num, const Fraction& _fraction)
{
    int _numerator   = _fraction.numerator + _fraction.denominator * _num;
    int _denominator = _fraction.denominator;
    return Fraction { _numerator, _denominator };
}

Fraction operator+ (const Fraction& _fraction, int _num)
{
    return _num + _fraction;
}

Fraction operator+ (const Fraction& _fraction1, const Fraction& _fraction2)
{
    int _numerator   = _fraction1.numerator * _fraction2.denominator + _fraction1.denominator * _fraction2.numerator;
    int _denominator = _fraction1.denominator * _fraction2.denominator;
    return Fraction { _numerator, _denominator };
}

Fraction Fraction::operator+ ()
{
    return *this;
}

/// --------

Fraction Fraction::operator+= (int _num)
{
    return (*this = *this + _num);
}

Fraction Fraction::operator+= (const Fraction& _fraction)
{
    return (*this = *this + _fraction);
}

/// --------

Fraction operator- (int _num, const Fraction& _fraction)
{
    Fraction temp = _fraction;
    return _num + (-temp);
}

Fraction operator- (const Fraction& _fraction, int _num)
{
    return _fraction + (-_num);
}

Fraction operator- (const Fraction& _fraction1, const Fraction& _fraction2)
{
    Fraction temp = _fraction2;
    return _fraction1 + (-temp);
}

Fraction Fraction::operator- ()
{
    this->numerator = -this->numerator;
    return *this;
}

/// --------

Fraction Fraction::operator-= (int _num)
{
    return (*this = *this - _num);
}

Fraction Fraction::operator-= (const Fraction& _fraction)
{
    return (*this = *this - _fraction);
}

/// --------

Fraction operator* (int _num, const Fraction& _fraction)
{
    int _numerator   = _fraction.numerator * _num;
    int _denominator = _fraction.denominator;
    return Fraction { _numerator, _denominator };
}

Fraction operator* (const Fraction& _fraction, int _num)
{
    return _num * _fraction;
}

Fraction operator* (const Fraction& _fraction1, const Fraction& _fraction2)
{
    int _numerator   = _fraction1.numerator * _fraction2.numerator;
    int _denominator = _fraction1.denominator * _fraction2.denominator;
    return Fraction { _numerator, _denominator };
}

/// --------

Fraction Fraction::operator*= (int _num)
{
    return (*this = *this * _num);
}

Fraction Fraction::operator*= (const Fraction& _fraction)
{
    return (*this = *this * _fraction);
}

/// --------

Fraction operator/ (int _num, const Fraction& _fraction)
{
    int _numerator   = _num * _fraction.denominator;
    int _denominator = _num * _fraction.numerator;
    return Fraction { _numerator, _denominator };
}

Fraction operator/ (const Fraction& _fraction, int _num)
{
    int _numerator   = _fraction.numerator;
    int _denominator = _num * _fraction.denominator;
    return Fraction { _numerator, _denominator };
}

Fraction operator/ (const Fraction& _fraction1, const Fraction& _fraction2)
{
    int _numerator   = _fraction1.numerator * _fraction2.denominator;
    int _denominator = _fraction1.denominator * _fraction2.numerator;
    return Fraction { _numerator, _denominator };
}

/// --------

Fraction Fraction::operator/= (int _num)
{
    return (*this = *this / _num);
}

Fraction Fraction::operator/= (const Fraction& _fraction)
{
    return (*this = *this / _fraction);
}

/// --------

bool operator== (const Fraction& _fraction, int _num)
{
    return (_fraction.denominator == 1 && _num == _fraction.numerator);
}

bool operator== (int _num, const Fraction& _fraction)
{
    return _fraction == _num;
}

bool operator== (const Fraction& _fraction1, const Fraction& _fraction2)
{
    return (_fraction1.numerator == _fraction2.numerator && _fraction1.denominator == _fraction2.denominator);
}

/// --------

bool operator> (const Fraction& _fraction, int _num)
{
    if (_fraction.denominator == 1) {
        return _fraction.numerator > _num;
    }

    Fraction tempFraction = _fraction;
    auto temp = (float)tempFraction;
    return temp > (float)_num;
}

bool operator> (int _num, const Fraction& _fraction)
{
    return !(_fraction > _num && !(_fraction == _num));
}

bool operator> (const Fraction& _fraction1, const Fraction& _fraction2)
{
    if (_fraction1.denominator == _fraction2.denominator) {
        return _fraction1.numerator > _fraction2.numerator;
    }

    Fraction tempFraction = _fraction2;
    auto temp = (float)tempFraction;
    return _fraction1 > temp;
}

/// --------

bool operator>= (const Fraction& _fraction, int _num)
{
    return _fraction > _num || _fraction == _num;
}

bool operator>= (int _num, const Fraction& _fraction)
{
    return _num > _fraction || _num == _fraction;
}

bool operator>= (const Fraction& _fraction1, const Fraction& _fraction2)
{
    return _fraction1 > _fraction2 || _fraction1 == _fraction2;
}

/// --------

bool operator< (const Fraction& _fraction, int _num)
{
    return !(_fraction >= _num);
}

bool operator< (int _num, const Fraction& _fraction)
{
    return !(_num >= _fraction);
}

bool operator< (const Fraction& _fraction1, const Fraction& _fraction2)
{
    return !(_fraction1 >= _fraction2);
}

/// --------

bool operator<= (const Fraction& _fraction, int _num)
{
    return _fraction < _num || _fraction == _num;
}

bool operator<= (int _num, const Fraction& _fraction)
{
    return _num < _fraction || _fraction == _num;
}

bool operator<= (const Fraction& _fraction1, const Fraction& _fraction2)
{
    return _fraction1 < _fraction2 || _fraction1 == _fraction2;
}

/// --------

Fraction& Fraction::operator= (const Fraction& _fraction)
{
    if (&_fraction != this) {
        this->numerator   = _fraction.getNumerator();
        this->denominator = _fraction.getDenominator();
    }

    return *this;
}

Fraction& Fraction::operator= (int _num)
{
    this->numerator   = _num;
    this->denominator = 1;
    return *this;
}

/// --------

Fraction::operator double()
{
    if (this->denominator == 0) {
        throw std::runtime_error("Denominator == 0");
    }
    return double(this->numerator) / double(this->denominator);
}

Fraction::operator float()
{
    if (this->denominator == 0) {
        throw std::runtime_error("Denominator == 0");
    }
    return float(this->numerator) / float(this->denominator);
}