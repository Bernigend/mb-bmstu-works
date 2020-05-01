/**
 * Created by Bernigend on 01.05.2020.
 */

#ifndef LABORATORY_WORK_3_V2_POLYNOMIAL_H
#define LABORATORY_WORK_3_V2_POLYNOMIAL_H


#include <vector>
#include <iostream>

class Polynomial {
protected:
	std::vector<double> coefficients;

public:
	// конструктор по умолчанию
	static bool DivPolynomial(Polynomial *P, Polynomial *Q);
	Polynomial();
	// конструктор с указанием количества коэффициентов
	explicit Polynomial(unsigned int);
	// конструктор с указанием массива коэффициентов и его размера
	Polynomial(const double*, unsigned int);
	// конструктор со списком инициализации
	Polynomial(const std::initializer_list<double>&);
	// конструктор копирования
	Polynomial(const Polynomial&);
	// деструктор
	~Polynomial();

	// арифметические операторы
	Polynomial operator+ (const Polynomial&);
	Polynomial operator- (const Polynomial&);
	Polynomial operator* (const Polynomial&);

	Polynomial operator+= (const Polynomial&);
	Polynomial operator-= (const Polynomial&);
	Polynomial operator*= (const Polynomial&);

	// вычисляет значение многочлена при заданном X
	double calculate(double);

	// перегрузка оператора []
	double& operator[] (unsigned int);
	double at(unsigned int);

	// операторы ввода/вывода
	friend std::ostream& operator<< (std::ostream&, const Polynomial&);
	friend std::istream& operator>> (std::istream&, Polynomial&);
};


#endif //LABORATORY_WORK_3_V2_POLYNOMIAL_H
