#include <iostream>
#include "Set.h"


int main()
{
    int numbers[3] = {1,2,3};
    Set* set1 = new Set(3, numbers);
    set1->show();
    std::cout << std::endl;

    int numbers2[3] = {2,2,6};
    Set* set2 = new Set(3, numbers2);
    set2->show();
    std::cout << std::endl;
}
