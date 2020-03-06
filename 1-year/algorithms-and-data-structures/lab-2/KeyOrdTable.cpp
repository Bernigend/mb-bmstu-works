/**
 * Created by Bernigend on 06.03.2020.
 */

#include "KeyOrdTable.h"

/**
 * Добавляет элемент в таблицу (сорт. по ключу)
 * @param key
 * @param value
 */
void KeyOrdTable::addElement(Key key, Value value) {
	// если this->head ещё неинициализирована
	if (this->head == nullptr) {
		Table::addToStart(key, value);
		return;
	}

	auto tmpElem = this->head;
	pTableElement prevElem = nullptr;

	// ищем последний элемент, у которого ключ меньше ключа, переданного в метод
	while (tmpElem != nullptr) {
		if (tmpElem->key < key) {
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
void KeyOrdTable::addToStart(Key key, Value value) {
	this->addElement(key, value);
}

/**
 * Алиас функции addElement
 * Не даём вставлять элементы куда попало
 * @param key
 * @param value
 */
void KeyOrdTable::addToEnd(Key key, Value value) {
	this->addElement(key, value);
}