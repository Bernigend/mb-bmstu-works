//
// Created by Bernigend on 31.05.2020.
//

#include "Element.h"

template< typename Type >
Element<Type>::Element()
{
	this->value = '\0';
	this->next  = NULL;
}

template< typename Type >
Element<Type>::Element(Type _value, Element* _next)
{
	this->value = _value;
	this->next  = _next;
}