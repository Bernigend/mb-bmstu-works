/**
 * Created by Bernigend on 03.01.2020.
 */

#include "structs.h"

#ifndef TEST_EXAM_FUNCTIONS_H
#define TEST_EXAM_FUNCTIONS_H

/**
 * Вводит количество строк и столбцов матрицы
 * @param matrix - структура матрицы
 * @throws std::invalid_argument
 */
void enterMatrixSizes(Matrix *matrix);

/**
 * Вводит значения элементов матрицы и проводит вычисления с ними
 * @param matrix - структура матрицы
 * @throws std::invalid_argument
 */
void enterMatrixData(Matrix* matrix);

/**
 * Выводит матрицу на экран
 * @param matrix - структура матрицы
 * @param withReplacement - нужна ли замена минимального элемента
 */
void printMatrix(Matrix *matrix, bool withReplacement = false);

/**
 * Выводит информацию о минимальном элементе матрицы на экран
 * @param matrix - структура матрицы
 */
void printMinElementInfo(Matrix *matrix);

/**
 * Выводит информацию о сумме элементов матрицы на экран
 * @param matrix - структура матрицы
 */
void printSumOfElementsInfo(Matrix *matrix);

#endif //TEST_EXAM_FUNCTIONS_H
