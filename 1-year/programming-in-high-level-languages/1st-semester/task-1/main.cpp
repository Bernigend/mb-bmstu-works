/**
 * Created by Bernigend at 26.11.2019.
 *
 * ---
 *
 * Задача №1 из задачника
 * Определить разницу в секундах между введёнными двумя датами и временем
 */

#include <iostream>
#include <ctime>
#include "functions.h"

using namespace std;

int main()
{
	int day1, day2;
	int month1, month2;
	int year1, year2;
	int hour1, hour2;
	int min1, min2;
	int sec1, sec2;
	int result;
	string error;

//	Вводим дату и время первого события
	cout << "Input date and time of 1st event like 'dd.mm.YYYY hh:mm:ss': ";
	result = scanf("%d.%d.%d %d:%d:%d", &day1, &month1, &year1, &hour1, &min1, &sec1);
	cout << endl;

	// Проверяем корректность данных
	error = checkInputData(day1, month1, year1, hour1, min1, sec1, result, 6);
	if (!error.empty()) {
		cout << error;
		return EXIT_FAILURE;
	}

//	Вводим дату и время второго события
	cout << "Input date and time of 2nd event like 'dd.mm.YYYY hh:mm:ss': ";
	result = scanf("%d.%d.%d %d:%d:%d", &day2, &month2, &year2, &hour2, &min2, &sec2);
	cout << endl;
	
	// Проверяем корректность данных
	error = checkInputData(day2, month2, year2, hour2, min2, sec2, result, 6);
	if (!error.empty()) {
		cout << error;
		return EXIT_FAILURE;
	}

//	Приводим введённые даты к специальной структуре
	struct tm tm1 = { sec1, min1, hour1, day1, month1 - 1, year1 - 1900 };
	struct tm tm2 = { sec2, min2, hour2, day2, month2 - 1, year2 - 1900 };
	
//	Получаем время в секундах
	time_t time1 = mktime(&tm1);
	time_t time2 = mktime(&tm2);

//	Находим разность между датами в секундах
	if (time1 != (time_t)(-1) && time2 != (time_t)(-1)) {
		double secondDiff = difftime(time2, time1);
		cout << "Diff: " << secondDiff << " sec";
	}
	else cout << "Undefined error";

	return EXIT_SUCCESS;
}