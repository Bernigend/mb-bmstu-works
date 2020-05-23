#include <iostream>
#include "string/String.h"

int main() {

	String string1 = String("Hello");

	std::cout << "String1:  " << string1 << std::endl;
	std::cout << "Str1 len: " << string1.length() << std::endl;
	std::cout << "Str1 end: " << string1.getLastByte()->value << std::endl;
	std::cout << "Str1 end: " << string1.at(4) << std::endl;
	std::cout << std::endl;

	// ---

	String string2 = String(" world");

	std::cout << "Str2 len: " << string2.length() << std::endl;
	std::cout << std::endl;

	// ---

	String string3 = String(string1);
	string3.concat(string2);

	std::cout << "String3:  " << string3 << std::endl;
	std::cout << "Str3 len: " << string3.length() << std::endl;
	std::cout << "Str3 end: " << string3.getLastByte()->value << std::endl;
	std::cout << std::endl;

	// ---

	String string4 = String("");
	string4.concat(string1);

	std::cout << "String4:  " << string4 << std::endl;
	std::cout << "Str4 len: " << string4.length() << std::endl;
	std::cout << "Str4 end: " << string4.getLastByte()->value << std::endl;
	std::cout << std::endl;

	// ---

	string4.deleteSubstr("ll");
	std::cout << "String4:  " << string4 << std::endl;
	std::cout << "Str4 len: " << string4.length() << std::endl;
	std::cout << "Str4 end: " << string4.getLastByte()->value << std::endl;
	std::cout << std::endl;

	// ---

	std::cout << "Str1 len: " << string1.length() << std::endl;
	std::cout << "Str2 len: " << string2.length() << std::endl;
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
