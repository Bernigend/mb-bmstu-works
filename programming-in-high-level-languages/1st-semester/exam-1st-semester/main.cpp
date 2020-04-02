/**
 * Created by Bernigend on 03.01.2020.
 *
 * ----
 *
 * Зачётная задача №4.
 * Найти среднее арифметическое из неотрицательных чисел и
 * заменить им минимальный элемент матрицы.
 */
#include <iostream>
#include "structs.h"
#include "functions.h"

int main() {
//	Структура матрицы
	auto* matrix = new Matrix;

	try {

//		Вводим размерность матрицы
		enterMatrixSizes(matrix);

//		Вводим значения элементов матрицы
		enterMatrixData(matrix);

	} catch (std::exception& e) {
		std::cerr << e.what();
		return EXIT_FAILURE;
	}

//	Выводим введённую матрицу
	printMatrix(matrix);
	std::cout << std::endl;

//	Выводим информацию о минимальном элементе матрицы
	printMinElementInfo(matrix);
	std::cout << std::endl;

//	Выводим информацию о сумме неотриц. элементов матрицы
	printSumOfElementsInfo(matrix);
	std::cout << std::endl;

//	Выводим матрицу с заменой минимального элемента
	printMatrix(matrix, true);

	return EXIT_SUCCESS;
}