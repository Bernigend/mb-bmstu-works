//
// Created by Bernigend on 31.05.2020.
//

#ifndef LABORATORY_WORK_5_STACK_H
#define LABORATORY_WORK_5_STACK_H


#include "Element.h"

template< typename Type >
class Stack {
protected:
	Element<Type>* head;
	unsigned int length;

public:
	Stack();
	~Stack();

	bool empty() const;
	Type getFirst() const;
	void push(Type);
	Type pop();
};

#include "Stack.tpp"


#endif //LABORATORY_WORK_5_STACK_H