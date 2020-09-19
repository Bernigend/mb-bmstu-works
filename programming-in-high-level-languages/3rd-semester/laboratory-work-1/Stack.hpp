#include "Stack.h"
#include "StackExceptions.h"

namespace lab {

	/**
	 * Конструктор с параметрами элемента стека.
	 *
	 * @tparam Type тип данных стека
	 * @param _value значение типа Type
	 */
	template<typename Type>
	StackElement<Type>::StackElement(Type _value)
	{
		this->value = _value;
	}

	template<typename Type>
	Stack<Type>::Stack(const Stack<Type>& stack)
	{
		StackElement<Type>* tmp = stack.head.get();

		while(tmp != nullptr) {
			this->push_back(tmp->value);
			tmp = tmp->next.get();
		}
	}

	/**
	 * Добавляет элемент в стек.
	 *
	 * @tparam Type тип данных стека
	 * @param value значение типа Type
	 */
	template<typename Type>
	void Stack<Type>::push(Type value)
	{
		if (!this->head) {
			this->head = std::make_unique<StackElement<Type>>(value);
			this->numElements++;
			return;
		}

		auto tmp = new StackElement<Type>(value);
		tmp->next = std::move(this->head);
		this->head = std::unique_ptr<StackElement<Type>>(tmp);
		this->numElements++;
	}

	/**
	 * Добавляет элемент в конец стека.
	 *
	 * @tparam Type тип данных стека
	 * @param value значение типа Type
	 */
	template<typename Type>
	void Stack<Type>::push_back(Type value)
	{
		if (!this->head) {
			this->push(value);
			return;
		}

		auto tmp = new StackElement<Type>(value);
		auto cur = this->head.get();

		while (cur->next != nullptr) {
			cur = cur->next.get();
		}

		cur->next = std::unique_ptr<StackElement<Type>>(tmp);
	}

	/**
	 * Изымает последний добавленный элемент из стека (последний добавленный изымается первым).
	 *
	 * @tparam Type тип данных стека
	 * @return значение элемента стека типа Type
	 */
	template<typename Type>
	Type Stack<Type>::pop()
	{
		if (!this->head) {
			throw PopOutOfRange();
		}

		auto toRemove = std::move(this->head);
		this->head = std::move(toRemove->next);
		this->numElements--;

		return toRemove->value;
	}

	/**
	 * Проверяет, существует ли элемент для изъятия.
	 *
	 * @tparam Type тип данных стека
	 * @return true, если значение существует, иначе - false
	 */
	template<typename Type>
	Type Stack<Type>::check_pop() const
	{
		if (!this->head) {
			throw PopOutOfRange();
		}

		return this->head->value;
	}

	/**
	 * Возвращает количество элементов в стеке.
	 *
	 * @tparam Type тип данных стека
	 * @return количество элементов
	 */
	template<typename Type>
	std::size_t Stack<Type>::size() const
	{
		return this->numElements;
	}

	/**
	 * Проверяет, существует ли элемент для изъятия (пустой стек или нет).
	 *
	 * @tparam Type тип данных стека
	 * @return true, если элемент существует, иначе - false
	 */
	template<typename Type>
	bool Stack<Type>::empty() const
	{
		return static_cast<bool>(this->head);
	}

	/**
	 * Удаляет все элементы стека.
	 *
	 * @tparam Type тип данных стека
	 */
	template<typename Type>
	void Stack<Type>::clear()
	{
		if (!this->head) return;
		auto toRemove = std::move(this->head);
		this->numElements = 0;
	}

	/**
	 * Выводит все элементы стека.
	 *
	 * @tparam Type тип данных стека
	 * @param out поток вывода
	 * @param stack стек для вывода элементов
	 * @return поток вывода
	 */
	template<typename Type>
	std::ostream& operator<< (std::ostream& out, const Stack<Type>& stack)
	{
		StackElement<Type>* tmp = stack.head.get();

		while(tmp != nullptr) {
			out << tmp->value << " ";
			tmp = tmp->next.get();
		}

		return out;
	}



}