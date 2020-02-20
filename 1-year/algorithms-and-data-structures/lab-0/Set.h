//
// Created by Bernigend on 20.02.2020.
//

#include <iostream>
#include "types.h"

#ifndef LAB0_SET_H
#define LAB0_SET_H


class Set {
public:
    /**
     * Конструктор класса
     * При указании размера множества заполняет тот нулями
     * При указании значений заполняет множество ими
     * @param size
     * @param values
     */
    explicit Set(int size = 0, const int *values = nullptr);

    /**
     * Добавляет число к множеству
     * @param number - число для добавления
     */
    void addNumber(int number);

    /**
     * Проверяет, включает ли множество переданное число
     * @param number - число для поиска
     * @return
     */
    bool isInclude(int number);

    /**
     * Удаляет число из множества, если оно там есть
     * @param number - число для удаления
     */
    void deleteNumber(int number);

    /**
     * Объединяет переданное множество с текущим
     * @param set - множество для объединения
     */
    void uniteWith(const Set *set);

    /**
     * Пересечение множеств
     * @param set - множество для пересечения
     */
    void intersectionWith(const Set *set);

    /**
     * Разность множеств
     * @param set
     */
    void difference(const Set *set);

    /**
     * Проверяет, является ли множется пустым
     * @return
     */
    bool isEmpty() const;

    /**
     * Выводит набор чисел на экран
     */
    void show() const;

    /**
     * Возвращает элемент множества
     * @param index
     * @return
     */
    int getNumber(uInt index) const;

    /**
     * Возвращает количество элементов множества
     * @return
     */
    uInt getSize() const;
};


#endif //LAB0_SET_H
