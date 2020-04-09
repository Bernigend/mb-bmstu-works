//
// Created by Bernigend on 09.04.2020.
//

#include "Stack.h"

// пустой ли стэк
bool Stack::isEmpty()
{
    return this->head == nullptr;
}

// возвращает значение первого элемента
pElement Stack::getFirst()
{
    return this->head;
}

// извлекает первый элемент
pElement Stack::get()
{
    if (this->head == nullptr) {
        return nullptr;
    }

    auto temp = this->head;
    this->head = this->head->next;

    return temp;
}

// добавляет элемент в начало
void Stack::add(int _value)
{
    auto temp = new Element(_value);
    temp->next = this->head;
    this->head = temp;
}

// оператор вывода
std::ostream& operator<< (std::ostream& stream, const Stack& stack)
{
    auto temp = stack.head;
    while (temp != nullptr) {
        stream << temp->value << " ";
        temp = temp->next;
    }
    return stream;
}