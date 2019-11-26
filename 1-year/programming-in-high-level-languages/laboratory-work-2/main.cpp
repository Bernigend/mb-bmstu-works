/**
 * Created by Bernigend on 26.11.2019.
 *
 * ---
 *
 * Лабораторная работа №2
 * Написать консольный скрипт, который будет выводить адреса сегментов памяти:
 * - TEXT segment (сегмент памяти, в котором хранятся коды инструкций программы)
 * - BSS segment (неинициализированные статические переменные или значение которых = 0)
 * - DATA segment (инициализированные статические переменные)
 * - Heap (сегмент памяти, который выделяется во время выполнения программы)
 * - Stack (сегмент памяти, который хранит локальные переменные функций + значения данных, передаваемых в функции)
 */

#include <iostream>
#include <iomanip>
using namespace std;

int bssSegment;
int dataSegment = 123;

int main(int argc, char* argv)
{
	int width = 14;

	// Попадает в text segment, потому что является кодом программы
	cout << setw(width) << left << "TEXT segment: " << main << endl;

	// Попадает в bss segment, потому что переменная не инициализирована
	cout << setw(width) << left << "BSS segment: " << &bssSegment << endl;
	
	// Попадает в data segment, потому что переменная инициализирована
	cout << setw(width) << left << "DATA segment: " << &dataSegment << endl;
	
	// Попадает в heap, потому что память выделяется во время работы программы
	cout << setw(width) << left << "HEAP: " << malloc(8) << endl;
	
	// Попадает в stack, потому что является локальный переменной функции
	cout << setw(width) << left << "Stack: " << &width << endl;

	return EXIT_SUCCESS;
}
