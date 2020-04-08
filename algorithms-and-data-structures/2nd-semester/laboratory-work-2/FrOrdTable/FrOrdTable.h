//
// Created by Bernigend on 08.04.2020.
//

#include "../Table/Table.h"

#ifndef LAB_2_FRORDTABLE_H
#define LAB_2_FRORDTABLE_H


class FrOrdTable : public Table {
public:
    /**
	 * Возвращает элемент по ключу
	 * @param key
	 * @return
	 */
    pTableElement findByKey(Key key) override;

    /**
	 * Добавляет элемент в таблицу
	 * @param key
	 * @param value
	 */
    void addElement(Key key, Value value);
};


#endif //LAB_2_FRORDTABLE_H
