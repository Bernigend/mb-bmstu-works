/**
 * Created by Bernigend on 28.04.2020.
 */

#include "Polynomial.h"

// конструктор по умолчанию
Polynomial::Polynomial() = default;

// конструктор с параметрами
Polynomial::Polynomial(unsigned int _degree, const double* _coefficient)
{
	this->degree = 0;
	for (int i = 0; i <= _degree; i++) {
		if (_coefficient[i] != 0) {
			this->degree = i;
		}
	}

	this->coefficient = new double [this->degree+1];
	for (int i = 0; i <= this->degree; i++) {
		if (_coefficient != nullptr)
			this->coefficient[i] = _coefficient[i];
		else
			this->coefficient[i] = 0.0;
	}
}

// констурктор копирования
Polynomial::Polynomial(const Polynomial& polynomial)
{
	this->degree      = polynomial.degree;
	this->coefficient = new double [this->degree+1];

	for (int i = 0; i <= this->degree; i++) {
		this->coefficient[i] = polynomial.coefficient[i];
	}
}

// деструктор
Polynomial::~Polynomial() = default;

// вычисляет значение многочлена при заданном X
double Polynomial::calculate(double x)
{
	double answer = 0.0;

	for (int i = 0; i <= this->degree; i++) {
		answer += std::pow(x, this->degree - i) * this->coefficient[i];
	}

	return answer;
}

Polynomial Polynomial::operator+ (const Polynomial& polynomial)
{
	Polynomial* result;

	if (this->degree >= polynomial.degree) {
		result = new Polynomial(this->degree, this->coefficient);
		unsigned int tmp = 0;
		for (int i = this->degree - polynomial.degree; i - 1 <= polynomial.degree; i++) {
			result->coefficient[i] = result->coefficient[i] + polynomial.coefficient[tmp++];
		}
	} else {
		result = new Polynomial(polynomial.degree, polynomial.coefficient);
		unsigned int tmp = 0;
		for (int i = polynomial.degree - this->degree; i - 1 <= this->degree; i++) {
			result->coefficient[i] = result->coefficient[i] + this->coefficient[tmp++];
		}
	}

	return *result;
}

Polynomial Polynomial::operator- (const Polynomial& polynomial)
{
	Polynomial* result;

	if (this->degree >= polynomial.degree) {
		result = new Polynomial(this->degree, this->coefficient);
		unsigned int tmp = 0;
		for (int i = this->degree - polynomial.degree; i - 1 <= polynomial.degree; i++) {
			result->coefficient[i] = result->coefficient[i] - polynomial.coefficient[tmp++];
		}
	} else {
		result = new Polynomial(polynomial.degree, polynomial.coefficient);
		unsigned int tmp = 0;
		for (int i = polynomial.degree - this->degree; i - 1 <= this->degree; i++) {
			result->coefficient[i] = this->coefficient[tmp++] - result->coefficient[i];
		}
	}

	return *result;
}

Polynomial Polynomial::operator* (const Polynomial& polynomial)
{
	Polynomial temp;
	temp.degree=degree+polynomial.degree;
	temp.coefficient = new double [temp.degree + 1];
	for(int i=0;i<=degree;i++)
	{
		for(int j=0;j<=polynomial.degree;j++)
		{
			temp.coefficient[i+j] +=coefficient[i]*polynomial.coefficient[j];
		}
	}
	return temp;
}

// перегрузка оператора []
double& Polynomial::operator[] (const unsigned int _degree)
{
	return this->coefficient[_degree];
}

// то же самое, что и []
double& Polynomial::at(unsigned int _degree)
{
	return this->coefficient[_degree];
}

// оператор вывода
std::ostream& operator<< (std::ostream& ostream, const Polynomial& polynomial)
{
	auto _degree = static_cast<int>(polynomial.degree);

	for (int i = _degree; i >= 0; i--) {
		double _coefficient = polynomial.coefficient[_degree - i];
		if (i < _degree) {
			ostream << ((_coefficient > 0) ? " + " : " - ");
		}
		ostream << ((_coefficient < 0) ? -_coefficient : _coefficient);
		ostream << "x^" << i;
	}

	return ostream;
}

// оператор ввода
std::istream& operator>> (std::istream& in, Polynomial& polynomial)
{
	in >> polynomial.degree;
	polynomial.coefficient = new double [polynomial.degree + 1];
	for (int i = 0; i <= polynomial.degree; i++) {
		in >> polynomial.coefficient[i];
	}
	return in;
}