//
// Created by Bernigend on 20.02.2020.
//

#include <iostream>
#include "types.h"

#ifndef LAB0_SET_H
#define LAB0_SET_H

int numbers[] = {1,22,13,5,8,45,0};
int const size = 7;

class Set {
//	int *numbers = nullptr;
//	uInt size = 0;
	int *shk;

public:
	/**
	 * Конструктор класса
	 * @param set
	 */
	Set();

    /**
     * Конструктор класса
     * При указании размера множества заполняет тот нулями
     * При указании значений заполняет множество ими
     * @param size
     * @param values
     */
    Set(int size, const int *values);

    /**
     * Добавляет число к множеству
     * @param number - число для добавления
     */
    void addNumber(int number);

    /**
     * Удаляет число из множества, если оно там есть
     * @param number - число для удаления
     */
    void deleteNumber(int number);

    /**
     * Объединяет переданное множество с текущим
     * @param set - множество для объединения
     */
    Set uniteWith(const Set *set);

    /**
     * Пересечение множеств
     * @param set - множество для пересечения
     */
    void intersectionWith(const Set *set);

    /**
     * Разность множеств
     * @param set
     */
    void differenceWith(const Set *set);

    /**
     * Проверяет, является ли множется пустым
     * @return
     */
    bool isEmpty() const;

	/**
	 * Проверяет, включает ли множество переданное число
	 * @param number - число для поиска
	 * @return
	 */
	bool isInclude(int number);

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
	 * Возвращает все элементы множества
	 * @param index
	 * @return
	 */
	int * getNumbers() const;

    /**
     * Возвращает количество элементов множества
     * @return
     */
    uInt getSize() const;

    /**
     * Объединение двух множеств
     * @param set1
     * @param set2
     * @return объединенный набор
     */
    static Set * unite(Set *set1, Set *set2);

	/**
	 * Пересечение двух переданных множеств
	 * @param set1
	 * @param set2
	 * @return
	 */
    static Set * intersection(Set *set1, Set *set2);

	/**
	 * Разность двух переданных множеств
	 * @param set1
	 * @param set2
	 * @return
	 */
    static Set * difference(Set *set1, Set *set2);

    Set *operator+ (Set set);

	Set *operator- (Set set);

	Set *operator* (Set set);
};


#endif //LAB0_SET_H
