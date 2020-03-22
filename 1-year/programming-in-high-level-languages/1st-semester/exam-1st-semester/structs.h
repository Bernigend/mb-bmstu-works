/**
 * Created by Bernigend on 03.01.2020
 */

#ifndef TEST_EXAM_STRUCTS_H
#define TEST_EXAM_STRUCTS_H

typedef unsigned int Uint;

/**
 * Структура минимального элемента
 * @value - значение минимального элемента
 * @initialized - был ли найден минимальный элемент
 */
struct MinElement {
	int value = 0;
	bool initialized = false;

	/**
	 * Заполняет структуру данными об элементе
	 * @param _value - значение нового минимального элемента
	 */
	void set(int _value) {
		value = _value;
		initialized = true;
	}
};

/**
 * Структура суммы элементов
 * @value - сумма значений
 * @countNumbers - количество чисел
 */
struct SumOfElements {
	int value = 0;
	Uint countNumbers = 0;

	/**
	 * Прибавляет к сумме переданное число
	 * @param _add - число для сложения
	 */
	void add(int _add) {
		value += _add;
		countNumbers++;
	}
};

/**
 * Структура матрицы
 * @values - значения элементов матрицы
 * @numRows - количество строк матрицы
 * @numCols - количество столбцов матрицы
 * @minElement - структура минимального элемента
 * @sumOfElements - структура суммы элементов
 */
struct Matrix {
	int **values{};
	Uint numRows = 0;
	Uint numCols = 0;
	MinElement *minElement = new MinElement;
	SumOfElements *sumOfElements = new SumOfElements;
};

#endif //TEST_EXAM_STRUCTS_H
