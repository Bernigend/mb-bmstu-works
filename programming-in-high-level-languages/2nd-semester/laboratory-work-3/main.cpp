#include <iostream>
#include "Polynomial.h"

int main() {

	double coefficients[3] {1, 2, 3};
	Polynomial polynomial1 = Polynomial(2, coefficients);

	std::cout << "1. " << polynomial1;
	std::cout << std::endl;
	std::cout << std::endl;

	// ---------------------------- //

	Polynomial polynomial2 = Polynomial(polynomial1);

	std::cout << polynomial2[2] << std::endl;
	polynomial2.at(2) = 6;
	std::cout << polynomial2[2] << std::endl;
	std::cout << "2. " << polynomial2;
	std::cout << std::endl;
	std::cout << polynomial2.calculate(2) << std::endl;
	std::cout << std::endl;

	// ---------------------------- //

	Polynomial polynomial3 = Polynomial(3, new double[4] {1, 2, 3, 4});
	std::cout << "3. " << polynomial3;
	std::cout << std::endl;
	std::cout << std::endl;

	// ---------------------------- //

	Polynomial polynomial4;

	polynomial4 = polynomial1 + polynomial3;
	std::cout << polynomial4;
	std::cout << std::endl;

	polynomial4 = polynomial3 + polynomial1;
	std::cout << polynomial4;
	std::cout << std::endl;
	std::cout << std::endl;

	// --- //

	polynomial4 = polynomial1 - polynomial3;
	std::cout << polynomial4;
	std::cout << std::endl;

	polynomial4 = polynomial3 - polynomial1;
	std::cout << polynomial4;
	std::cout << std::endl;
	std::cout << std::endl;

	// --- //

	polynomial4 = polynomial1 * polynomial3;
	std::cout << polynomial4;
	std::cout << std::endl;

	polynomial4 = polynomial3 * polynomial1;
	std::cout << polynomial4;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
