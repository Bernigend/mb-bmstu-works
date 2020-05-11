#include <iostream>
#include "Set.h"

int main()
{
	// инициализация первого множества
    Set* set1 = new Set(size, numbers);
    set1->show();
    std::cout << std::endl;

	// инициализация второго множества
    int numbers2[3] = {2,2,6};
    Set* set2 = new Set(3, numbers2);
    set2->show();
    std::cout << std::endl;

    // объединение с помощью статического метода
    Set *set3 = Set::unite(set1, set2);
    set3->show();
	std::cout << std::endl;

    // объединение с помощью оператора +
    Set *set4 = *set1 + *set2;
    set4->show();
	std::cout << std::endl;

    // объединение с помощью метода
    set1->uniteWith(set2);
    set1->show();
}
