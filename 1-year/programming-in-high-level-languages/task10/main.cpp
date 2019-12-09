/**
 * Created by Bernigend at 09.12.2019.
 *
 * ----
 *
 * Задача №10 из задачника А.В. Афанасьева
 * Во всех словах, начинающихся с маленькой латинской буквы, заменитьпервый символ на соответствующую прописную букву.
 * --
 * Входные данные: строка в файле CAPITAL.IN
 * Выходные данные: преобразованная строка в файле CAPITAL.OUT
 */

#include <iostream>
#include <fstream>

using namespace std;

void setUpperCase(char& symbol);

int main() {
	const string PATH_TO_INPUT_FILE  = R"(C:\Development\repositories\mb-bmstu-works\1-year\programming-in-high-level-languages\task10\texts\input.txt)";
	const string PATH_TO_OUTPUT_FILE = R"(C:\Development\repositories\mb-bmstu-works\1-year\programming-in-high-level-languages\task10\texts\output.txt)";

	ifstream inputFile;
	string tmpString;

	cout << "Input file: '" << PATH_TO_INPUT_FILE << "'" << endl;
//	Открываем файл и проверяем, открыт ли он
	inputFile.open(PATH_TO_INPUT_FILE);
	if (!inputFile.is_open()) {
		cout << "[Error] File can`t be opened" << endl;
		return EXIT_FAILURE;
	}

//	По условию задачи во входном файле содержится одна строка - считываем её
	getline(inputFile, tmpString);
//	Закрываем входной файл - он нам не нужен больше
	inputFile.close();

	cout << "The source text from a file:" << endl;
	cout << tmpString << endl;
	cout << endl;

//	Проходим по всем символам строки
	for (unsigned int i = 0; i < tmpString.size(); i++) {
		if (i == 0) {
			if (tmpString[i] != EOF || tmpString[i] != ' ') {
				setUpperCase(tmpString[i]);
			}
		} else {
			if (tmpString[i-1] == ' ') {
				setUpperCase(tmpString[i]);
			}
		}
	}

	cout << "Output file: '" << PATH_TO_OUTPUT_FILE << "'" << endl;
//	Пытаемся открыть файл для выходных данных
	ofstream outputFile(PATH_TO_OUTPUT_FILE);
	if (!outputFile.is_open()) {
		cout << "[Error] Can`t open file to write!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Converted string:" << endl;
	cout << tmpString;
	outputFile << tmpString;

	outputFile.close();
	tmpString.clear();
	return 0;
}

/**
 * Заменяет строчный латинский символ на прописной
 *
 * @param symbol - символ для замены
 */
void setUpperCase(char& symbol)
{
	if ((int)symbol >= 97 && (int)symbol <= 122)
		symbol = (char)((int)symbol-32);
}