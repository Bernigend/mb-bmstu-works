#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 30.05.2020.
//

#include <cstring>
#include "OPZ.h"

// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

OPZ::OPZ(const char* _statement)
{
	this->statement = new char [std::strlen(_statement)+1];
	std::strcpy(this->statement, _statement);
}

OPZ::OPZ(const PAV& pav)
{
	this->statement = new char [std::strlen(pav.statement)+1];
	std::strcpy(this->statement, pav.statement);
	this->initFromPAV();
}

OPZ::~OPZ()
{
	delete [] this->statement;
}

// --------------------- //
// МЕТОДЫ
// --------------------- //

int OPZ::priority(char sign)
{
	if (sign == '*' || sign == '/') return 2;
	if (sign == '+' || sign == '-') return 1;
	return 0;
}

double OPZ::calculate() const
{
	Stack<double> stack;

	for (unsigned int i = 0; i < std::strlen(this->statement); i++) {
		char symbol = this->statement[i];

		if (symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/')
		{
			double b = stack.pop();
			double a = stack.pop();

			switch (symbol) {
				case '-': stack.push(a - b); break;
				case '+': stack.push(a + b); break;
				case '*': stack.push(a * b); break;
				case '/': stack.push(a / b); break;
			}
		}
		else if (symbol >= '0' && symbol <= '9')
		{
			stack.push((double)(symbol - '0'));
		}
	}

	return stack.pop();
}

void OPZ::initFromPAV()
{
	if (this->statement == NULL) return;

	unsigned int p = 0;
	char* tmp = new char [std::strlen(this->statement)];
	Stack<char> stack;

	for(unsigned int i = 0; i < std::strlen(this->statement); i++) {
		char symbol = this->statement[i];

		if (symbol == '(')
		{
			stack.push(symbol);
		}
		else if (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*')
		{
			while (!stack.empty() && OPZ::priority(stack.getFirst()) > OPZ::priority(symbol)) {
				tmp[p] = stack.pop();
				p++;
			}
			stack.push(symbol);
		}
		else if (symbol == ')')
		{
			while (!stack.empty() && stack.getFirst() != '(') {
				tmp[p] = stack.pop();
				p++;
			}
			stack.pop();
		}
		else
		{
			tmp[p] = symbol;
			p++;
		}
	}

	while(!stack.empty()) {
		tmp[p] = stack.pop();
		p++;
	}

	delete [] this->statement;
	this->statement = tmp;
}

// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //

std::ostream& operator<< (std::ostream& out, const OPZ& opz)
{
	out << opz.statement;
	return out;
}