//
// Created by Bernigend on 09.04.2020.
//

#include "Dack.h"

// добавляет элемент в начало
void Dack::add(int _value)
{
    Stack::add(_value); // NOLINT(bugprone-parent-virtual-call)
}

// добавляет элемент в конец
void Dack::addEnd(int _value)
{
    Queue::add(_value);
}

// возвращает элемент с конца
pElement Dack::getEnd()
{
    auto temp = this->head;

    if (temp == nullptr) {
        return nullptr;
    }

    if (temp->next == nullptr) {
        delete this->head;
        return temp;
    }

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    auto temp2 = temp->next;
    delete temp->next;
    temp->next = nullptr;

    return temp2;
}