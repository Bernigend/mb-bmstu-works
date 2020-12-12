//
// Created by bernigend on 07.12.2020.
//

#ifndef LABORATORY_WORK_2_QUEUE_H
#define LABORATORY_WORK_2_QUEUE_H

#include <memory>
#include <ostream>

namespace lab {

    template<typename T>
    struct _queueElement {
        T _value;
        std::unique_ptr<_queueElement<T>> _next{};

        explicit _queueElement(T);
    };

    template<typename T>
    class Queue {
    protected:
        std::size_t _numElements = 0;
        std::unique_ptr<_queueElement<T>> _head;

    public:
        Queue() = default;
        ~Queue() = default;

        Queue(const Queue<T>&);
        Queue(std::initializer_list<T>);
        Queue(Queue<T>&&) noexcept;

        void push(T);
        T pop();
        [[nodiscard]] T check_pop() const;

        [[nodiscard]] std::size_t size() const noexcept;
        [[nodiscard]] bool empty() const noexcept;
        void clean();

        Queue<T>& operator= (const Queue<T>&);

        template<typename Type>
        friend std::ostream& operator<< (std::ostream&, const Queue<Type>&);
    };
}

#include "Queue.hpp"

#endif //LABORATORY_WORK_2_QUEUE_H
