/**
 * Created by Bernigend on 27.12.2019.
 */

#ifndef EXAM_1ST_SEMESTER_STRUCTS_H
#define EXAM_1ST_SEMESTER_STRUCTS_H

typedef unsigned int Uint;

/**
 * Структура минимального элемента
 */
struct MinElement
{
	Uint row;
	Uint col;
	int value;
	bool initialized = false;

	explicit MinElement(Uint _row = 0, Uint _col = 0, int _value = 0, bool _initialized = false) {
		row = _row;
		col = _col;
		value = _value;
		initialized = _initialized;
	}

	void fill(Uint _row, Uint _col, int _value) {
		row = _row;
		col = _col;
		value = _value;
		initialized = true;
	}
};

/**
 * Структура суммы элементов
 */
struct SumOfElements
{
	int value = 0;
	Uint countNumbers = 0;

	void add(int _add) {
		value += _add;
		countNumbers++;
	}
};

/**
 * Структура матрицы
 */
struct Matrix
{
	int** values{};
	Uint countRows = 0;
	Uint countCols = 0;
	MinElement minElement;
	SumOfElements sumOfElements;
};

#endif //EXAM_1ST_SEMESTER_STRUCTS_H
