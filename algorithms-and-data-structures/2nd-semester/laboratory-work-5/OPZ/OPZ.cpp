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
	this->statement = NULL;
	this->initFromPAV(pav);
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

bool OPZ::checkWhile(char symbol, const Stack<char>& stack) {
	if (symbol == ')')
		return stack.getFirst() != '(';
	else
		return OPZ::priority(stack.getFirst()) > OPZ::priority(symbol);
}

void OPZ::initFromPAV(const PAV& pav)
{
	this->statement = new char [std::strlen(pav.statement)];

	unsigned int position = 0;
	Stack<char> stack;

	for (unsigned int i = 0; i < std::strlen(pav.statement); i++) {
		char symbol = pav.statement[i];

		if (symbol == '(') stack.push(symbol);
		else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == ')')
		{
			while (!stack.empty() && checkWhile(symbol, stack)) {
				this->statement[position] = stack.pop();
				position++;
			}
			if (symbol == ')') stack.pop(); else stack.push(symbol);
		}
		else
		{
			this->statement[position] = symbol;
			position++;
		}
	}

	while (!stack.empty()) {
		this->statement[position] = stack.pop();
		position++;
	}

	this->statement[position] = '\0';
}

// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //

std::ostream& operator<< (std::ostream& out, const OPZ& opz)
{
	out << opz.statement;
	return out;
}