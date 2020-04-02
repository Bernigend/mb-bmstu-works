/**
 * Created by Bernigend on 06.03.2020.
 */

#include "ValueOrdTable.h"

/**
 * Добавляет элемент в таблицу (сорт. по значению)
 * @param key
 * @param value
 */
void ValueOrdTable::addElement(Key key, Value value) {
	// если this->head ещё неинициализирована
	if (this->head == nullptr) {
		Table::addToStart(key, value);
		return;
	}

	auto tmpElem = this->head;
	pTableElement prevElem = nullptr;

	// ищем последний элемент, у которого значение меньше значения, переданного в метод
	while (tmpElem != nullptr) {
		if (tmpElem->value < value) {
			prevElem = tmpElem;
			tmpElem  = tmpElem->next;
			continue;
		}
		break;
	}

	// если предыдущего элемента не существует
	if (prevElem == nullptr) {
		Table::addToStart(key, value);
		return;
	}

	tmpElem = new TableElement(key, value);
	tmpElem->next = prevElem->next;

	prevElem->next = tmpElem;
}

/**
 * Алиас функции addElement
 * Не даём вставлять элементы куда попало
 * @param key
 * @param value
 */
void ValueOrdTable::addToStart(Key key, Value value) {
	this->addElement(key, value);
}

/**
 * Алиас функции addElement
 * Не даём вставлять элементы куда попало
 * @param key
 * @param value
 */
void ValueOrdTable::addToEnd(Key key, Value value) {
	this->addElement(key, value);
}