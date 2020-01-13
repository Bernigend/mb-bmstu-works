/**
 * Created by Bernigend on 03.01.2020.
 */

#include <iostream>
#include <iomanip>
#include "structs.h"

/**
 * Вводит количество строк и столбцов матрицы
 * @param matrix - структура матрицы
 * @throws std::invalid_argument
 */
void enterMatrixSizes(Matrix *matrix) {
	std::cout << "Enter the number of rows in the matrix: ";
	std::cin >> matrix->numRows;
	if (std::cin.fail() || matrix->numRows == 0)
		throw std::invalid_argument("The number of rows entered is incorrect");
	std::cout << std::endl;

	std::cout << "Enter the number of columns in the matrix: ";
	std::cin >> matrix->numCols;
	if (std::cin.fail() || matrix->numCols == 0)
		throw std::invalid_argument("The number of columns entered is incorrect");
	std::cout << std::endl;
}

/**
 * Вводит значения элементов матрицы и проводит вычисления с ними
 * @param matrix - структура матрицы
 * @throws std::invalid_argument
 */
void enterMatrixData(Matrix *matrix) {
	matrix->values = new(std::nothrow)int *[matrix->numRows]{};
	if (matrix->values == nullptr) {
		std::cerr << "Failed to allocate memory for " << matrix->numRows << " rows" << std::endl;
		return;
	}

	for (Uint row = 0; row < matrix->numRows; row++) {

		matrix->values[row] = new(std::nothrow)int[matrix->numCols]{};
		if (matrix->values == nullptr) {
			std::cerr << "Failed to allocate memory for " << matrix->numCols << " cols" << std::endl;
			return;
		}

		for (Uint col = 0; col < matrix->numCols; col++) {

//			Вводим значение нового элемента
			std::cout << "matrix[" << row + 1 << "][" << col + 1 << "] = ";
			std::cin >> matrix->values[row][col];
			if (std::cin.fail())
				throw std::invalid_argument("The value of matrix element is incorrect");
			std::cout << std::endl;

//			Ищем минимальный элемент матрицы
			if ((row == 0 && col == 0) || matrix->values[row][col] < matrix->minElement->value)
				matrix->minElement->set(matrix->values[row][col]);

//			Суммируем значения неотрицательных элементов матрицы
			if (matrix->values[row][col] >= 0)
				matrix->sumOfElements->add(matrix->values[row][col]);
		}
	}
}

/**
 * Выводит матрицу на экран
 * @param matrix - структура матрицы
 * @param withReplacement - нужна ли замена минимального элемента
 */
void printMatrix(Matrix *matrix, bool withReplacement = false) {
//	Если ещё не был найден минимальный элемент и требуется замена элементов
	if (withReplacement && !matrix->minElement->initialized) {
		std::cout << "[WARNING] The minimum element of the matrix has not yet been found" << std::endl;
		std::cout << "[WARNING] The replacement will not be performed" << std::endl << std::endl;
	}

//	Если все элементы матрицы отрицательны и требуется замена элементов
	if (withReplacement && matrix->sumOfElements->countNumbers == 0) {
		std::cout << "[WARNING] The values of all elements of the matrix are negative" << std::endl;
		std::cout << "[WARNING] The replacement will not be performed" << std::endl << std::endl;
	}

	std::cout << ((withReplacement) ? "Your matrix with replacement:" : "Your entered matrix:") << std::endl;

//	Если значения элементов матрицы ещё не были введены
	if (matrix->values == nullptr) {
		std::cout << "The values of elements of the matrix has not yet been entered" << std::endl;
		return;
	}

//	Выводим матрицу
	for (Uint row = 0; row < matrix->numRows; row++) {

//		Если значения элементов строки матрицы ещё не были введены
		if (matrix->values[row] == nullptr) {
			std::cout << "The values of elements of row of the matrix has not yet been entered" << std::endl;
			return;
		}

		for (Uint col = 0; col < matrix->numCols; col++) {

//			Если соблюдены все условия, заменяем элемент средним арифметическим, иначе выводим какой есть
			if (withReplacement && matrix->minElement->initialized && matrix->sumOfElements->countNumbers != 0)
				if (matrix->values[row][col] == matrix->minElement->value)
					std::cout << std::setw(5) << std::right
					          << (float) matrix->sumOfElements->value / matrix->sumOfElements->countNumbers;
				else
					std::cout << std::setw(5) << std::right << matrix->values[row][col];
			else
				std::cout << std::setw(5) << std::right << matrix->values[row][col];
		}
		std::cout << std::endl;
	}
}

/**
 * Выводит информацию о минимальном элементе матрицы на экран
 * @param matrix - структура матрицы
 */
void printMinElementInfo(Matrix *matrix) {
	std::cout << "Minimum element of the matrix:" << std::endl;

//	Если ещё не был найден минимальный элемент
	if (!matrix->minElement->initialized) {
		std::cout << "[WARNING] The minimum element of the matrix has not yet been found" << std::endl;
		return;
	}

	std::cout << " - Value: " << matrix->minElement->value << std::endl;
}

/**
 * Выводит информацию о сумме элементов матрицы на экран
 * @param matrix - структура матрицы
 */
void printSumOfElementsInfo(Matrix *matrix) {
	std::cout << "Sum of elements info:" << std::endl;
	std::cout << " - value: " << matrix->sumOfElements->value << std::endl;
	std::cout << " - numbers: " << matrix->sumOfElements->countNumbers << std::endl;

	if (matrix->sumOfElements->countNumbers != 0)
		std::cout << " - average: " << (float) matrix->sumOfElements->value / matrix->sumOfElements->countNumbers
		          << std::endl;
}