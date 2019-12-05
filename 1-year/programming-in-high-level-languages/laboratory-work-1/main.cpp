/**
 * Created by Bernigend on 20.11.2019.
 *
 * ---
 *
 * Лабораторная работа №1
 * Написать консольный скрипт, на вход которому будут даваться команды и аргументы к ним
 * Требуемые команды:
 * - 1. Вывод доступных команд
 * - 2. Вывод количества байт, отводимых под каждый тип переменной
 * - 3. Перевод числа в систему счисления с основанием 16
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
//	Если не передана конкретная команда, выводим информацию о лабораторной
	if (argc < 2) {
		cout << endl;
		cout << "Laboratory work No. 1" << endl << endl;
		cout << "Usage:" << endl;
		cout << "command [argument]" << endl << endl;
		cout << "To view a list of commands, use --help";
		cout << endl;

		return EXIT_SUCCESS;
	}

	string userCommand = argv[1];

	cout << endl;

//	Обработка команды на вывод списка команд
	if (userCommand == "--help") {

		cout << "Laboratory work No. 1" << endl << endl;
		cout << "Usage:" << endl;
		cout << setw(14) << left << "--help"         << " - displays a list of commands" << endl;
		cout << setw(14) << left << "--sizes"        << " - displays variable sizes" << endl;
		cout << setw(14) << left << "--hex [number]" << " - displays the number converted from 10 number system to 16 number system" << endl;

//	Обработка команды на вывод размеров переменных
	} else if (userCommand == "--sizes") {

		short width = 18;

		cout << "Variable sizes:" << endl;
		cout << endl;

		cout << setw(width) << left << "short" << " - " << sizeof(short) << " bytes" << endl;
		cout << setw(width) << left << "unsigned short" << " - " << sizeof(unsigned short) << " bytes" << endl;
		cout << setw(width) << left << "short int" << " - " << sizeof(short int) << " bytes" << endl;
		cout << setw(width) << left << "unsigned short int" << " - " << sizeof(unsigned short int) << " bytes" << endl;
		cout << setw(width) << left << "int" << " - " << sizeof(int) << " bytes" << endl;
		cout << setw(width) << left << "unsigned int" << " - " << sizeof(unsigned int) << " bytes" << endl;
		cout << setw(width) << left << "long" << " - " << sizeof(int) << " bytes" << endl;
		cout << setw(width) << left << "unsigned long" << " - " << sizeof(int) << " bytes" << endl;
		cout << setw(width) << left << "long long" << " - " << sizeof(int) << " bytes" << endl;
		cout << setw(width) << left << "unsigned long long" << " - " << sizeof(int) << " bytes" << endl;
		cout << endl;

		cout << setw(width) << left << "float" << " - " << sizeof(float) << " bytes" << endl;
		cout << setw(width) << left << "double" << " - " << sizeof(double) << " bytes" << endl;
		cout << setw(width) << left << "long double" << " - " << sizeof(long double) << " bytes" << endl;
		cout << endl;

		cout << setw(width) << left << "char" << " - " << sizeof(char) << " bytes" << endl;
		cout << setw(width) << left << "string" << " - " << sizeof(string) << " bytes" << endl;
		cout << endl;

		cout << setw(width) << left << "bool" << " - " << sizeof(bool) << " bytes";

//	Обработка команды, которая переводит переданное число в 16 систему счисления
	} else if (userCommand == "--hex") {

		if (argc < 3) {
			cout << "You must enter a number in the 10 number system as an argument." << endl;
			cout << "For example: --hex 12" << endl;

			return EXIT_SUCCESS;
		}

		printf_s("Entered number (%s) in 16 number system: %X", argv[2], stoi(argv[2]));

	}

	cout << endl;
	return EXIT_SUCCESS;
}