#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 14.06.2020.
//

#ifndef LABORATORY_WORK_6_LINEARLIST_H
#define LABORATORY_WORK_6_LINEARLIST_H

#include "../AV/AV.h"
#include "LinearListNode.h"


class LinearList {
protected:
	pLLNode head;

	static void toLinearList(pLLNode& node, const std::string& rawString, unsigned int& position);

public:
	LinearList();
	explicit LinearList(const AV& av);

	friend std::ostream& operator<< (std::ostream& out, const LinearList& linearList);
};


#endif //LABORATORY_WORK_6_LINEARLIST_H