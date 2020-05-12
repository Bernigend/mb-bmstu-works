#include <iostream>
#include "Circle.h"

int main() {
	const std::string INPUT_FILE_PATH  = "C:/Development/mb-bmstu-works/programming-in-high-level-languages/2nd-semester/task-16/input.txt";
	const std::string OUTPUT_FILE_PATH = "C:/Development/mb-bmstu-works/programming-in-high-level-languages/2nd-semester/task-16/output.txt";

	// -------------------- //

	std::cout << "# ----------------- #" << std::endl;
	std::cout << "# ----- TESTS ----- #" << std::endl;
	std::cout << "# ----------------- #" << std::endl;
	std::cout << std::endl;

	// -------------------- //

	auto circle1 = Circle(0, 0, 5);
	auto circle2 = Circle(circle1);

	std::cout << "circle1 == circle2" << std::endl;
	std::cout << circle1.getCommonPoints(circle2) << std::endl;
	std::cout << std::endl;

	// -------------------- //

	auto circle3 = Circle(2, 2, 2);
	auto circle4 = Circle(2, 3, 2);

	std::cout << "circle3 and circle4 = 2 common points" << std::endl;
	std::cout << circle3.getCommonPoints(circle4) << std::endl;
	std::cout << std::endl;

	// -------------------- //

	auto circle5 = Circle(0, 0, 2);
	auto circle6 = Circle(4, 0, 2);

	std::cout << "circle5 and circle6 = 1 common point" << std::endl;
	std::cout << circle5.getCommonPoints(circle6) << std::endl;
	std::cout << std::endl;

	// -------------------- //

	auto circle7 = Circle(2, 2, 2);
	auto circle8 = Circle(5, 5, 2);

	std::cout << "circle7 and circle8 = 0 common points" << std::endl;
	std::cout << circle7.getCommonPoints(circle8) << std::endl;
	std::cout << std::endl;

	// -------------------- //

	std::cout << "# ----------------- #" << std::endl;
	std::cout << "# - WRITE TO FILE - #" << std::endl;
	std::cout << "# ----------------- #" << std::endl;
	std::cout << std::endl;

	std::vector<Circle> circles;
	CircleErrors circleError;

	// --- //

	std::cout << "Open " + INPUT_FILE_PATH + " ";

	// получаем данные обо всех Circles из файла
	circleError = Circle::getFromFile(INPUT_FILE_PATH, &circles);
	if (circleError != CircleErrors::SUCCESS) {
		Circle::printError(std::cerr, circleError);
		return EXIT_FAILURE;
	}

	std::cout << "- success" << std::endl;

	// --- //

	std::cout << "Open " + OUTPUT_FILE_PATH + " and write answer to it ";

	// записываем данные об общих точках в файл
	circleError = Circle::writeAllCommonPoints(OUTPUT_FILE_PATH, &circles);
	if (circleError != CircleErrors::SUCCESS) {
		Circle::printError(std::cerr, circleError);
		return EXIT_FAILURE;
	}

	std::cout << "- success" << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
