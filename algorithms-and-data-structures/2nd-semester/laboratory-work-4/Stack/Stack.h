//
// Created by Bernigend on 09.04.2020.
//

#include "ostream"
#include "../Element.h"

#ifndef LABORATORY_WORK_4_STACK_H
#define LABORATORY_WORK_4_STACK_H


class Stack {
protected:
    pElement head = nullptr;

public:
    // пустой ли стэк
    bool isEmpty();

    // возвращает значение первого элемента
    pElement getFirst();

    // извлекает первый элемент
    pElement get();

    // добавляет элемент в начало
    virtual void add(int _value);

    // оператор вывода
    friend std::ostream& operator<< (std::ostream& stream, const Stack& stack);
};


#endif //LABORATORY_WORK_4_STACK_H
