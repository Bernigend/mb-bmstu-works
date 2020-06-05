#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
#include <iostream>
#include "AVLTree/AVLTree.h"

int main() {
    // создаём АВЛ дерево
    AVLTree tree = AVLTree();

    // заполняем данными
    tree.insert(5);
    tree.insert(8);
    tree.insert(23);
    tree.insert(1);
    tree.insert(89);
    tree.insert(34);

    // выводим в порядке возрастания
    std::cout << tree << std::endl;

    // ищем элемент
    Node* tmp = tree.search(23);
    if (tmp == NULL) {
        std::cout << "The value is not found" << std::endl;
    } else {
        std::cout << "Address: " << tmp << "; Value: " << tmp->value << ";" << std::endl;
    }

    tree.remove(8);
    std::cout << tree << std::endl;

    return 0;
}