//
// Created by bernigend on 07.12.2020.
//

#ifndef LABORATORY_WORK_2_CONVERTER_H
#define LABORATORY_WORK_2_CONVERTER_H

#include "Queue/Queue.h"
#include "Stack/Stack.h"

namespace lab {

    class Converter {
    public:

        /**
         * Создаёт стек из копии очереди
         * @tparam T
         * @param queue
         * @return
         */
        template<typename T>
        static Stack<T>& queueToStack(const Queue<T>& queue)
        {
            auto newStack = new Stack<T>(queue.size());
            auto tmpQueue = Queue<T>(queue);

            while (!tmpQueue.empty()) {
                newStack->push(tmpQueue.pop());
            }

            return *newStack;
        }

        /**
         * Создаёт очередь из копии стека
         * @tparam T
         * @param stack
         * @return
         */
        template<typename T>
        static Queue<T>& stackToQueue(const Stack<T>& stack)
        {
            auto newQueue = new Queue<T>();
            auto tmpStack = Stack<T>(stack);

            while (!tmpStack.empty()) {
                newQueue->push(tmpStack.pop());
            }

            return *newQueue;
        }
    };

}

#endif //LABORATORY_WORK_2_CONVERTER_H
