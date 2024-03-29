#include <iostream>
#include "DateTime.h"

int main() {
    // 1
    DateTime dateTime1;
    std::cout << dateTime1.toString() << std::endl;
    dateTime1.print(std::cout);

    std::cout << std::endl << std::endl;

    // 2
    DateTime dateTime2(dateTime1);
    std::cout << dateTime2.toString("H:i:s d.m.Y");

    std::cout << std::endl << std::endl;

    // 3
    DateTime dateTime3(2020, 3, 22, 22, 33, 0);
    std::cout << dateTime3.isValid();

    std::cout << std::endl << std::endl;

    // 4
    DateTime dateTime4;
    std::cout << dateTime4.getDate() << " " << dateTime4.getTime();

    std::cout << std::endl << std::endl;

    // 5
    DateTime dateTime5;
    dateTime5 = DateTime::fromString("2020.08.12 12:12:12");
    dateTime5.print(std::cout);

    return 0;
}
