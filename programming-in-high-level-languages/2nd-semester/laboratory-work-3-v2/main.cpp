#include <iostream>
#include "Polynomial.h"

int main() {

	// ------------------------------- //

	Polynomial polynomial1 = Polynomial(new double[3] {1, 2, 3}, 3);
	std::cout << "1.   " << polynomial1              << std::endl;
	std::cout << "Ans: " << polynomial1.calculate(2) << std::endl;
	std::cout << "[0]: " << polynomial1[0]           << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial2 {1, -2, 3, 4};
	std::cout << "2.   " << polynomial2              << std::endl;
	std::cout << "Ans: " << polynomial2.calculate(2) << std::endl;
	std::cout << "[2]: " << polynomial2.at(2)        << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomial3 {3, 2, 1};
	std::cout << "3.   " << polynomial3 << std::endl;
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

	Polynomial polynomial4 {1, 2, 3, 4};
	std::cout << "4.   " << polynomial4 << std::endl;
	std::cout << std::endl;

	Polynomial polynomial5 {1, 2, 3};
	std::cout << "5.   " << polynomial5 << std::endl;
	std::cout << std::endl;

	// --- //

	std::cout << "4 / 5 | " << polynomial4 / polynomial5 << std::endl;
	std::cout << "1 % 2 | " << polynomial4 % polynomial5 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomialTemp;

	polynomialTemp = polynomial1;
	std::cout << "1 += 3 | " << (polynomialTemp += polynomial3) << std::endl;

	polynomialTemp = polynomial1;
	std::cout << "1 -= 3 | " << (polynomialTemp -= polynomial3) << std::endl;

	polynomialTemp = polynomial1;
	std::cout << "1 *= 3 | " << (polynomialTemp *= polynomial3) << std::endl;

	polynomialTemp = polynomial4;
	std::cout << "4 /= 5 | " << (polynomialTemp /= polynomial5) << std::endl;

	polynomialTemp = polynomial4;
	std::cout << "4 %= 5 | " << (polynomialTemp %= polynomial5) << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	double x1[] {-2}; Polynomial b (x1, 1);
	Polynomial test1 = Polynomial(x1, 1);

	std::cout << "test1 | " << test1 << std::endl;
	std::cout << std::endl;

	// --- //

	std::cout << "1 / test1 | " << polynomial1 / test1 << std::endl;
	std::cout << "test1 / 1 | " << test1 / polynomial1 << std::endl;
	std::cout << "1 % test1 | " << polynomial1 % test1 << std::endl;
	std::cout << "test1 % 1 | " << test1 % polynomial1 << std::endl;
	std::cout << std::endl;

	// ------------------------------- //

	Polynomial polynomialIn;
	std::cout << "Enter polynomial:" << std::endl;
	std::cin >> polynomialIn;
	std::cout << std::endl;
	std::cout << "In.  " << polynomialIn << std::endl;
	std::cout << std::endl;

	return 0;
}
