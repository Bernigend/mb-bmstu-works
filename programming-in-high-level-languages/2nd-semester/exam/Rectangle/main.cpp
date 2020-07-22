/**
 * БИЛЕТ 2
 * ---
 * Реализовать класс прямоугольник с методом определения отношения между двумя
 * прямоугольниками, рассмотреть все случаи нахождения одного прямоугольника
 * относительно другого.
 * ---
 * Стандарт: C++11
 */

#include <iostream>


// ---------- CLASS DECLARATION ---------- //


enum RECTANGLE_PLACES {
	INTERSECT,
	NOT_INTERSECT,
	SECOND_IN_FIRST,
	FIRST_IN_SECOND
};

class Rectangle {
protected:
	int X1 = 0; // X координата левой нижней точки
	int Y1 = 0; // Y координата левой нижней точки
	int X2 = 0; // X координата правой верхней точки
	int Y2 = 0; // Y координата правой верхней точки

public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(const Rectangle& rectangle);

	RECTANGLE_PLACES checkLocation(const Rectangle& other) const;

	friend std::ostream& operator<< (std::ostream& out, const Rectangle& rectangle);
	friend std::istream& operator>> (std::istream& in, Rectangle& rectangle);
};


// ---------- MAIN FUNCTION ---------- //


int main() {
	Rectangle rectangle1 = Rectangle(0, 0, 4, 4);
	Rectangle rectangle2 = Rectangle(-1, -1, 10, 10);

	switch (rectangle1.checkLocation(rectangle2)) {
		case INTERSECT:
			std::cout << "intersect";
			break;
		case NOT_INTERSECT:
			std::cout << "not intersect";
			break;
		case FIRST_IN_SECOND:
			std::cout << "first rectangle within second";
			break;
		case SECOND_IN_FIRST:
			std::cout << "second rectangle within first";
			break;
	}

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Rectangle::Rectangle() = default;

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : X1{x1}, Y1{y1}, X2{x2}, Y2{y2} {}

Rectangle::Rectangle(const Rectangle& rectangle) = default;

RECTANGLE_PLACES Rectangle::checkLocation(const Rectangle& other) const
{
	int left   = std::max(this->X1, other.X1),
		top    = std::min(this->Y2, other.Y2),
		right  = std::min(this->X2, other.X2),
		bottom = std::max(this->Y1, other.Y1),
		width  = right - left,
		height = top - bottom;

	if (width < 0 || height < 0)
		return RECTANGLE_PLACES::NOT_INTERSECT;
	else if ((this->X1 < other.X1) && (this->X2 > other.X2) && (this->Y1 < other.Y1) && (this->Y2 > other.Y2))
		return RECTANGLE_PLACES::SECOND_IN_FIRST;
	else if ((this->X1 > other.X1) && (this->X2 < other.X2) && (this->Y1 > other.Y1) && (this->Y2 < other.Y2))
		return RECTANGLE_PLACES::FIRST_IN_SECOND;

	return RECTANGLE_PLACES::INTERSECT;
}

std::ostream& operator<< (std::ostream& out, const Rectangle& rectangle)
{
	// TODO
}

std::istream& operator>> (std::istream& in, Rectangle& rectangle)
{
	// TODO
}
