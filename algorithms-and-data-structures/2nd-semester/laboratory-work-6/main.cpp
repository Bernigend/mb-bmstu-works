#include <iostream>
#include "AV/AV.h"

int main() {
    AV av1 = AV("(((a+b)*c)/(c+d))");
    std::cout << av1 << std::endl;

    AV av2 = AV("(a+b)");
    std::cout << av2 << std::endl;

    AV av4 = AV("((a+b)/(c-d))");
    std::cout << av4 << std::endl;

    AV av5 = AV("(((a+b)/(c-d))*e)");
    std::cout << av5 << std::endl;

    return 0;
}