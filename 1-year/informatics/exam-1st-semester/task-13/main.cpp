/**
 * Created by Bernigend on 13.01.2020.
 *
 * ----
 *
 * Описание задачи в Readme.md
 * --
 * Для поиска "серединки" числа записываем само число в виде строки, в которой ищем точку,
 * символ до и после которой - целая и дробная часть "серединки" соответственно;
 * Для удобного хранения данных используем структуру Number,
 * состоящую из значения "серединки" и действительного числа в виде строки);
 * Для последующей сортировки создан массив из структур Number;
 */
#include <iostream>
using namespace std;

/**
 * Структура действительного числа
 */
struct Number {
	/**
	 * Значение действительного числа в виде строки
	 */
	string strVal;

	/**
	 * Значение серединки в виде числа
	 */
	double middle = 0.0;
};

/**
 * Находим "серединку" числа.
 * Проходим по каждому символу введённого числа, ищем точку.
 * - опущены проверки существования элемента [k-1] и [k+1]
 *
 * Здесь взят принцип перевода символов типа char в int, зная,
 * что символы (char) 1-9 <=> числам (int) 49-57
 *
 * @param number
 */
void findMiddle(Number *number) {
	for (int k = 0; k < number->strVal.size(); k++)
		if (number->strVal[k] == '.')
			number->middle = ((int)number->strVal[k-1]-48) + ((double)(number->strVal[k+1]-48.0)*0.1);
}

int main() {
//	Количество действительных чисел
	int count = 0;
//	Объявляем массив из структур
	Number *numbers = nullptr;

	cout << "Enter the number of numbers: ";
	cin >> count;
	if (cin.fail()) {
		cerr << "[WARNING] Cin fails";
		return EXIT_FAILURE;
	}
	cout << endl;

	numbers = new Number [count];

//	Вводим действительное число и ищем его "серединку"
	for (int i = 0; i < count; i++) {
		cin >> numbers[i].strVal;
		findMiddle(&numbers[i]);
	}

//	Сортируем числа по полученным "серединкам"
	for (int i = 0; i < count; i++) {
		for (int k = 0; k < count - i - 1; k++) {
			if (numbers[k].middle > numbers[k+1].middle) {
				Number temp  = numbers[k];
				numbers[k]   = numbers[k+1];
				numbers[k+1] = temp;
			}
		}
	}

	cout << endl;

//	Выводим отсортированный массив
	for (int i = 0; i < count; i++)
		cout << numbers[i].strVal << endl;

	return EXIT_SUCCESS;
}