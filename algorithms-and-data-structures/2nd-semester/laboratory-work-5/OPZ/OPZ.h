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

	void initFromPAV();
	static int priority(char);

public:
	explicit OPZ(const char*);
	explicit OPZ(const PAV&);
	~OPZ();

	double calculate() const;

	friend std::ostream& operator<< (std::ostream&, const OPZ&);
};


#endif //LABORATORY_WORK_5_OPZ_H