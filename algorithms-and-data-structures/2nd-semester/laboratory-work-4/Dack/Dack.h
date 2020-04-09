//
// Created by Bernigend on 09.04.2020.
//

#include <iostream>
#include "../Queue/Queue.h"

#ifndef LABORATORY_WORK_4_DACK_H
#define LABORATORY_WORK_4_DACK_H


class Dack : public Queue {
public:
    // добавляет элемент в начало
    void add(int _value) override;

    // добавляет элемент в конец
    void addEnd(int _value);

    // возвращает элемент с конца
    pElement getEnd();
};


#endif //LABORATORY_WORK_4_DACK_H
