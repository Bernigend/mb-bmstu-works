/**
 * Created by Bernigend at 24.12.2019.
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

int main()
{
//	Структура матрицы
	Matrix matrix;

	try {

//		Вводим размерность матрицы
		inputMatrixInfo(matrix);

//		Вводим значения элементов матрицы и проводим вычисления
		inputMatrixData(matrix);
		std::cout << std::endl;

	} catch (std::exception& e) {
		std::cerr << e.what();
		return EXIT_FAILURE;
	}

//	Выводим введённую матрицу
	printMatrix(matrix);
	std::cout << std::endl;

//	Выводим информацию о минимальном элементе
	printMinElementInfo(matrix);
	std::cout << std::endl;

//	Выводит информацию о сумме неотрицательных элементов
	printSumElementsInfo(matrix);
	std::cout << std::endl;

//	Выводим матрицу с заменой элемента
	printMatrix(matrix, true);

	return EXIT_SUCCESS;
}