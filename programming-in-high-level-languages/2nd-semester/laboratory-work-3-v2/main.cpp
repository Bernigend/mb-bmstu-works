#include <iostream>
#include "Polynomial.h"

int main() {

	// ------------------------------- //

	Polynomial polynomial1 = Polynomial(new double[3] {1, 2, 3}, 3);
	std::cout << "1. " << polynomial1 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial2 {1, 2, 3};
	std::cout << "2. " << polynomial2 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial3;
	std::cout << "Enter polynomial:" << std::endl;
	std::cin >> polynomial3;
	std::cout << std::endl;
	std::cout << "3. " << polynomial3 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //



	return 0;
}
