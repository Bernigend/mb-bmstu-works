//
// Created by Bernigend on 27.03.2020.
//

#include <iostream>

#ifndef LABORATORY_WORK_2_FRACTION_H
#define LABORATORY_WORK_2_FRACTION_H


class Fraction {
protected:
    /**
     * Числитель
     */
    int numerator;

    /**
     * Знаменатель
     */
    int denominator;

public:
    /**
     * Конструктор по умолчанию
     */
    Fraction();

    /**
     * Конструктор копирования
     *
     * @param _fraction
     */
    Fraction(Fraction& _fraction);

    /**
     * Конструктор копирования
     *
     * @param _fraction
     */
    Fraction(const Fraction& _fraction);

    /**
     * Конструктор с параметром для целого числа
     * @param _numerator
     */
    explicit Fraction(int _numerator);

    /**
     * Конструктор с параметрами
     *
     * @param _numerator
     * @param _denominator
     */
    Fraction(int _numerator, int _denominator);

    /**
     * Перегрузка оператора вывода
     *
     * @param _stream
     * @param _fraction
     *
     * @return
     */
    friend std::ostream& operator<< (std::ostream& _stream, const Fraction& _fraction);

    /**
     * Перегрузка оператора ввода
     *
     * @param _stream
     * @param _fraction
     *
     * @return
     */
    friend std::istream& operator>> (std::istream& _stream, Fraction& _fraction);

    /**
     * Обрабатывает сложение двух объектов класса
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator+ (const Fraction& _fraction);

    /**
     * Обрабатывает сложение целого числа и объекта класса
     *
     * @param _num
     *
     * @return
     */
    Fraction operator+ (int _num);

    /**
     * Ничего не делает
     *
     * @return
     */
    Fraction operator+ ();

    /**
     * Оператор +=
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator+= (const Fraction& _fraction);

    /**
     * Оператор +=
     *
     * @param _num
     *
     * @return
     */
    Fraction operator+= (int _num);

    /**
     * Обрабатывает разность двух объектов класса
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator- (const Fraction& _fraction);

    /**
     * Обрабатывает разность целого числа и объекта класса
     *
     * @param _num
     *
     * @return
     */
    Fraction operator- (int _num);

    /**
     * Унарный минус
     *
     * @return
     */
    Fraction operator- ();

    /**
     * Оператор -=
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator-= (const Fraction& _fraction);

    /**
     * Оператор -=
     *
     * @param _num
     *
     * @return
     */
    Fraction operator-= (int _num);

    /**
     * Обрабатывает произведение двух объектов класса
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator* (const Fraction& _fraction);

    /**
     * Обрабатывает произведение целого числа и объекта класса
     *
     * @param _num
     *
     * @return
     */
    Fraction operator* (int _num);

    /**
     * Обрабатывает частное двух объектов класса
     *
     * @param _fraction
     *
     * @return
     */
    Fraction operator/ (const Fraction& _fraction);

    /**
     * Обрабатывает частное целого числа и объекта класса
     *
     * @param _num
     *
     * @return
     */
    Fraction operator/ (int _num);

    /**
     * Обрабатывает сравнение двух объектов класса
     *
     * @param _fraction
     *
     * @return
     */
    bool operator== (const Fraction& _fraction);

    /**
     * Я уже устал писать комменты
     * @param _fraction
     * @return
     */
    bool operator> (const Fraction& _fraction);

    /**
     * Я уже устал писать комменты
     * @param _fraction
     * @return
     */
    bool operator>= (const Fraction& _fraction);

    /**
     * Я уже устал писать комменты
     * @param _fraction
     * @return
     */
    bool operator< (const Fraction& _fraction);

    /**
     * Я уже устал писать комменты
     * @param _fraction
     * @return
     */
    bool operator<= (const Fraction& _fraction);

    /**
     * Перегрузка оператора присваивания
     *
     * @param _fraction
     *
     * @return
     */
    Fraction& operator= (const Fraction& _fraction);

    /**
     * Обрабатывает приведение объекта класса к типу double
     *
     * @return
     */
    explicit operator double();

    /**
     * Обрабатывает приведение объекта класса к типу float
     *
     * @return
     */
    explicit operator float();

    /**
     * @return числитель
     */
    inline int getNumerator() const;

    /**
     * @return знаменатель
     */
    inline int getDenominator() const;
};

Fraction operator+ (int _num, Fraction& _fraction);
Fraction operator- (int _num, Fraction& _fraction);
Fraction operator* (int _num, Fraction& _fraction);
Fraction operator/ (int _num, Fraction& _fraction);


int Fraction::getNumerator() const {
    return this->numerator;
}

int Fraction::getDenominator() const {
    return this->denominator;
}


#endif //LABORATORY_WORK_2_FRACTION_H
