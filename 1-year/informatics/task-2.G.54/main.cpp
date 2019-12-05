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
#include <ctime>

using namespace std;

int weekday(int day, int month, int year);

int main()
{
	int day, weekdayNumber;

	cout << "Input day number: ";
	cin >> day;
	cout << endl;

	if (cin.fail() || day < 1 || day > 31) {
		cout << "Error: the day number must be between 1 and 31!";
		return EXIT_FAILURE;
	}

	cout << "Input weekday (number 1-7): ";
	cin >> weekdayNumber;
	cout << endl;

	if (cin.fail() || weekdayNumber < 1 || weekdayNumber > 7) {
		cout << "Error: the weekday number must be between 1 and 7!";
		return EXIT_FAILURE;
	}
	
	if (weekdayNumber == 7) weekdayNumber = 0;

	int count = 0;

	for (int year = 1900; year < 2001; year++) {
		for (int month = 1; month <= 12; month++) {
			if (weekdayNumber == weekday(day, month, year))
				count++;
		}
	}

	cout << "Count: " << count << endl << endl;
}

/**
 * Определяет и возвращает номер дня недели
 *
 * @param int day - день месяца (1-31)
 * @param int month - номер месяца (1-12)
 * @param int year - год (1900-...)
 */
int weekday(int day, int month, int year)
{
	struct tm time_in{};
	struct tm* time_out;
	time_t time_tmp;

	time_in = { 0, 0, 0, day, month - 1, year - 1900 };
	time_tmp = mktime(&time_in);
	time_out = localtime(&time_tmp);

	if (time_out != nullptr)
		return time_out->tm_wday;
	else
		return -1;
}