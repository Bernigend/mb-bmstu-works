/**
 * БИЛЕТ 7
 * ---
 * Разработать класс для работы с градусами с перегрузкой операторов и переводом
 * из градусов секунд и минут в радианы и обратно.
 * ---
 * Стандарт: C++11
 */

#include <iostream>


// ---------- CLASS DECLARATION ---------- //


const double PI = 3.14159;

class Angle {
protected:
	int degree = 0;
	int minute = 0;
	int second = 0;

	double radians    = 0.0;
	double normDegree = 0.0;

	// переводит градусы + минуты + секунды в десятичное число
	void normalizeDegrees();
	// переводит радианы в градусы + минуты + секунды
	void convertToDegree();
	// переводит градусы в радианы
	void convertToRadians();

public:
	// конструктор для радиан
	// автоматически разбивает радианы на градусы + минуты + секунды
	explicit Angle(double _radians);

	// конструктор для градусов + минут + секунд
	// автоматически совмещает их в радианы
	Angle(int _degree, int _minute, int _second);

	Angle operator+ (const Angle& other) const;
	Angle operator- (const Angle& other) const;

	friend std::ostream& operator<< (std::ostream& out, const Angle& angle);

	inline int getDegree() const;
	inline int getMinute() const;
	inline int getSecond() const;
	inline double getRadians() const;
	inline double getNormDegree() const;
};

int Angle::getDegree() const {
	return degree;
}

int Angle::getMinute() const {
	return minute;
}

int Angle::getSecond() const {
	return second;
}

double Angle::getRadians() const {
	return radians;
}

double Angle::getNormDegree() const {
	return normDegree;
}


// ---------- MAIN FUNCTION ---------- //


int main() {

	Angle angle1 = Angle(55, 45, 0);
	Angle angle2 = Angle(2);

	std::cout << angle1 << std::endl;
	std::cout << std::endl;
	std::cout << angle2 << std::endl;
	std::cout << std::endl;
	std::cout << angle1 + angle2 << std::endl;

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Angle::Angle(double _radians) : radians{_radians}
{
	this->convertToDegree();
	this->normalizeDegrees();
}

Angle::Angle(int _degree, int _minute, int _second) : degree{_degree}, minute{_minute}, second{_second}
{
	this->normalizeDegrees();
	this->convertToRadians();
}

void Angle::normalizeDegrees()
{
	this->normDegree = this->degree / 1.0 + this->minute / 60.0 + this->second / 3600.0;
}

void Angle::convertToDegree()
{
	double tmp = this->radians * 180.0 / PI;
	this->degree = static_cast<int>(tmp);

	tmp = (tmp - this->degree) * 60.0;
	this->minute = static_cast<int>(tmp);

	tmp = (tmp - this->minute) * 60.0;
	this->second = static_cast<int>(tmp);
}

void Angle::convertToRadians()
{
	this->radians = this->normDegree * PI / 180;
}

Angle Angle::operator+ (const Angle& other) const
{
	return Angle { this->radians + other.radians };
}

Angle Angle::operator- (const Angle& other) const
{
	return Angle { this->radians - other.radians };
}

std::ostream& operator<< (std::ostream& out, const Angle& angle)
{
	return out
		<< "degree = " << angle.degree << std::endl
		<< "minute = " << angle.minute << std::endl
		<< "second = " << angle.second << std::endl
		<< "radian = " << angle.radians;
}
