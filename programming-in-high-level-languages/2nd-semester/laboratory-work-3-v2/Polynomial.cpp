/**
 * Created by Bernigend on 01.05.2020.
 */

#include <cmath>
#include "Polynomial.h"

// ----------------------------------- //
// КОНСТРУКТОРЫ
// ----------------------------------- //

Polynomial::Polynomial() = default;

Polynomial::Polynomial(unsigned int num) : coefficients(num) {}

Polynomial::Polynomial(const double* _coefficients, unsigned int num) : coefficients(num)
{
	if (_coefficients == nullptr) {
		return;
	}

	for (int i = 0; i < num; i++) {
		this->coefficients[num - i - 1] = _coefficients[i];
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
		i++;
	}
}

Polynomial::Polynomial(const Polynomial& polynomial)
{
	this->coefficients = polynomial.coefficients;
}

Polynomial::~Polynomial()
{
	this->coefficients.clear();
}


// ----------------------------------- //
// ПЕРЕГРУЗКА АРИФ. ОПЕРАТОРОВ
// ----------------------------------- //

Polynomial Polynomial::operator+ (const Polynomial& other)
{
	unsigned int size1 = this->coefficients.size(),
	             size2 = other.coefficients.size();
	Polynomial result;

	if (size1 >= size2) {
		result = Polynomial(*this);
		for (unsigned int i = 0; i < size2; i++) {
			result[i] += other.coefficients.at(i);
		}
	} else {
		result = Polynomial(other);
		for (unsigned int i = 0; i < size1; i++) {
			result[i] += this->coefficients.at(i);
		}
	}

	return result;
}

Polynomial Polynomial::operator-(const Polynomial& other)
{
	unsigned int size1 = this->coefficients.size(),
	             size2 = other.coefficients.size();
	Polynomial result;

	if (size1 >= size2) {
		result = Polynomial(*this);
		for (unsigned int i = 0; i < size2; i++) {
			result[i] -= other.coefficients.at(i);
		}
	} else {
		result = Polynomial(other);
		for (unsigned int i = 0; i < size2; i++) {
			result[i] = -result[i];
		}
		result = *this + result;
	}

	return result;
}

Polynomial Polynomial::operator* (const Polynomial& other)
{
	unsigned int size1 = this->coefficients.size(),
			     size2 = other.coefficients.size();
	Polynomial temp = Polynomial(size1 + size2);

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			temp.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
		}
	}

	return temp;
}

Polynomial Polynomial::operator/ (const Polynomial& other)
{
	return Polynomial::DivPolynomial(*this, other);
}

Polynomial Polynomial::operator% (const Polynomial& other)
{
	return Polynomial::DivPolynomial(*this, other, true);
}

Polynomial Polynomial::operator+= (const Polynomial& other)
{
	*this = *this + other;
	return *this;
}

Polynomial Polynomial::operator-= (const Polynomial& other)
{
	*this = *this - other;
	return *this;
}

Polynomial Polynomial::operator*= (const Polynomial& other)
{
	*this = *this * other;
	return *this;
}

Polynomial Polynomial::operator/= (const Polynomial& other)
{
	*this = *this / other;
	return *this;
}

Polynomial Polynomial::operator%= (const Polynomial& other)
{
	*this = *this % other;
	return *this;
}


// ----------------------------------- //
// МЕТОД ВЫЧИСЛЕНИЯ ЗНАЧЕНИЯ
// ----------------------------------- //

double Polynomial::calculate(double x)
{
	double result {0};
	unsigned int i = 0;

	for (auto coefficient : this->coefficients) {
		result += std::pow(x, i) * coefficient;
		i++;
	}

	return result;
}


// ----------------------------------- //
// ПЕРЕГРУЗКА [] и at()
// ----------------------------------- //

double& Polynomial::operator[](unsigned int degree)
{
	return this->coefficients[degree];
}

double Polynomial::at(unsigned int degree)
{
	return this->coefficients.at(degree);
}


// ----------------------------------- //
// ОПЕРАТОРЫ ВВОДА/ВЫВОДА
// ----------------------------------- //

std::ostream& operator<< (std::ostream& out, const Polynomial& polynomial)
{
	int size = polynomial.coefficients.size();
	bool first = true;

	for (int i = size - 1; i >= 0; i--) {
		auto coefficient = polynomial.coefficients[i];
		if (coefficient == 0) continue;

//		if (i != size - 1) {
		if (!first) {
			out << ((coefficient < 0) ? " - " : " + ");
		} else {
			out << ((coefficient < 0) ? " - " : "");
		}

		out << ((coefficient < 0) ? -coefficient : coefficient);

		if (i != 0) {
			out << "x^" << i;
		}

		first = false;
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


// ----------------------------------- //
// МЕТОД ДЕЛЕНИЯ ПОЛИНОМОВ
// ----------------------------------- //

bool Polynomial::Equal(double x, double y)
{
	return fabs(x - y) < 1e-9;
}

Polynomial Polynomial::DivPolynomial(const Polynomial& dividend, const Polynomial& divider, bool returnRemainder)
{
	auto temp = Polynomial(dividend);
	auto A    = &temp.coefficients;
	auto B    = divider.coefficients;

	int n = (int)A->size() - 1;
	int m = (int)B.size() - 1;

	auto result = Polynomial(n - m + 1);

	for (int i = n; i >= m; i--) {
		result[i - m] = A->at(i) / B[m];
		for (int j = m; j >= 0; j--) {
			A->at(i - m + j) -= B[j] * result[i - m];
		}
	}

	A->resize(m);
	while(A->size() > 1 && Polynomial::Equal(A->back(), 0)) {
		A->pop_back();
	}

	if (returnRemainder) {
		return temp;
	} else {
		return result;
	}
}