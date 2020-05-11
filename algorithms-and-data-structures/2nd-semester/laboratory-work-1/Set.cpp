//
// Created by Bernigend on 20.02.2020.
//

#include <iostream>
#include "types.h"
#include "Set.h"

/**
 * Конструктор класса
 * @param set
 */
Set::Set()
{
//	this->numbers = set->getNumbers();
//	this->size    = set->getSize();
	this->shk = new int[size];
	for (int i = 0; i<size; i++) {
		shk[i] = 0;
	}
}

/**
 * Конструктор класса
 * При указании размера множества заполняет тот нулями
 * При указании значений заполняет множество ими
 * @param size
 * @param values
 */
Set::Set(int size, const int *values)
{
//    if (size > 0) {
//        this->size = size;
//        this->numbers = new int[size];
//
//        for (uInt i = 0; i < size; i++) {
//            if (values != nullptr) {
//                this->numbers[i] = values[i];
//            } else {
//                this->numbers[i] = 0;
//            }
//        }
//    }
}

/**
 * Добавляет число к множеству
 * @param number - число для добавления
 */
void Set::addNumber(int number)
{
//    int *oldNumbers = this->numbers;
//    this->numbers = new int[this->size + 1];

    for (uInt i = 0; i < size; i++) {
    	if (numbers[i] == number) {
		    this->shk[i] = 1;
		    return;
	    }
    }

//    this->numbers[this->size] = number;
//    this->size++;
}

/**
 * Удаляет число из множества, если оно там есть
 * @param number - число для удаления
 */
void Set::deleteNumber(int number)
{
	for (uInt i = 0; i < size; i++) {
		if (numbers[i] == number) {
			this->shk[i] = 0;
			return;
		}
	}

//    if (this->size == 0) {
//        return;
//    }
//
//    int *newNumbers = new int[this->size - 1];
//    uInt counter = 0;
//    bool found = false;
//
//    for (uInt i = 0; i < this->size; i++) {
//        if (this->numbers[i] != number) {
//            newNumbers[counter] = this->numbers[i];
//            counter++;
//            continue;
//        }
//        found = true;
//    }
//
//    if (found) {
//        this->numbers = newNumbers;
//        this->size--;
//    }
}

/**
 * Объединяет переданное множество с текущим
 * @param set - множество для объединения
 */
Set Set::uniteWith(const Set *set)
{

	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 1 || set->shk[i] == 1) {
			temp.shk[i] = 1;
		}
	}

	return temp;

//    uInt tmpSize = this->size;
//    int *tmpNumbers = new int[this->size + set->getSize()];
//    bool found;
//
//    for (uInt i = 0; i < this->size; i++) {
//        tmpNumbers[i] = this->numbers[i];
//    }
//
//    for (uInt i = 0; i < set->getSize(); i++) {
//        // проверяем наличие значения из нового множества в добавляемом
//        found = false;
//        for (uInt k = 0; k < tmpSize; k++) {
//            if (tmpNumbers[k] == set->getNumber(i)) {
//                found = true;
//                break;
//            }
//        }
//
//        if (!found) {
//            tmpNumbers[tmpSize] = set->getNumber(i);
//            tmpSize++;
//        }
//    }
//
//    int *newNumbers = new int[tmpSize];
//    for (uInt i = 0; i < tmpSize; i++) {
//        newNumbers[i] = tmpNumbers[i];
//    }
//
//    this->numbers = newNumbers;
//    this->size    = tmpSize;
}

/**
 * Пересечение множеств
 * @param set - множество для пересечения
 */
Set Set::intersectionWith(const Set *set)
{

	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 1 && set->shk[i] == 1) {
			temp.shk[i] = 1;
		}
	}

	return temp;

//    uInt tmpSize = 0;
//    int *tmpNumbers = new int[this->size + set->getSize()];
//    bool found;
//
//    // проходим по текущему множеству
//    for (uInt i = 0; i < this->size; i++) {
//        // проходим по переданному множеству
//        for (uInt k = 0; k < set->getSize(); k++) {
//            // находим одинаковые числа
//            if (this->numbers[i] == set->getNumber(k)) {
//                // находим дубликаты чисел
//                found = false;
//                for (uInt j = 0; j < tmpSize; j++) {
//                    if (this->numbers[i] == tmpNumbers[j]) {
//                        found = true;
//                    }
//                }
//
//                // добавляем число в множество
//                if (!found) {
//                    tmpNumbers[tmpSize] = this->numbers[i];
//                    tmpSize++;
//                }
//            }
//        }
//    }
//
//    int *newNumbers = new int[tmpSize];
//    for (uInt i = 0; i < tmpSize; i++) {
//        newNumbers[i] = tmpNumbers[i];
//    }
//
//    this->numbers = newNumbers;
//    this->size    = tmpSize;
}

/**
 * Разность множеств
 * @param set
 */
Set Set::differenceWith(const Set *set)
{

	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 1 && set->shk[i] == 0) {
			temp.shk[i] = 1;
		}
	}

	return temp;
//
//    uInt tmpSize = 0;
//    int *tmpNumbers = new int[this->size];
//    bool found;
//
//    for (uInt i = 0; i < this->size; i++) {
//        found = false;
//        for (uInt k = 0; k < set->getSize(); k++) {
//            if (this->numbers[i] == set->getNumber(k)) {
//                found = true;
//                break;
//            }
//        }
//
//        if (!found) {
//            tmpNumbers[tmpSize] = this->numbers[i];
//            tmpSize++;
//        }
//    }
//
//    int *newNumbers = new int[tmpSize];
//    for (uInt i = 0; i < tmpSize; i++) {
//        newNumbers[i] = tmpNumbers[i];
//    }
//
//    this->numbers = newNumbers;
//    this->size    = tmpSize;
}

/**
 * Проверяет, является ли множется пустым
 * @return
 */
bool Set::isEmpty() const
{
	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 1 && set->shk[i] == 1) {
			temp.shk[i] = 1;
		}
	}

	return temp;
}

/**
 * Проверяет, включает ли множество переданное число
 * @param number - число для поиска
 * @return
 */
bool Set::isInclude(int number)
{
	for (uInt i = 0; i < this->size; i++) {
		if (numbers[i] == number) {
			return true;
		}
	}

	return false;
}

/**
 * Выводит набор чисел на экран
 */
void Set::show() const {
    for (uInt i = 0; i < size; i++) {
    	if (shk[i] == 1)
            std::cout << numbers[i] << std::endl;
    }
}

/**
 * Возвращает элемент множества
 * @param index
 * @return
 */
int Set::getNumber(uInt index) const {
    if (index > this->size) {
        return 0;
    }
    return this->numbers[index];
}

/**
 * Возвращает все элементы множества
 * @param index
 * @return
 */
int * Set::getNumbers() const {
	return this->numbers;
}

/**
 * Возвращает количество элементов множества
 * @return
 */
uInt Set::getSize() const {
    return size;
}

/**
 * Объединение двух множеств
 * @param set1
 * @param set2
 * @return объединенный набор
 */
Set * Set::unite(Set *set1, Set *set2)
{
	Set *newSet = new Set(set1);
	newSet->uniteWith(set2);
	return newSet;
}

/**
 * Пересечение двух переданных множеств
 * @param set1
 * @param set2
 * @return
 */
Set * Set::intersection(Set *set1, Set *set2)
{
	Set *newSet = new Set(set1);
	newSet->intersectionWith(set2);
	return newSet;
}

/**
 * Разность двух переданных множеств
 * @param set1
 * @param set2
 * @return
 */
Set * Set::difference(Set *set1, Set *set2)
{
	Set *newSet = new Set(set1);
	newSet->differenceWith(set2);
	return newSet;
}

Set *Set::operator+ (Set set)
{
	Set *pSet = &set;
	return Set::unite(this, pSet);
}

Set *Set::operator- (Set set)
{
//	Set *pSet = &set;
//	return Set::difference(this, pSet);
	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 0) {
			temp.shk[i] = 1;
		}
	}

	return temp;
}

Set *Set::operator* (Set set)
{
//	Set *pSet = &set;
//	return Set::intersection(this, pSet);
	Set temp;
	for (uInt i = 0; i < size; i++) {
		if (shk[i] == 1 && set->shk[i] == 1) {
			temp.shk[i] = 1;
		}
	}

	return temp;
}