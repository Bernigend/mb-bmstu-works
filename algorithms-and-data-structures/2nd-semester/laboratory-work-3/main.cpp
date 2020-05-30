#include <iostream>
#include "string/String.h"

int main() {

	String string1 = String("Test");

	std::cout << "String1:  " << string1 << std::endl;
	std::cout << "Str1 len: " << string1.length() << std::endl;
	std::cout << "Str1 end: " << string1.getLastByte()->value << std::endl;
	std::cout << std::endl;

	// --------------------- //

	std::cout << "Str concat: " << string1 + " " + "program" << std::endl;
	std::cout << "String1:    " << string1 << std::endl;
	std::cout << std::endl;

	// --------------------- //

	String subString1 = string1.substr(1, 2);

	std::cout << "SubStr1: " << subString1 << std::endl;
	std::cout << "Str1:    " << string1 << std::endl;
	std::cout << std::endl;

	// --------------------- //

	std::cout << "Test - es:  " << string1 - "es" << std::endl;
	std::cout << "Test - T:   " << string1 - "T" << std::endl;
	std::cout << "Test - Tes: " << string1 - "Tes" << std::endl;
	std::cout << "Test - est: " << string1 - "est" << std::endl;
	std::cout << "Test - res: " << string1 - "res" << std::endl;
	std::cout << "String1: " << string1 << std::endl;
	std::cout << std::endl;

	// --------------------- //

	std::cout << "Result1: " << string1.search("es")->value << std::endl;
	std::cout << "Result2: " << string1.search("T")->value << std::endl;
	std::cout << "Result3: " << string1.search("st")->value << std::endl;
	std::cout << std::endl;

	// --------------------- //

	String string2 = String(string1);

	string2.addTo(0, "AAB");
	std::cout << "String2-1: " << string2 << std::endl;

	string2 = string2 - "AAB";
	std::cout << "String2-2: " << string2 << std::endl;
	string2.addTo(3, "BBA");
	std::cout << "String2-3: " << string2 << std::endl;

	std::cout << "String1:   " << string1 << std::endl;
	std::cout << std::endl;

	// --------------------- //

	String string3 = String("I cannot do this");
	string3.replace("I", "We");

	std::cout << "String3: " << string3 << std::endl;
	std::cout << std::endl;

	// --------------------- //

	bool tmp;
	std::cout << "Enter 0 or 1 to exit: ";
	std::cin >> tmp;

	return 0;
}
