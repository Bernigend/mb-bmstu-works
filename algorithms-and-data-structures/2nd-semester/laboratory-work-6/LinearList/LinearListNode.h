#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 14.06.2020.
//

#ifndef LABORATORY_WORK_6_LINEARLISTNODE_H
#define LABORATORY_WORK_6_LINEARLISTNODE_H


#include <ostream>

#ifndef NULL
#define NULL 0
#endif

struct LinearListNode {
	bool R;
	LinearListNode* next;
	union {
		LinearListNode* level;
		char atom;
	};

	explicit LinearListNode(char _atom = '\0')
	{
		this->R     = _atom != '\0';
		this->next  = NULL;
		this->level = NULL;
		this->atom  = _atom;
	}
};

typedef LinearListNode* pLLNode;

std::ostream& operator<< (std::ostream& out, const pLLNode& linearListNode);


#endif //LABORATORY_WORK_6_LINEARLISTNODE_H