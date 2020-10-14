//
// Created by Bernigend on 19.09.2020.
//

#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Stack.h"


namespace lab {

	/**
	 * Конструктор с указанием вместительности стека.
	 *
	 * @tparam Type
	 * @param _capacity
	 */
	template<typename Type>
	Stack<Type>::Stack(std::size_t _capacity) : capacity(_capacity)
	{
		if (_capacity <= 0) throw bad_stack_capacity();
		this->array = std::make_unique<Type[]>(_capacity);
	}

	/**
	 * Конструктор со списком инициализации.
	 *
	 * @tparam Type
	 * @param list
	 */
	template<typename Type>
	Stack<Type>::Stack(std::initializer_list<Type> list) : Stack(list.size())
	{
		for (Type item : list) this->push(item);
	}

	/**
	 * Конструктор с параметром (не копирования - по стандарту он не может быть шаблоном?)
	 *
	 * @tparam Type
	 * @param stack
	 */
	template<typename Type>
	Stack<Type>::Stack(const Stack& stack) : Stack(stack.capacity)
	{
		for (std::size_t i = 0; i < stack.numElements; i++) {
			this->push(stack.array[i]);
		}
	}

	/**
	 * Добавляет значение в стек.
	 *
	 * @tparam Type
	 * @param value
	 */
	template<typename Type>
	void Stack<Type>::push(Type value)
	{
		if (this->numElements >= this->capacity) this->resize(this->capacity + 8);
		this->array[this->numElements] = value;
		this->numElements += 1;
	}

	/**
	 * Возвращает значение и удаляет его из стека (последний добавленный изымается первым, LIFO).
	 *
	 * @tparam Type
	 * @return
	 */
	template<typename Type>
	Type Stack<Type>::pop() {
		if (this->empty()) throw pop_out_of_index();

		this->numElements -= 1;
		Type tmp = this->array[this->numElements];
		if (this->numElements == 0) this->clear();

		return tmp;
	}

	/**
	 * Возвращает значение, не удаляя его из стека
	 *
	 * @tparam Type
	 * @return
	 */
	template<typename Type>
	Type Stack<Type>::check_pop() const {
		if (this->empty()) throw pop_out_of_index();
		return this->array[this->numElements];
	}

	/**
	 * Изменяет вместительность стека.
	 *
	 * @tparam Type
	 * @param _capacity
	 */
	template<typename Type>
	void Stack<Type>::resize(std::size_t _capacity)
	{
		this->capacity = _capacity;

		if (this->numElements > this->capacity) {
			this->numElements = this->capacity;
		}

		auto tmp = std::move(this->array);
		this->array = std::make_unique<Type[]>(this->capacity);

		std::copy(tmp.get(), tmp.get()+this->numElements, this->array.get());
	}

	/**
	 * Возвращает количество значений в стеке.
	 *
	 * @tparam Type
	 * @return
	 */
	template<typename Type>
	std::size_t Stack<Type>::size() const {
		return this->numElements;
	}

	/**
	 * Возвращает, пустой ли стек.
	 *
	 * @tparam Type
	 * @return
	 */
	template<typename Type>
	bool Stack<Type>::empty() const {
		return !static_cast<bool>(this->array);
	}

	/**
	 * Очищает стек от всех значений.
	 *
	 * @tparam Type
	 */
	template<typename Type>
	void Stack<Type>::clear() {
		if (this->empty()) return;
		this->numElements = 0;
	}

	/**
	 * Копирует стек в новую переменную.
	 *
	 * @tparam Type
	 * @param stack
	 * @return
	 */
	template<typename Type>
	Stack<Type>& Stack<Type>::operator= (const Stack<Type>& stack)
	{
		if (this == &stack) return *this;
		*this = Stack(stack);
		return *this;
	}

	/**
	 * Перегрузка оператора вывода.
	 *
	 * @tparam Type
	 * @param out
	 * @param stack
	 * @return
	 */
	template<typename Type>
	std::ostream& operator<< (std::ostream& out, const Stack<Type>& stack)
	{
		out << stack.numElements << " of " << stack.capacity << ": ";
		for (std::size_t i = 0; i < stack.size(); i++)
			out << stack.array[i] << " ";
		return out;
	}

}

#endif //ARRAY_STACK_HPP