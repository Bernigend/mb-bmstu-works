//
// Created by Bernigend on 30.05.2020.
//

#ifndef LABORATORY_WORK_5_OPZ_H
#define LABORATORY_WORK_5_OPZ_H


#include <ostream>
#include "../PAV/PAV.h"
#include "../Stack/Stack.h"

class OPZ {
protected:
	char* statement;

	void initFromPAV(const PAV&);
	static bool checkWhile(char, const Stack<char>&);

public:
	explicit OPZ(const char*);
	explicit OPZ(const PAV&);
	~OPZ();

	double calculate() const;

	static int priority(char);

	friend std::ostream& operator<< (std::ostream&, const OPZ&);
};


#endif //LABORATORY_WORK_5_OPZ_H