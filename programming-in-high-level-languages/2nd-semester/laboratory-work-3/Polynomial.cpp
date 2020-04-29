/**
 * Created by Bernigend on 28.04.2020.
 */

#include <cmath>
#include "Polynomial.h"

// конструктор по умолчанию
Polynomial::Polynomial() = default;

// конструктор с параметрами
Polynomial::Polynomial(unsigned int _degree, const double* _coefficient)
{
	this->degree      = _degree;
	this->coefficient = new double [this->degree + 1];
	for (int i = 0; i <= this->degree; i++) {
		this->coefficient[i] = (_coefficient != nullptr) ? _coefficient[i] : 0.0;
	}
}

// констурктор копирования
Polynomial::Polynomial(const Polynomial& polynomial)
{
	this->degree      = polynomial.degree;
	this->coefficient = new double [this->degree + 1];
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

Polynomial Polynomial::operator/ (Polynomial& other)
{
	auto H = new Polynomial();
	auto R = new Polynomial();

	Polynomial* p = &other;

	Polynomial::DivPolynomial(this, p, H, R);

	return *H;
}

Polynomial Polynomial::operator% (Polynomial& other)
{
	auto H = new Polynomial();
	auto R = new Polynomial();

	Polynomial* p = &other;

	Polynomial::DivPolynomial(this, p, H, R);

	return *R;
}

Polynomial Polynomial::operator+=(const Polynomial& polynomial)
{
	return *this + polynomial;
}

Polynomial Polynomial::operator-=(const Polynomial& polynomial)
{
	return *this - polynomial;
}

Polynomial Polynomial::operator*=(const Polynomial& polynomial)
{
	return *this * polynomial;
}

Polynomial Polynomial::operator/=(Polynomial& polynomial)
{
	return *this / polynomial;
}

Polynomial Polynomial::operator%=(Polynomial& polynomial)
{
	return *this % polynomial;
}

bool Polynomial::DivPolynomial(Polynomial *P, Polynomial *Q, Polynomial *H, Polynomial *R) {
	int i,j;
	double u;

	auto *nh = new Polynomial(),
		 *nr = new Polynomial();

//	nh = (Polynomial *) calloc(1,sizeof(Polynomial));
//	nr = (Polynomial *) calloc(1,sizeof(Polynomial));

	if (Q->degree==0 && Q->coefficient[0]==0.0) return false;

	nr->degree=P->degree;
	nr->coefficient = new double [nr->degree+1];

	for (i=0; i<=P->degree; i++)  nr->coefficient[i]=P->coefficient[i];

	nh->degree = P->degree - Q->degree;
	nh->coefficient = new double [nh->degree+1];

	if (nh->degree<0) {

		nh->degree=0;
		nh->coefficient[0] = 0.0;

	} else {

		for (i = nh->degree; i>=0; i--)  {
			nh->coefficient[i] = nr->coefficient[nr->degree] / Q->coefficient[Q->degree];
			for (j=i; j<=nr->degree; j++) {
				u = nh->coefficient[i] * Q->coefficient[j-i];
				u = -u;
				nr->coefficient[j] = nr->coefficient[j] + u;
			}
			if (nr->degree > 0)  nr->degree--;
		}

		while (fabs(nr->coefficient[nr->degree]) < 1e-12 && nr->degree>0)
			nr->degree--;
	}

	H->degree      = nh->degree;
	H->coefficient = new double [H->degree+1];
	for (i=0; i<=nh->degree; i++) H->coefficient[i] = nh->coefficient[i];

	R->degree      = nr->degree;
	R->coefficient = new double [R->degree+1];
	for (i=0; i<=nr->degree; i++) R->coefficient[i] = nr->coefficient[i];

	delete nh;
	delete nr;

	return true;
}

// перегрузка оператора []
double& Polynomial::operator[] (const unsigned int _degree)
{
	return this->coefficient[_degree];
}

// то же самое, что и []
double Polynomial::at(unsigned int _degree)
{
	return (_degree <= this->degree) ? this->coefficient[_degree] : 0.0;
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