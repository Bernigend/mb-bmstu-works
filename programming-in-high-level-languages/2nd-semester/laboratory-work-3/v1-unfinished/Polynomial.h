#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "google-explicit-constructor"
/**
 * Created by Bernigend on 28.04.2020.
 */

#ifndef LABORATORY_WORK_3_POLYNOMIAL_H
#define LABORATORY_WORK_3_POLYNOMIAL_H


#include <iostream>

class Polynomial {
protected:
	// степень полинома
	unsigned int degree = 0;
	// коэффициенты полинома
	double* coefficient = nullptr;

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
	Polynomial operator/ (Polynomial&);
	Polynomial operator% (Polynomial&);

	Polynomial operator+= (const Polynomial&);
	Polynomial operator-= (const Polynomial&);
	Polynomial operator*= (const Polynomial&);
	Polynomial operator/= (Polynomial&);
	Polynomial operator%= (Polynomial&);

	// не спрашивайте как и почему
	// взято из http://jean-pierre.moreau.pagesperso-orange.fr/c_polynoms.html
	// адаптировано под мой класс
	// как иначе реализовать метод не знаю, хоть расстреляйте
	static bool DivPolynomial(Polynomial *P, Polynomial *Q, Polynomial *H, Polynomial *R);

	// перегрузка оператора []
	double& operator[] (unsigned int);
	double at(unsigned int);

	// оператор вывода
	friend std::ostream& operator<< (std::ostream&, const Polynomial&);
	// оператор ввода
	friend std::istream& operator>> (std::istream&, Polynomial&);
};


#endif //LABORATORY_WORK_3_POLYNOMIAL_H

#pragma clang diagnostic pop