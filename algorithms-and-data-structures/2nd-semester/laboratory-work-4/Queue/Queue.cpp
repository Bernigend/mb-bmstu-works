//
// Created by Bernigend on 09.04.2020.
//

#include "Queue.h"

// добавляет элемент в конец очереди
void Queue::add(int _value)
{
    auto temp = this->head;

    if (temp == nullptr) {
    this->head = new Element(_value);
    return;
    }

    while (temp->next != nullptr) {
    temp = temp->next;
    }

    temp->next = new Element(_value);
}