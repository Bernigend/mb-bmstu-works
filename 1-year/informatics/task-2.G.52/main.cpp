/**
 * Created by Bernigend at 05.12.2019.
 *
 * ----
 *
 * Задача II.G.52
 * Дано натуральное число N (N <= 100). Записать это число русскими словами (семнадцать, двести пятьдесят три, тысяча и т. д.). {6}
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
	string result, inputNumber;

//	Включаем поддержку кирилицы в консоли CLion
	system("chcp 65001");
//	setlocale(LC_ALL, "Russian");

//	Максимальное количество разрядов входного числа + 1
	const short MAX_BASIS = 5;

//	Основания
	const string basis[MAX_BASIS][10] = {
			{ "","","","","","","","","","" },
			{ "","одна","две","три","четыре","пять","шесть","семь","восемь","девять" },
			{ "","сто","двести","триста","четыреста","пятьсот","шестьсот","семьсот","восемьсот","девятьсот" },
			{ "","десять","двадцать","тридцать","сорок","пятьдесят","шестьдесят","семьдесят","восемьдесят","девяносто" },
			{ "","один","два","три","четыре","пять","шесть","семь","восемь","девять" },
	};

//	Падежные окончания тысяч
	const string ends[10] = { "тысяч", "тысяча", "тысячи", "тысячи", "тысячи", "тысячь", "тысячь", "тысячь", "тысячь", "тысячь" };

//	Числа от 10 до 19, т.к. их названия уникальны
	const string dec[10] = { "десять","одиннадцать","двенадцать","тринадцать","четырнадцать","пятнадцать","шестнадцать","семнадцать","восемнадцать","девятнадцать" };


//	Вводим число
	cout << "Input number (max. digit number - " << MAX_BASIS - 1 << "): ";
	cin >> inputNumber;
	cout << endl;

//	Если введено число, количество разрядов которого больше допустимого, прекращаем работу
	if (inputNumber.size() > MAX_BASIS-1) {
		cout << "Error: maximum digit number - " << MAX_BASIS-1;
		return EXIT_FAILURE;
	}

	if (inputNumber == "0")
		result = "нуль";
	else {
		result = "Answer: ";

		for (unsigned int i = 0; i < inputNumber.size(); i++) {

			if (i != 0 && inputNumber[i-1] != ' ')
				result.append(" ");

//			Если очередь дошла до пятизначного числа, начинающегося на 1 - обрабатываем как числа от 10 до 19
			if (inputNumber.size() - i == 5 && inputNumber[i] == '1') {
				result.append(dec[(int)inputNumber[i+1]-48]);
				continue;
			}

//			Если очередь дошла до тысячи, обрабатываем как количество тысяч + тысяча в нужном падеже
			if (inputNumber.size() > 3 && inputNumber.size() - i == 4) {
				result.append(basis[MAX_BASIS - inputNumber.size() + i][(int)inputNumber[i] - 48]);
				result.append(" ");
				result.append(ends[(int)inputNumber[inputNumber.size() - (inputNumber.size() - i)]-48]);
				continue;
			}

//			Если очередь дошла до двузначного числа, начинающегося на 1 - обрабатываем как числа от 10 до 19
			if (inputNumber.size()-i == 2 && inputNumber[i] == '1') {
				result.append(dec[(int)inputNumber[inputNumber.size()-1]-48]);
				break;
			}

			result.append(basis[MAX_BASIS - inputNumber.size() + i][(int)inputNumber[i]-48]);
		}
	}

	cout << result;
	return 0;
}
