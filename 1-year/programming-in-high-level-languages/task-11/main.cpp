/**
 * Created by Bernigend at 15.12.2019.
 *
 * ----
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * Заменяет символы входной строки в соответствии с переданным массивом замен
 */
void convertString(string& stringToConvert, const char* symbols)
{
	for (unsigned int i = 0; i < stringToConvert.size(); i++) {
		if (symbols[stringToConvert[i]] != 0 && stringToConvert[i] >= 'a' && stringToConvert[i] <= 'z')
			stringToConvert[i] = symbols[stringToConvert[i]];

		if (symbols[stringToConvert[i]] != 0 && stringToConvert[i] >= 'A' && stringToConvert[i] <= 'Z')
			stringToConvert[i] = symbols[stringToConvert[i] + 32] - 32;
	}
}

int main()
{
	const string PATH_TO_INPUT_FILE  = R"(C:\BMSTU\programming-on-high-level-lang\task-11\texts\input.txt)";
	const string PATH_TO_OUTPUT_FILE = R"(C:\BMSTU\programming-on-high-level-lang\task-11\texts\output.txt)";
	char symbols[123] = { 0 };

//	Символы первой строки
	symbols['b'] = 'z';
	symbols['c'] = 'x';
	symbols['d'] = 'w';
	symbols['f'] = 'v';
	symbols['g'] = 't';
	symbols['h'] = 's';
	symbols['j'] = 'r';
	symbols['k'] = 'q';
	symbols['l'] = 'p';
	symbols['m'] = 'n';

//	Символы второй строки
	symbols['z'] = 'b';
	symbols['x'] = 'c';
	symbols['w'] = 'd';
	symbols['v'] = 'f';
	symbols['t'] = 'g';
	symbols['s'] = 'h';
	symbols['r'] = 'j';
	symbols['q'] = 'k';
	symbols['p'] = 'l';
	symbols['n'] = 'm';

//	Открываем входной файл для чтения
	ifstream inputFile(PATH_TO_INPUT_FILE);
	if (!inputFile.is_open()) {
		std::cout << "[Error] Input file can`t be opened" << endl;
		return EXIT_FAILURE;
	}

//	Открываем выходной файл для записи
	ofstream outputFile(PATH_TO_OUTPUT_FILE);
	if (!outputFile.is_open()) {
		std::cout << "[Error] Output file can`t be opened" << endl;
		return EXIT_FAILURE;
	}

	string tmpString;

//	Читаем входной файл построчно и делаем операции со строками, записывая их в выходной файл
	while (getline(inputFile, tmpString)) {
		convertString(tmpString, symbols);
		outputFile << tmpString << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}