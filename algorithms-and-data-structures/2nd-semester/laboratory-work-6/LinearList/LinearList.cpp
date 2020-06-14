#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 14.06.2020.
//

#include "LinearList.h"


// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

LinearList::LinearList() : head(NULL) {}

LinearList::LinearList(const AV& av) : head(0)
{
	unsigned int position = 0;
	LinearList::toLinearList(this->head, (std::string)(av), position);
}


// --------------------- //
// СТАТИЧЕСКИЕ МЕТОДЫ
// --------------------- //

void LinearList::toLinearList(pLLNode& node, const std::string& rawString, unsigned int& position)
{
	char symbol = rawString[position++];

	if (symbol == '(')
	{
		node = new LinearListNode();
		LinearList::toLinearList(node->level, rawString, position);
		LinearList::toLinearList(node->next, rawString, position);
	}
	else if ((symbol >= 'a' && symbol <= 'z') || symbol == '/' || symbol == '*' || symbol == '+' || symbol == '-')
	{
		node = new LinearListNode(symbol);
		LinearList::toLinearList(node->next, rawString, position);
	}
	else if (symbol == ')') node = NULL;
}


// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //

std::ostream& operator<< (std::ostream& out, const LinearList& linearList)
{
	return out << linearList.head;
}

std::ostream& operator<< (std::ostream& out, const pLLNode& linearListNode)
{
	pLLNode tmp;

	if (linearListNode != NULL) {
		if (linearListNode->R) out << linearListNode->atom;
		else {
			out << '(';

			tmp = linearListNode->level;
			while (tmp != NULL) {
				out << tmp;
				tmp = tmp->next;
			}

			out << ')';
		}
	}

	return out;
}