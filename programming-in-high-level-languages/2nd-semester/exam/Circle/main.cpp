/**
 * БИЛЕТ 1
 * ---
 * Реализовать класс окружность с методом определения отношения между двумя
 * окружностями, рассмотреть все случаи нахождения одной окружности
 * относительно другой.
 * ---
 * Стандарт: C++11
 */

#include <iostream>


// ---------- CLASS DECLARATION ---------- //


const double PI = 3.14;

enum CIRCLE_PLACES {
	COINCIDE,  // окружности совпадают
	CONTAINS,  // одна окружность входит в другую
	OUTSIDE,   // окруности не пересекаются
	ONE_TOUCH, // окружности имеют 1 общую точку
	TWO_TOUCH  // окружности имеют 2 общие точки
};

class Circle {
protected:
	int X; // x кордината
	int Y; // y координата
	unsigned int R; // радиус

public:
	// проверка радиуса должна осуществляться самостоятельно
	Circle(int x, int y, unsigned int r);
	Circle(const Circle& circle);

	// вычисляет площадь окружности
	double area() const;
	// определяет взаимоположение двух окружностей
	CIRCLE_PLACES checkLocation(const Circle& other) const;
};


// ---------- MAIN FUNCTION ---------- //


int main() {
	Circle circle1 = Circle(0, 0, 5);
	Circle circle2 = Circle(3, 5, 3);

	std::cout << "Area 1: " << circle1.area() << std::endl;
	std::cout << "Area 2: " << circle2.area() << std::endl;
	std::cout << std::endl;

	auto location = circle1.checkLocation(circle2);
	switch (location) {
		case COINCIDE:
			std::cout << "Circles coincide";
			break;
		case CONTAINS:
			std::cout << "One circle contains the other";
			break;
		case OUTSIDE:
			std::cout << "Circles are too far apart";
			break;
		case ONE_TOUCH:
			std::cout << "One common point";
			break;
		case TWO_TOUCH:
			std::cout << "Two common points";
			break;
	}

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Circle::Circle(int x, int y, unsigned int r) : X{x}, Y{y}, R{r} {}

Circle::Circle(const Circle& circle) : Circle(circle.X, circle.Y, circle.R) {}

double Circle::area() const {
	return PI * this->R * this->R;
}

CIRCLE_PLACES Circle::checkLocation(const Circle& other) const {
	int distance   = (this->X - other.X) * (this->X - other.X) + (this->Y - other.Y) * (this->Y - other.Y);
	unsigned int r = (this->R + other.R) * (this->R + other.R);

	// проверяем пересекаются ли окружности
	if (distance > r)
		return OUTSIDE;
	else if (distance == 0 && this->R == other.R)
		return COINCIDE;
	else if (distance + std::min(this->R, other.R) < std::max(this->R, other.R))
		return CONTAINS;
	else if (distance == r)
		return ONE_TOUCH;
	else
		return TWO_TOUCH;
}
