//
// Created by Bernigend on 08.04.2020.
//

#include "FrOrdTable.h"

pTableElement FrOrdTable::findByKey(Key key)
{
    pTableElement p  = this->head;
    pTableElement p1 = this->head;

    while ((p != nullptr) && (p->key != key)) {
        p1 = p;
        p = p->next;
    }

    if ((p != this->head) && (p != nullptr)) {
        p1->next = p->next;
        p->next = this->head;
        this->head = p;
    }

    return p;
}

void FrOrdTable::addElement(Key key, Value value)
{
    this->addToEnd(key, value);
}