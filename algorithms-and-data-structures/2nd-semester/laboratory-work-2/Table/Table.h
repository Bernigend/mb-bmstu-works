/**
 * Created by Bernigend on 28.02.2020.
 */

#include <iostream>
#include "TableElement.h"

#ifndef LAB_2_TABLE_H
#define LAB_2_TABLE_H


class Table {

protected:
	pTableElement head = nullptr;

public:
	/**
	 * Добавляет элемент в начало таблицы
	 * @param key
	 * @param value
	 */
	virtual void addToStart(Key key, Value value);

	/**
	 * Добавляет элемент в конец таблицы
	 * @param key
	 * @param value
	 */
	virtual void addToEnd(Key key, Value value);

	/**
	 * Возвращает элемент по ключу
	 * @param key
	 * @return
	 */
    virtual pTableElement findByKey(Key key);

	/**
	 * Удаляет элемент по ключу
	 * @param key
	 */
	void deleteByKey(Key key);

	/**
	 * Выводит элементы таблицы на экран
	 */
	void print();

	/**
	 * Проверяет, есть ли элементы в таблице
	 * @return
	 */
	bool isEmpty();
};


#endif //LAB_2_TABLE_H
