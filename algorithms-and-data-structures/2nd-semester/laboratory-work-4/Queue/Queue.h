//
// Created by Bernigend on 09.04.2020.
//

#include "../Stack/Stack.h"

#ifndef LABORATORY_WORK_4_QUEUE_H
#define LABORATORY_WORK_4_QUEUE_H


class Queue : public Stack {
public:
    // добавляет элемент в конец очереди
    void add(int _value) override;
};


#endif //LABORATORY_WORK_4_QUEUE_H
