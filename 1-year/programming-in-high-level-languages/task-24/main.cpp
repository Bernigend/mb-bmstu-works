/**
 * Created by Bernigend at 15.12.2019
 *
 * ----
 *
 *
 */

#include <iostream>
using namespace std;

typedef unsigned int Uint;

struct Interval {
	Uint start;
	Uint end;
};

Uint countOnesInBin(Uint number);

int main()
{
	Interval intervals[5];
	Uint tmpInt;
	short countIntervals;

	cout << "Input count of intervals: ";
	cin >> countIntervals;
	cout << endl;

	if (cin.fail()) {
		cout << "[Error] Something went wrong." << endl;
		return EXIT_FAILURE;
	}

//	Вводим интервалы
	for (Uint i = 0; i < countIntervals; i++) {
		cout << i + 1 << ". Input start and end of interval: ";
		cin >> intervals[i].start >> intervals[i].end;
		cout << endl;

		if (intervals[i].start > intervals[i].end) {
			tmpInt = intervals[i].start;
			intervals[i].start = intervals[i].end;
			intervals[i].end = tmpInt;
		}
	}

	cout << endl;
	cout << "Answer: " << endl;
	
//	Проходим по числам в интервалах
	Uint count = 0;
	for (Uint i = 0; i < countIntervals; i++) {
		for (Uint number = intervals[i].start; number <= intervals[i].end; number++) {
			if (countOnesInBin(number) % 2 == 1)
				count++;
		}

		cout << i + 1 << ". " << count << endl;
		count = 0;
	}

	return EXIT_SUCCESS;
}

/**
 * Возвращает количество единиц в двоичном представлении числа
 */
Uint countOnesInBin(Uint number)
{
	Uint count = 0;
	while (number) {
		if (number % 2 == 1)
			count++;
		number /= 2;
	}
	return count;
}