/**
 * Created by Bernigend 04.12.2019.
 *
 * ----
 *
 * Задача №2 из задачника
 * Определить сумму правых частей всех натуральных чисел из интервала (A,B)
 *
 * Входные данные:
 *  - два числа A и B (1 <= A <= B <= 10^15)
 */


#include <iostream>
#include <cmath>

using namespace std;

// Сокращаем тип переменной
typedef unsigned long long int uLLint;

// Указываем ограничение на входные данные
const long long int MAX_INPUT_NUM = 1000000000000000;

uLLint findRightPartOfNum(uLLint num);

int main()
{
	uLLint startNum, endNum;

	cout << "Input the beginning and end of the interval: ";
	cin >> startNum >> endNum;
	cout << endl;

//	Если произошла ошибка при вводе, прекращаем работу
	if (cin.fail()) {
		cout << "Error: you entered incorrect values";
		return EXIT_FAILURE;
	}

//	Если начало интервала больше его конца, меняем местами
	if (startNum > endNum) {
		uLLint tmp;

		tmp = startNum;
		startNum = endNum;
		endNum = tmp;
	}

//	Если введённые числа больше максимального разрешённого, прекращаем работу
	if (startNum > MAX_INPUT_NUM || endNum > MAX_INPUT_NUM) {
		cout << "Error: number cannot be more than " << MAX_INPUT_NUM << endl;
		return EXIT_FAILURE;
	}

	uLLint sum = 0;

	for (; startNum <= endNum; startNum++) {
		sum += findRightPartOfNum(startNum);
	}

	cout << sum;
}

/**
 * Возвращает правую часть числа в 10 системе счисления
 * --
 * Рассматривает число справа налево, считая количество бинарных нулей до первой единицы (степень двойки)
 * для перевода числа в 10 систему счисления, чтобы не хранить лишние данные.
 *
 * @param num - число в 10 системе счисления
 * @return правая часть числа в 10 системе счисления
 */
uLLint findRightPartOfNum(uLLint num)
{
	int power = 0; // степень числа

	while (num) {
		if (num % 2 == 0)
			power++;
		else
			break;

		num /= 2;
	}

	return pow(2, power);
}