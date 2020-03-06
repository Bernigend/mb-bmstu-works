/**
 * Created by Bernigend on 06.03.2020.
 */

#include "Table.h"

#ifndef LAB_2_KEYORDTABLE_H
#define LAB_2_KEYORDTABLE_H


class KeyOrdTable : public Table {
public:
	/**
	 * Добавляет элемент в таблицу (сорт. по ключу)
	 * @param key
	 * @param value
	 */
	void addElement(Key key, Value value);

	/**
	 * Алиас функции addElement
	 * Не даём вставлять элементы куда попало
	 * @param key
	 * @param value
	 */
	void addToStart(Key key, Value value) override;

	/**
	 * Алиас функции addElement
	 * Не даём вставлять элементы куда попало
	 * @param key
	 * @param value
	 */
	void addToEnd(Key key, Value value) override;
};


#endif //LAB_2_KEYORDTABLE_H
