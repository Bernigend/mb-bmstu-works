#include <iostream>
#include "Polynomial.h"

int main() {

	// ------------------------------- //

	Polynomial polynomial1 = Polynomial(new double[3] {1, 2, 3}, 3);
	std::cout << "1.   " << polynomial1 << std::endl;
	std::cout << "Ans: " << polynomial1.calculate(2) << std::endl;
	std::cout << "[0]: " << polynomial1[0] << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial2 {1, -2, 3, 4};
	std::cout << "2.   " << polynomial2 << std::endl;
	std::cout << "Ans: " << polynomial2.calculate(2) << std::endl;
	std::cout << "[2]: " << polynomial2.at(2) << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial3 {3, 2, 1};
	std::cout << "2.   " << polynomial3 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	std::cout << "1 + 2 | " << polynomial1 + polynomial2 << std::endl;
	std::cout << "2 + 1 | " << polynomial2 + polynomial1 << std::endl;
	std::cout << "1 + 3 | " << polynomial1 + polynomial3 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	std::cout << "1 - 2 | " << polynomial1 - polynomial2 << std::endl;
	std::cout << "2 - 1 | " << polynomial2 - polynomial1 << std::endl;
	std::cout << "1 - 3 | " << polynomial1 - polynomial3 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	std::cout << "1 * 2 | " << polynomial1 * polynomial2 << std::endl;
	std::cout << "2 * 1 | " << polynomial2 * polynomial1 << std::endl;
	std::cout << "1 * 3 | " << polynomial1 * polynomial3 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial test1 {1, 2, 3, 4};
	Polynomial test2 {1, 2, 3};

	std::cout << "1 / 2 | " << Polynomial::DivPolynomial(&test1, &test2) << std::endl;
	std::cout << std::endl;

//	Polynomial polynomial3;
//	std::cout << "Enter polynomial:" << std::endl;
//	std::cin >> polynomial3;
//	std::cout << std::endl;
//	std::cout << "3. " << polynomial3 << std::endl;
//	std::cout << std::endl;

	// ------------------------------- //



	return 0;
}
