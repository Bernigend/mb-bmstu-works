/**
 * БИЛЕТ 25, Пиксаев А.Н. К3-22Б 19МК019
 * ---
 * Реализовать класс вектор в трехмерном пространстве, с перегрузкой операторов
 * ---
 * Стандарт: C++11
 */

#include <iostream>


// ---------- CLASS DECLARATION ---------- //


class Vector {
protected:
	int x = 0;
	int y = 0;
	int z = 0;

public:
	Vector();
	Vector(int X, int Y, int Z);
	Vector(const Vector& vector);

	Vector operator+ (const Vector& other) const;
	Vector operator- (const Vector& other) const;
	int operator* (const Vector& other) const;

	friend std::ostream& operator<< (std::ostream& out, const Vector& vector);
	friend std::istream& operator>> (std::istream& in, Vector& vector);
};


// ---------- MAIN FUNCTION ---------- //


int main() {
	Vector vector1 = Vector(0, 1, 3);
	Vector vector2 = Vector(5, 2, 3);

	std::cout << vector1 << std::endl;
	std::cout << vector1 * vector2 << std::endl;
	std::cout << vector1 + vector2 << std::endl;

	return 0;
}


// ---------- CLASS IMPLEMENTATION ---------- //


Vector::Vector() = default;

Vector::Vector(int X, int Y, int Z) : x{X}, y{Y}, z{Z} {}

Vector::Vector(const Vector& vector) : Vector(vector.x, vector.y, vector.z) {}

Vector Vector::operator+ (const Vector& other) const
{
	return Vector { this->x + other.x, this->y + other.y, this->z + other.z };
}

Vector Vector::operator- (const Vector& other) const
{
	// по аналогии с Vector::operator+
}

int Vector::operator* (const Vector& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

std::ostream& operator<< (std::ostream& out, const Vector& vector)
{
	return out << "{ " << vector.x << "; " << vector.y << "; " << vector.z << " }";
}

std::istream& operator>> (std::istream& in, Vector& vector)
{
	// по аналогии с operator<<
}
