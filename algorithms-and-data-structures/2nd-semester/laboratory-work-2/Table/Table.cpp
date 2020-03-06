/**
 * Created by Bernigend on 28.02.2020.
 */

#include "Table.h"

/**
 * Добавляет элемент в начало таблицы
 * @param key
 * @param value
 */
void Table::addToStart(Key key, Value value) {
	auto tmpElem = new TableElement(key, value);

	tmpElem->next = this->head;
	this->head    = tmpElem;
}

/**
 * Добавляет элемент в конец таблицы
 * @param key
 * @param value
 */
void Table::addToEnd(Key key, Value value) {
	if (this->head == nullptr) {
		this->head = new TableElement(key, value);
		return;
	}

	auto tmpElem = this->head;

	// проходимся до последнего элемента
	while (tmpElem->next != nullptr) {
		tmpElem = tmpElem->next;
	}

	tmpElem->next = new TableElement(key, value);
}

/**
 * Возвращает элемент по ключу
 * @param key
 * @return
 */
pTableElement Table::findByKey(Key key) {
	auto tmpElem = this->head;

	while (tmpElem != nullptr) {
		if (tmpElem->key == key) {
			return tmpElem;
		}
		tmpElem = tmpElem->next;
	}

	return nullptr;
}

/**
 * Удаляет элемент по ключу
 * @param key
 */
void Table::deleteByKey(Key key) {
	pTableElement prevElem = nullptr;
	auto tmpElem = this->head;

	while (tmpElem != nullptr) {
		if (tmpElem->key == key) {
			// если найденный элемент самый первый
			if (prevElem == nullptr) {
				tmpElem = this->head->next;
				delete this->head;
				this->head = tmpElem;
			// если элемент находится между двумя другими
			} else {
				prevElem->next = tmpElem->next;
				delete tmpElem;
			}

			break;
		}

		prevElem = tmpElem;
		tmpElem = tmpElem->next;
	}
}

/**
 * Выводит элементы таблицы на экран
 */
void Table::print() {
	pTableElement tmpElem = this->head;
	while (tmpElem != nullptr) {
		std::cout << "[" << tmpElem->key << "] => " << tmpElem->value << "; ";
		tmpElem = tmpElem->next;
	}
	std::cout << std::endl;
}

/**
 * Проверяет, есть ли элементы в таблице
 * @return
 */
bool Table::isEmpty() {
	return this->head == nullptr;
}