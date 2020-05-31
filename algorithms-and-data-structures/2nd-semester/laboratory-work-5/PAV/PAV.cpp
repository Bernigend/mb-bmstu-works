//
// Created by Bernigend on 31.05.2020.
//


#include <cstring>
#include "PAV.h"

PAV::PAV(const char* _statement)
{
	this->statement = new char [std::strlen(_statement)+1];
	std::strcpy(this->statement, _statement);
}

PAV::~PAV()
{
	delete [] this->statement;
}