//
// Created by Bernigend on 19.09.2020.
//

#ifndef LABORATORY_WORK_1_STACK_H
#define LABORATORY_WORK_1_STACK_H

#include <memory>
#include <cstddef>
#include <iostream>

namespace lab {

	// структура для хранения данных об элементе стека
	template<typename Type>
	struct StackElement {
		Type value;
		std::unique_ptr<StackElement<Type>> next;

		explicit StackElement(Type);

		~StackElement() {
			std::cout << "deleted " << this->value << std::endl;
		}
	};

	// шаблонный класс стека (LIFO)
	template<typename Type>
	class Stack {
	protected:
		std::size_t numElements = 0;
		std::unique_ptr<StackElement<Type>> head;

		void push_back(Type);

	public:
		Stack() = default;
		~Stack() = default;

		// по стандарту конструктор копирования не может быть шаблоном,
		// поэтому это просто конструктор с параметром
		Stack(const Stack<Type>&);
		// конструктор со списком инициализации
//		Stack(std::initializer_list<Type>);

		// добавляет элемент в стек
		void push(Type);
		// изымает элемент из стека (возвращает значение и удаляет элемент)
		Type pop();
		// проверяет, можно ли изъять элемент
		[[nodiscard]] Type check_pop() const;

		// возвращает количество элементов стека
		[[nodiscard]] std::size_t size() const;
		// возвращает пустой ли стек
		[[nodiscard]] bool empty() const;
		// удаляет все элементы стека
		void clear();

		// копирует стек в новую переменную
		Stack& operator= (const Stack&);
		// перенаправление вывода
		template<typename T> friend std::ostream& operator<< (std::ostream&, const Stack<T>&);
	};

}

#endif //LABORATORY_WORK_1_STACK_H
