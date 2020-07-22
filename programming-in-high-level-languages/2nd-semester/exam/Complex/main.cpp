/**
 * БИЛЕТ 3
 * ---
 * Реализовать класс комплексных чисел, с перегрузкой операторов. И
 * преобразования в различные формы (арифметическая, тригонометрическая
 * экспоненциальная).
 * ---
 * Стандарт: C++11
 * ---
 * ПРИМЕЧАНИЕ: эта задача - лабораторная №0 по АСД + 3 новых метода для преобразования
 */

#include <iostream>
#include <cmath>


// ---------- CLASS DECLARATION ---------- //


class Complex {
protected:
	double re;
	double im;

	double module() const;

public:
	// конструктор с параметрами по умолчанию
	explicit Complex(double = 0.0, double = 0.0);
	// конструктор копирования
	Complex(const Complex&);

	// оператор сложения
	Complex operator+ (const Complex&) const;
	// оператор вычитания
	Complex operator- (const Complex&) const;
	// оператор умножения
	Complex operator* (const Complex&) const;
	// оператор деления
	Complex operator/ (const Complex&) const;

	// оператор вывода
	friend std::ostream& operator<< (std::ostream&, const Complex&);
	// оператор ввода
	friend std::istream& operator>> (std::istream&, Complex&);

	inline double getRe() const;
	inline double getIm() const;

	// все методы выше были сделаны в лаб №0 по АСД

	// перевод в арифметическую форму
	double toArithmeticNotation() const;
	// перевод в тригонометрическую форму
	std::string toTrigonometricNotation() const;
	// перевод в экспоненциальную форму
	std::string toExponentialNotation() const;
};

double Complex::getRe() const
{
	return this->re;
}

double Complex::getIm() const
{
	return this->im;
}


// ---------- MAIN FUNCTION ---------- //


int main() {
	Complex complex1 = Complex(3.4, 4.5);
	Complex complex2 = Complex(1.2, 5.6);

	std::cout << "Complex1: " << complex1 << std::endl;
	std::cout << "Complex1 + Complex2: " << complex1 + complex2 << std::endl;
	std::cout << std::endl;

	std::cout << "Complex1 in arithmetic notation:    " << complex1.toArithmeticNotation() << std::endl;
	std::cout << "Complex1 in trigonometric notation: " << complex1.toTrigonometricNotation() << std::endl;
	std::cout << "Complex1 in exponential notation:   " << complex1.toExponentialNotation() << std::endl;

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Complex::Complex(double _re, double _im) : re{_re}, im{_im} {}

Complex::Complex(const Complex& complex) : re{complex.getRe()}, im{complex.getIm()} {}

double Complex::module() const
{
	return sqrt(std::pow(re,2) + std::pow(im,2));
}

double Complex::toArithmeticNotation() const
{
	double fi = 0;

	if (this->re > 0) {
		if (this->im > 0)
			fi = std::atan(std::abs(this->im / this->re));
		else if (this->im < 0)
			fi = -std::atan(std::abs(this->im / this->re));
		else
			fi = 0;
	}
	else if (this->re < 0)
	{
		if (this->im > 0)
			fi = 3.14 - std::atan(std::abs(this->im / this->re));
		else if (this->im < 0)
			fi = atan(std::abs(this->im / this->re)) - 3.14;
		else
			fi = 3.14;
	}
	else
	{
		if (this->im > 0)
			fi = 1.57;
		else if (this->im < 0)
			fi = 3.14;
	}

	return fi;
}

std::string Complex::toTrigonometricNotation() const
{
	double r = module();
	double fi = toArithmeticNotation();
	return std::to_string(r) + " * ( " + std::to_string(cos(fi)) + " +i* " + std::to_string(sin(fi)) + " )";
}

std::string Complex::toExponentialNotation() const
{
	double r = module();
	double fi = toArithmeticNotation();
	return std::to_string(r) + " * exp^( " + std::to_string(fi) + " )*i";
}

Complex Complex::operator+ (const Complex& complex) const
{
	return Complex {this->re + complex.re, this->im + complex.im};
}

Complex Complex::operator- (const Complex& complex) const
{
	return Complex {this->re - complex.re, this->im - complex.im};
}

Complex Complex::operator* (const Complex& complex) const
{
	return Complex {
		this->re * complex.re - this->im * complex.im,
		this->re * complex.im + this->im * complex.re
	};
}

Complex Complex::operator/ (const Complex& complex) const
{
	double r = complex.re * complex.re + complex.im * complex.im;
	return Complex {
		((this->re * complex.re + this->im * complex.im) / r),
		((this->im * complex.re - this->re * complex.im) / r)
	};
}

std::ostream& operator<< (std::ostream& stream, const Complex& complex)
{
	stream << "z = " << complex.re;

	if (complex.im >= 0) {
		stream << " + " << complex.im << "*i";
	} else {
		stream << " - " << -complex.im << "*i";
	}

	return stream;
}

std::istream& operator>> (std::istream& stream, Complex& complex)
{
	stream >> complex.re;
	stream >> complex.im;
	return stream;
}