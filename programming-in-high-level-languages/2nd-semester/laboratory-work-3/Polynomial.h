/**
 * Created by Bernigend on 28.04.2020.
 */

#ifndef LABORATORY_WORK_3_POLYNOMIAL_H
#define LABORATORY_WORK_3_POLYNOMIAL_H


#include <cmath>
#include <iostream>

class Polynomial {
protected:
	// степень полинома
	unsigned int degree = 0;
	// коэффициенты полинома
	double *coefficient = new double[1] {0.0};

public:
	// конструктор по умолчанию
	Polynomial();
	// конструктор с параметрами
	Polynomial(unsigned int, const double* = nullptr);
	// констурктор копирования
	Polynomial(const Polynomial&);
	// деструктор
	~Polynomial();

	// вычисляет значение многочлена при заданном X
	double calculate(double);

	Polynomial operator+ (const Polynomial&);
	Polynomial operator- (const Polynomial&);
	Polynomial operator* (const Polynomial&);

	// перегрузка оператора []
	double& operator[] (unsigned int);

	// то же самое, что и []
	double& at(unsigned int);

	// оператор вывода
	friend std::ostream& operator<< (std::ostream&, const Polynomial&);

	// оператор ввода
	friend std::istream& operator>> (std::istream&, Polynomial&);
};


#endif //LABORATORY_WORK_3_POLYNOMIAL_H
