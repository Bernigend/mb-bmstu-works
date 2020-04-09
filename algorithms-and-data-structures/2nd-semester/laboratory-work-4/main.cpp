#include <iostream>
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Dack/Dack.h"

int main() {
    Stack stack;
    for (int i = 0; i < 10; i++) {
        stack.add(i);
    }

    std::cout << "Stack:" << std::endl;
    std::cout << " - Sample:" << std::endl;
    std::cout << stack << std::endl;
    stack.get();
    std::cout << " - Without 1st element:" << std::endl;
    std::cout << stack << std::endl;
    std::cout << std::endl;

    // -------------------- //

    Queue queue;
    for (int i = 0; i < 10; i++) {
        queue.add(i);
    }

    std::cout << "Queue:" << std::endl;
    std::cout << " - Sample:" << std::endl;
    std::cout << queue << std::endl;
    queue.get();
    std::cout << " - Without 1st element:" << std::endl;
    std::cout << queue << std::endl;
    std::cout << std::endl;

    // -------------------- //

    Dack dack;
    for (int i = 0; i < 10; i++) {
        dack.add(i);
    }

    std::cout << "Dack:" << std::endl;
    std::cout << " - To start:" << std::endl;
    std::cout << dack << std::endl;

    for (int i = 10; i < 20; i++) {
        dack.addEnd(i);
    }

    std::cout << " - To end:" << std::endl;
    std::cout << dack << std::endl;

    std::cout << " - Last element:" << std::endl;
    std::cout << dack.getEnd()->value << std::endl;

    std::cout << " - Without last element:" << std::endl;
    std::cout << dack << std::endl;

    std::cout << " - First element:" << std::endl;
    std::cout << dack.get()->value << std::endl;

    std::cout << " - Without first element:" << std::endl;
    std::cout << dack << std::endl;

    return 0;
}
