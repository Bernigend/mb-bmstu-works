/**
 * Created by Bernigend on 11.05.2020.
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include "Circle.h"

// ------------------------------
// КОНСТРУКТОРЫ
// ------------------------------

Circle::Circle() = default;
Circle::Circle(const Circle& other) = default;
Circle::Circle(int x, int y, int r) {
	this->X = x;
	this->Y = y;
	this->R = r;
}

// ------------------------------
// МЕТОДЫ
// ------------------------------

int Circle::getCommonPoints(const Circle& other) {
	const double EPS = 1e-12;
	int distance = 0;

	// проверяем, не совпадают ли окружности
	if ((this->X == other.X) && (this->Y == other.Y) && (this->R == other.R)) {
		return -1;
	}

	distance += (other.X - this->X)*(other.X - this->X);
	distance += (other.Y - this->Y)*(other.Y - this->Y);

	// проверяем условие внешнего касания
	if (std::fabs((this->R + other.R) * (this->R + other.R) - distance) < EPS) {
		return 1;
	}

	// проверяем условие внутреннего касания
	if (std::fabs((this->R - other.R) * (this->R - other.R) - distance) < EPS) {
		return 1;
	}

	// рассматриваем случаи, когда окружности не имеют общих точек
	if (
		((this->R + other.R)*(this->R + other.R) < distance - EPS) ||
		((this->R - other.R)*(this->R - other.R) > distance + EPS)
	) {
		return 0;
	}

	return 2;
}

CircleErrors Circle::getFromFile(const std::string& path, std::vector<Circle>* circles) {
	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		inputFile.close();
		return CircleErrors::CANNOT_OPEN_FILE;
	}

	std::string inputLine;
	while (std::getline(inputFile, inputLine)) {
		int xPoint = 0, yPoint = 0, rLength = 0;
		std::sscanf(inputLine.c_str(), "%d %d %d", &xPoint, &yPoint, &rLength);
		circles->emplace_back(Circle { xPoint, yPoint, rLength });
	}

	inputFile.close();
	return CircleErrors::SUCCESS;
}

CircleErrors Circle::writeAllCommonPoints(const std::string& path, std::vector<Circle>* circles) {
	if (circles == nullptr) {
		return CircleErrors::CIRCLES_LIST_IS_NULL;
	}

	auto circlesNum = circles->size();
	if (circlesNum % 2 != 0) {
		return CircleErrors::CIRCLES_NUM_IS_ODD;
	}

	std::ofstream outputFile(path);
	if (!outputFile.is_open()) {
		outputFile.close();
		return CircleErrors::CANNOT_OPEN_FILE;
	}

	for (int i = 0; i < circlesNum / 2; i++) {
		outputFile << circles->at(0 + i*2).getCommonPoints(circles->at(1 + i*2)) << std::endl;
	}

	outputFile.close();
	return CircleErrors::SUCCESS;
}

void Circle::printError(std::ostream& output, CircleErrors error) {
	switch (error) {
		case CircleErrors::CANNOT_OPEN_FILE:
			output << "Cannot open file";
			break;
		case CircleErrors::CIRCLES_LIST_IS_NULL:
			output << "Circles list is null";
			break;
		case CircleErrors::CIRCLES_NUM_IS_ODD:
			output << "Circles number is odd";
			break;
		default:
			output << "Success";
			break;
	}
}