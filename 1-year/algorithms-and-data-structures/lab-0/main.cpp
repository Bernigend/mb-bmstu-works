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

//    set1->uniteWith(set2);
//    set1->intersectionWith(set2);
//    set1->difference(set2);

	Set *set3 = Set::unite(set1, set2);
	set3->show();

//    set1->show();
}
