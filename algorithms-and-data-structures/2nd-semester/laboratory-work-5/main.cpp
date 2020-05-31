#include <iostream>
#include "OPZ/OPZ.h"

int main() {
	// создаём привычную арифметическую запись
	PAV pav = PAV("(((1+((2*(3-5))/(4+6)))/(1*2))/3)");
	std::cout << "PAV: " << pav.statement << std::endl;

	// перепишем ПАВ в обратную польскую запись
	OPZ opz = OPZ(pav);
	std::cout << "OPZ: " << opz << std::endl;

	// вычисляем ОПЗ
	std::cout << "Res: " << opz.calculate() << std::endl;
	std::cout << std::endl;

	bool canceled;
	std::cout << "Enter 0 or 1 to exit: ";
	std::cin >> canceled;

	return 0;
}