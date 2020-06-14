#include <iostream>
#include "AV/AV.h"
#include "LinearList/LinearList.h"

int main() {
	std::cout << "------- AV FROM BINARY TREE -------" << std::endl << std::endl;

    AV av1 = AV("(((a+b)*c)/(c+d))");
    std::cout << av1 << std::endl;

    AV av2 = AV("(a+b)");
    std::cout << av2 << std::endl;

    AV av4 = AV("((a+b)/(c-d))");
    std::cout << av4 << std::endl;

    AV av5 = AV("(((a+b)/(c-d))*e)");
    std::cout << av5 << std::endl;
    std::cout << (std::string)av5 << std::endl << std::endl;

	std::cout << "------- AV FROM LINEAR LIST -------" << std::endl << std::endl;

	LinearList linearList;

	linearList = LinearList(av1);
	std::cout << linearList << std::endl;

	linearList = LinearList(av2);
	std::cout << linearList << std::endl;

	linearList = LinearList(av4);
	std::cout << linearList << std::endl;

	linearList = LinearList(av5);
	std::cout << linearList << std::endl;

	bool waitingExit;
	std::cout << "Enter any symbol to exit: ";
	std::cin >> waitingExit;

    return 0;
}