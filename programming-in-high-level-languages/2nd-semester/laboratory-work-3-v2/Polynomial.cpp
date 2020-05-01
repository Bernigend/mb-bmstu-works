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

/**
 * @param P делимое
 * @param Q делитель
 * @param H частное
 * @param R остаток
 * @return
 */
bool Polynomial::DivPolynomial(Polynomial *P, Polynomial *Q) {

	/// DEGREE = COEFFICIENTS.SIZE() - 1

	int i,j;
	double u;

	auto *nh = new Polynomial(P->coefficients.size()-1 - Q->coefficients.size()-1 + 1),
	     *nr = new Polynomial(P->coefficients.size());

//	nh = (Polynomial *) calloc(1,sizeof(Polynomial));
//	nr = (Polynomial *) calloc(1,sizeof(Polynomial));

	if (Q->coefficients.size()-1==0 && Q->coefficients[0]==0.0) return false;

//	nr->degree=P->degree;
//	nr->coefficient = new double [nr->degree+1];

//	for (i=0; i<=P->degree; i++)  nr->coefficient[i]=P->coefficient[i];
	for (i=0; i<=P->coefficients.size()-1; i++)  nr->coefficients[i]=P->coefficients[i];

//	nh->degree = P->degree - Q->degree;
//	nh->coefficient = new double [nh->degree+1];

	if (nh->coefficients.size()-1<0) {

//		nh->degree=0;
		nh->coefficients[0] = 0.0;

	} else {

		for (i = nh->coefficients.size()-1; i>=0; i--)  {
			nh->coefficients[i] = nr->coefficients[nr->coefficients.size()-1] / Q->coefficients[Q->coefficients.size()-1];
			for (j=i; j<=nr->coefficients.size()-1; j++) {
				u = nh->coefficients[i] * Q->coefficients[j-i];
				u = -u;
				nr->coefficients[j] = nr->coefficients[j] + u;
			}
//			if (nr->coefficients.size()-1 > 0)  nr->degree--;
		}

//		while (fabs(nr->coefficients[nr->coefficients.size()-1]) < 1e-12 && nr->coefficients.size()-1>0)
//			nr->degree--;
	}

//	H->degree      = nh->degree;
//	H->coefficient = new double [H->degree+1];
	Polynomial HH = Polynomial(nh->coefficients.size());
	for (i=0; i<=nh->coefficients.size()-1; i++) HH.coefficients[i] = nh->coefficients[i];

//	R->degree      = nr->degree;
//	R->coefficient = new double [R->degree+1];
	Polynomial RR = Polynomial(nr->coefficients.size());
	for (i=0; i<=nr->coefficients.size()-1; i++) RR.coefficients[i] = nr->coefficients[i];

	delete nh;
	delete nr;

	std::cout << "chastnoe: " << HH << std::endl;
	std::cout << "ostatok: " << RR << std::endl;

	return true;
}