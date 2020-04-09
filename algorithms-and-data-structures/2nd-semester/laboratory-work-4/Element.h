//
// Created by Bernigend on 09.04.2020.
//

#ifndef LABORATORY_WORK_4_ELEMENT_H
#define LABORATORY_WORK_4_ELEMENT_H


struct Element {
    int value {};
    Element* next = nullptr;

    explicit Element(int _value) {
        this->value = _value;
    }
};

typedef Element* pElement;

#endif //LABORATORY_WORK_4_ELEMENT_H
