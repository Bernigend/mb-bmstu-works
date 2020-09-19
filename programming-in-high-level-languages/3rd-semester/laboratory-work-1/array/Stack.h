//
// Created by Bernigend on 19.09.2020.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <cstddef>
#include <memory>
#include <iostream>
#include "StackExceptions.h"


namespace lab {

	template<typename Type>
	class Stack {
	protected:
		std::size_t capacity = 0;
		std::size_t numElements = 0;
		std::unique_ptr<Type[]> array;

	public:
		Stack() = default;
		~Stack() = default;

		explicit Stack(std::size_t _capacity);
		Stack(std::initializer_list<Type> list);
		Stack(const Stack& stack);

		void push(Type value);
		Type pop();
		[[nodiscard]] Type check_pop() const;

		void resize(std::size_t _capacity);

		[[nodiscard]] std::size_t size() const;
		[[nodiscard]] bool empty() const;
		void clear();

		Stack& operator= (const Stack&);
		template<typename T> friend std::ostream& operator<< (std::ostream& out, const Stack<T>& stack);
	};

}


#endif //ARRAY_STACK_H
