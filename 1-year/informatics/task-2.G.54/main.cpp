/**
 * Created by Bernigend at 05.12.2019.
 *
 * ----
 *
 * Задача II.G.54.
 * Задано число месяца и день недели.
 * Посчитать, сколько раз в двадцатом столетии на указанное число выпадал указанный день недели. {6}
 */

// Отключаем уведомления безопасности в Visual Studio
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// Сокращаем название типа
typedef unsigned int Uint;

Uint countMonthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Uint getWeekday(Uint day, Uint month, Uint year);

int main()
{
	Uint day, weekday;

	cout << "Enter the day number and the day number of the week separated by a space: ";
	cin >> day >> weekday;
	cout << endl;

//	Если произошла ошибка при вводе данных, либо они не удовлетворяют нас, прекращаем работу
	if (cin.fail() || day < 1 || day > 31 || weekday < 1 || weekday > 7) {
		cout << "Error: the day number or the day number of the week is invalid! Try again." << endl;
		return EXIT_FAILURE;
	}

	if (weekday == 7) weekday = 0;

	Uint count = 0;

	for (Uint year = 1901; year < 2001; year++) {
//		Если год високосный, то в феврале 29 дней
		(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) ?: countMonthDays[1] = 29;

		for (Uint month = 1; month < 13; month++) {
//			Если число не входит в числа месяца, пропускаем этот месяц
			if (day > countMonthDays[month])
					continue;

			if (getWeekday(day, month, year) == weekday)
				count++;
		}
	}

	cout << "Count: " << count << endl;

	return EXIT_SUCCESS;
}

/**
 * Возвращает номер дня недели (0 - воскресенье, 1 - понедельник, ...)
 * ---
 * Использует формулу "вечного календаря", см. https://ru.wikibooks.org/wiki/Реализации_алгоритмов/Вечный_календарь
 *
 * @param day - число месяца
 * @param month - месяц
 * @param year - год
 * @return номер дня недели (0 - воскресенье, 1 - понедельник, ...)
 */
Uint getWeekday(Uint day, Uint month, Uint year)
{
	if (month == 1 || month == 2) {
		year--;
		month += 10;
	} else
		month -= 2;

	return ((day + (31u*month)/12u + year + year/4u - year/100u + year/400u) % 7u);
}