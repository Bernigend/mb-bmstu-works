/**
 * Created by Bernigend on 27.12.2019.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "structs.h"

/**
 * Вводит количество строк и столбцов матрицы
 *
 * @throws std::invalid_argument()
 */
void inputMatrixInfo(Matrix& matrix)
{
	std::cout << "Enter the number of rows of the matrix: ";
	std::cin >> matrix.countRows;
	if (std::cin.fail() || matrix.countRows < 0)
		throw std::invalid_argument("The number of rows is invalid");
	std::cout << std::endl;

	std::cout << "Enter the number of columns of the matrix: ";
	std::cin >> matrix.countCols;
	if (std::cin.fail() || matrix.countCols < 0)
		throw std::invalid_argument("The number of columns is invalid");
	std::cout << std::endl;
}

/**
 * Вводит значения элементов матрицы + ищет минимальный элемент +
 * подсчитывает среднее арифметическое неотрицательных элементов
 *
 * @param matrix - структура Matrix матрицы
 *
 * @return структура матрицы
 *
 * @throws std::invalid_argument()
 */
Matrix inputMatrixData(Matrix& matrix)
{
	matrix.values = new int* [matrix.countRows];

	for (Uint row = 0; row < matrix.countRows; row++) {
		matrix.values[row] = new int [matrix.countCols];

		for (Uint col = 0; col < matrix.countCols; col++) {

			std::cout << "matrix[" << row+1 << "][" << col+1 << "] = ";
//			Вводим значение элемента матрицы
			std::cin >> matrix.values[row][col];
			if (std::cin.fail())
				throw std::invalid_argument("The value of the matrix element is incorrect");

//			Находим минимальный элемент матрицы
			if ((row == 0 && col == 0) || matrix.values[row][col] < matrix.minElement.value)
				matrix.minElement.fill(row, col, matrix.values[row][col]);

//			Находим среднюю сумму неотрицательных эементов
			if (matrix.values[row][col] >= 0)
				matrix.sumOfElements.add(matrix.values[row][col]);

		}
	}
	return matrix;
}

/**
 * Выводит на экран информацию о найденном минимальном элементе матрицы
 *
 * @param matrix - структура матрицы
 */
void printMinElementInfo(Matrix& matrix)
{
	if (!matrix.minElement.initialized) {
		std::cout << "The minimum element has not yet been found...";
		return;
	}

	std::cout << "Minimum element:" << std::endl;
	std::cout << " - row: " << matrix.minElement.row+1 << std::endl;
	std::cout << " - column: " << matrix.minElement.col+1 << std::endl;
	std::cout << " - value: " << matrix.minElement.value << std::endl;
}

/**
 * Выводит информацию о сумме неотрицательных элементов и их количестве
 *
 * @param matrix - структура матрицы
 */
void printSumElementsInfo(Matrix& matrix)
{
	std::cout << "Sum elements info: " << std::endl;
	std::cout << " - number of numbers: " << matrix.sumOfElements.countNumbers << std::endl;
	std::cout << " - sum of numbers: " << matrix.sumOfElements.value << std::endl;

	if (matrix.sumOfElements.countNumbers != 0)
		std::cout << " - average: " << ((float)matrix.sumOfElements.value / matrix.sumOfElements.countNumbers) << std::endl;
}

/**
 * Выводит матрицу на экран, а также производит замену минимального элемента
 * средним арифметическим из неотрицательных элементов, если withReplace == true
 *
 * @param matrix - структура матрицы
 * @param withReplace - нужно ли производить замену элемента
 */
void printMatrix(Matrix& matrix, bool withReplace = false)
{
	std::cout << ((withReplace) ? "Your modified matrix:" : "Your matrix:") << std::endl;

	if (withReplace && matrix.sumOfElements.countNumbers == 0)
		std::cout << "[WARNING] All elements of the matrix are negative: no replacement will be made..." << std::endl << std::endl;

	for (Uint row = 0; row < matrix.countRows; row++) {
		for (Uint col = 0; col < matrix.countCols; col++) {

			if (withReplace && matrix.sumOfElements.countNumbers != 0 && row == matrix.minElement.row && col == matrix.minElement.col)
				std::cout << std::setw(5) << std::right << ((float)matrix.sumOfElements.value / matrix.sumOfElements.countNumbers);
			else
				std::cout << std::setw(5) << std::right << matrix.values[row][col];

		}
		std::cout << std::endl;
	}
}