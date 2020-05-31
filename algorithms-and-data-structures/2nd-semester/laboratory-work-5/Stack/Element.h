//
// Created by Bernigend on 31.05.2020.
//

#ifndef LABORATORY_WORK_5_ELEMENT_H
#define LABORATORY_WORK_5_ELEMENT_H


template< typename Type >
struct Element {
	Type value;
	Element* next;

	Element();
	explicit Element(Type, Element* = NULL);
};

#include "Element.tpp"


#endif //LABORATORY_WORK_5_ELEMENT_H