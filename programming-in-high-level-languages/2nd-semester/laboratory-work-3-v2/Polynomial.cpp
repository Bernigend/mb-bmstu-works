/**
 * Created by Bernigend on 01.05.2020.
 */

#include "Polynomial.h"

// ----------------------------------- //
// КОНСТРУКТОРЫ
// ----------------------------------- //

Polynomial::Polynomial() = default;

Polynomial::Polynomial(const double* _coefficients, unsigned int num) : coefficients(num)
{
	if (_coefficients == nullptr) {
		return;
	}

	for (int i = 0; i < num; i++) {
		this->coefficients[num - i - 1] = _coefficients[i];
//		std::cout << num - i - 1 << " - " << _coefficients[i] << " - " << this->coefficients[num - i - 1] << std::endl;
	}
}

Polynomial::Polynomial(const std::initializer_list<double>& _coefficients) : coefficients(_coefficients.size())
{
	unsigned int size = _coefficients.size();
	if (size < 1) {
		return;
	}

	int i = 0;
	for (auto coefficient : _coefficients) {
		this->coefficients[size - i - 1] = coefficient;
//		std::cout << size - i - 1 << " - " << coefficient << " - " << this->coefficients[size - i - 1] << std::endl;
		i++;
	}
}

Polynomial::~Polynomial()
{
	this->coefficients.clear();
}


// ----------------------------------- //
// ОПЕРАТОРЫ ВВОДА/ВЫВОДА
// ----------------------------------- //

std::ostream& operator<< (std::ostream& out, const Polynomial& polynomial)
{
	int size = polynomial.coefficients.size();

	for (int i = size - 1; i >= 0; i--) {
		auto coefficient = polynomial.coefficients[i];
		if (coefficient == 0) continue;

		if (i != size - 1) {
			out << ((coefficient < 0) ? " - " : " + ");
		}
		out << ((coefficient < 0) ? -coefficient : coefficient);
		if (i != 0) {
			out << "x^" << i;
		}
	}

	return out;
}

std::istream& operator>> (std::istream& in, Polynomial& polynomial)
{
	int num;
	in >> num;

	std::vector<double> coefficients(num);
	for (int i = 0; i < num; i++) {
		in >> coefficients[num - i - 1];
	}

	polynomial.coefficients = coefficients;
	return in;
}