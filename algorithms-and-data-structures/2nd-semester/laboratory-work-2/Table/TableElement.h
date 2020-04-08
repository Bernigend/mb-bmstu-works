/**
 * Created by Bernigend on 28.02.2020.
 */

#ifndef LAB_2_TABLEELEMENT_H
#define LAB_2_TABLEELEMENT_H

typedef int Key;
typedef int Value;

struct TableElement;
typedef TableElement* pTableElement;

struct TableElement {
	Key key = 0;
	Value value = 0;
	pTableElement next = nullptr;

	TableElement(Key key, Value value) {
		this->key   = key;
		this->value = value;
	}
};

#endif //LAB_2_TABLEELEMENT_H
