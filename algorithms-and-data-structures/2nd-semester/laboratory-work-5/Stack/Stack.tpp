//
// Created by Bernigend on 31.05.2020.
//

#include "Stack.h"

// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

template< typename Type >
Stack<Type>::Stack() : head(NULL), length(0) {}

template< typename Type >
Stack<Type>::~Stack()
{
	Element<Type>* temp     = this->head;
	Element<Type>* toDelete = NULL;

	while (temp != NULL) {
		toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
}

// --------------------- //
// МЕТОДЫ
// --------------------- //

template< typename Type >
bool Stack<Type>::empty() const
{
	return this->head == NULL;
}

template< typename Type >
Type Stack<Type>::getFirst() const
{
	return (this->head == NULL) ? '\0' : this->head->value;
}

template< typename Type >
void Stack<Type>::push(Type value)
{
	this->head = new Element<Type>(value, this->head);
	this->length++;
}

template< typename Type >
Type Stack<Type>::pop()
{
	if (this->head == NULL) return '\0';

	Element<Type>* toDelete = this->head;
	Type result = this->head->value;
	this->head  = this->head->next;

	this->length--;
	delete toDelete;
	return result;
}