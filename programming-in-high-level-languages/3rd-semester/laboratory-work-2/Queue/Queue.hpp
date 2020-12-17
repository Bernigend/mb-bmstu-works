#include "Queue.h"
#include "QueueExceptions.h"

namespace lab {

    /**
     * Конструктор с параметром для элемента очереди
     * @tparam T
     * @param _value
     */
    template<typename T>
    _queueElement<T>::_queueElement(T _value) : _value(_value) {}

    /**
     * Конструктор копирования (или просто с параметром, если ориентироваться на какую-то статью)
     * @tparam T
     * @param queue
     */
    template<typename T>
    Queue<T>::Queue(const Queue<T> &queue)
    {
        _queueElement<T>* tmp = queue._head.get();

        while (tmp != nullptr) {
            this->push(tmp->_value);
            tmp = tmp->_next.get();
        }
    }

    /**
     * Конструктор со списком инициализации
     * @tparam T
     * @param list
     */
    template<typename T>
    Queue<T>::Queue(std::initializer_list<T> list)
    {
        for (T item : list) {
            this->push(item);
        }
    }

    /**
     * Конструктор перемещения
     * @tparam T
     * @param queue
     */
    template<typename T>
    Queue<T>::Queue(Queue<T> &&queue) noexcept
    {
        this->_head = std::move(queue._head);
        queue._head = nullptr;
    }

    /**
     * Конструктор из объекта Stack
     * @tparam T
     * @param stack
     */
	template<typename T>
	Queue<T>::Queue(const Stack<T>& stack)
	{
		auto tmpStack = Stack<T>(stack);

		while (!tmpStack.empty()) {
			this->push(tmpStack.pop());
		}
	}

    /**
     * Добавляет элемент в конец очереди
     * @tparam T
     * @param value
     */
    template<typename T>
    void Queue<T>::push(T value)
    {
        if (!this->_head) {
            this->_head = std::make_unique<_queueElement<T>>(value);
            this->_numElements++;
            return;
        }

        auto tmp = new _queueElement<T>(value);
        auto cur = this->_head.get();

        while (cur->_next != nullptr) {
            cur = cur->_next.get();
        }

        cur->_next = std::unique_ptr<_queueElement<T>>(tmp);
        this->_numElements++;
    }

    /**
     * Изымает следущий на очереди элемент очереди (последний зашёл -> последний вышел)
     * @tparam T
     * @return
     */
    template<typename T>
    T Queue<T>::pop()
    {
        if (!this->_head) {
            throw PopOutOfRange();
        }

        auto toRemove = std::move(this->_head);
        this->_head = std::move(toRemove->_next);
        this->_numElements -= 1;

        return toRemove->_value;
    }

    /**
     * Проверяет наличие элемента для изъятия
     * @tparam T
     * @return
     */
    template<typename T>
    T Queue<T>::check_pop() const
    {
        if (!this->_head) {
            throw PopOutOfRange();
        }

        return this->_head->_value;
    }

    /**
     * Возвращает количество элементов
     * @tparam T
     * @return
     */
    template<typename T>
    std::size_t Queue<T>::size() const noexcept
    {
        return this->_numElements;
    }

    /**
     * Возвращает не пустая ли очередь
     * @tparam T
     * @return true - пустая
     */
    template<typename T>
    bool Queue<T>::empty() const noexcept
    {
        return static_cast<bool>(!this->_head);
    }

    /**
     * Очищает очередь от элементов
     * @tparam T
     */
    template<typename T>
    void Queue<T>::clean()
    {
        if (!this->_head) return;
        auto toRemove = std::move(this->_head);
        this->_numElements = 0;
    }

    /**
	 * Оператор присваивания (копирования).
	 * Полностью копирует очередь в новую пременную.
	 *
	 * @tparam T
	 * @param queue
	 * @return
	 */
    template<typename T>
    Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
    {
        if (this == &queue) return *this;

        auto tmp = Queue<T>(queue);
        this->_head = std::move(tmp._head);

        return *this;
    }

    /**
	 * Выводит все элементы очереди.
	 *
	 * @tparam Type тип данных стека
	 * @param out поток вывода
	 * @param stack стек для вывода элементов
	 * @return поток вывода
	 */
    template<typename Type>
    std::ostream& operator<< (std::ostream& out, const Queue<Type>& queue)
    {
        _queueElement<Type>* tmp = queue._head.get();

        while(tmp != nullptr) {
            out << tmp->_value << " ";
            tmp = tmp->_next.get();
            if (tmp) {
                out << "<- ";
            }
        }

        return out;
    }
}