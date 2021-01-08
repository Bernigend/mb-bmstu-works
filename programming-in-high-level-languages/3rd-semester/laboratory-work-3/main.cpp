#include <iostream>
#include <thread>
#include <ctime>
#include "AvlTree/AvlTree.h"

class TestClass {
protected:
    int value = 0;
public:
    TestClass() = default;

    explicit TestClass(int _value) : value(_value) {}

    TestClass(const TestClass& testClass) = default;

    TestClass(TestClass&& testClass) = default;

    TestClass& operator=(const TestClass& testClass) = default;

    friend bool operator>(const TestClass& left, const TestClass& right)
    {
        return left.value > right.value;
    }

    friend bool operator<(const TestClass& left, const TestClass& right)
    {
        return left.value < right.value;
    }

    friend std::ostream& operator<<(std::ostream& out, const TestClass& testClass)
    {
        return out << testClass.value;
    }
};

template<typename Type>
void testTreeByRandomInsertRemove(AvlTree<Type>& tree, int randAdd = 10)
{
    srand(std::time(nullptr) + randAdd);
    for (int i = 0; i <= 200; i++) {
        if (std::rand() % 2) {
            tree.insert(i / 5);
        } else {
            tree.remove(i / 5);
        }
    }
}

int main()
{
    // создаём АВЛ дерево
    AvlTree<int> tree_int{5, 6, 23, 1, 89, 34};

    // выводим в порядке возрастания
    std::cout << "tree_int:    " << tree_int << std::endl;
    std::cout << std::endl;

    // ищем элемент
    if (!tree_int.search(23)) {
        std::cout << "The value is not found" << std::endl;
    } else {
        std::cout << "The value is found" << std::endl;
    }
    std::cout << std::endl;

    // удаление элемента
    tree_int.remove(8);
    std::cout << "tree_int:    " << tree_int << std::endl;

    // удаление несуществующего элемента
    tree_int.remove(45784);
    std::cout << "tree_int:    " << tree_int << std::endl;
    std::cout << std::endl;

    // вывод элементов в различном порядке
    std::cout << "PreOrder:    ";
    tree_int.preOrderPrint(std::cout);
    std::cout << std::endl;
    std::cout << "InOrder:     ";
    tree_int.inOrderPrint(std::cout);
    std::cout << std::endl;
    std::cout << "PostOrder:   ";
    tree_int.postOrderPrint(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;

    // добавление дерева в дерево, очистка дерева
    AvlTree<int> subtree_int{6, 8, 45, 23};
    std::cout << "subtree_int: " << subtree_int << std::endl;
    tree_int.insert(subtree_int);
    std::cout << "tree_int:    " << tree_int << std::endl;
    subtree_int.clearTree();
    std::cout << "subtree_int (after clear): " << subtree_int << std::endl;
    std::cout << std::endl;

    // получение поддерева
    AvlTree<int> subtree = tree_int.getSubtree(5);
    if (!subtree.isEmpty()) {
        std::cout << "Tree: " << subtree << std::endl;
    } else {
        std::cout << "Tree is not found" << std::endl;
    }
    std::cout << std::endl;

    // проверка типа double
    AvlTree<double> tree_double{6, 54.34, 9};
    std::cout << "tree_double: " << tree_double << std::endl;
    std::cout << std::endl;

    // проверка на классе
    AvlTree<TestClass> tree_class{
            TestClass(5),
            TestClass(67),
            TestClass(34),
            TestClass(3)
    };
    std::cout << "tree_class:  " << tree_class << std::endl;
    std::cout << std::endl;

    // проверка на случайные запись/удаление элемента
    AvlTree<int> tree_rand1;

    testTreeByRandomInsertRemove(tree_rand1, 50);
    testTreeByRandomInsertRemove(tree_rand1, 100);
    testTreeByRandomInsertRemove(tree_rand1, 150);
    testTreeByRandomInsertRemove(tree_rand1, 200);

    std::cout << "tree_rand1: " << tree_rand1 << std::endl;
    std::cout << std::endl;

    // проверка на thread-safe
    AvlTree<int> tree_th1;

    std::thread thread_1([&tree_th1]() { testTreeByRandomInsertRemove(tree_th1, 50); });
    std::thread thread_2([&tree_th1]() { testTreeByRandomInsertRemove(tree_th1, 100); });
    std::thread thread_3([&tree_th1]() { testTreeByRandomInsertRemove(tree_th1, 150); });
    std::thread thread_4([&tree_th1]() { testTreeByRandomInsertRemove(tree_th1, 200); });

    thread_1.join();
    thread_2.join();
    thread_3.join();
    thread_4.join();

    std::cout << "tree_th1: " << tree_th1 << std::endl;
    std::cout << std::endl;

    return 0;
}
