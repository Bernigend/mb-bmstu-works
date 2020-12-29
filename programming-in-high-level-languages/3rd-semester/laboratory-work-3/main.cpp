#include <iostream>
#include "AVLTree/AVLTree.h"

class TestClass {
protected:
	int value = 0;
public:
	TestClass() = default;
	explicit TestClass(int _value) : value(_value) {}
	TestClass(const TestClass& testClass) = default;
	TestClass(TestClass&& testClass) = default;
	TestClass& operator= (const TestClass& testClass) = default;
	friend bool operator> (const TestClass& left, const TestClass& right)
	{
		return left.value > right.value;
	}
	friend bool operator< (const TestClass& left, const TestClass& right)
	{
		return left.value < right.value;
	}
	friend std::ostream& operator<< (std::ostream& out, const TestClass& testClass)
	{
		return out << testClass.value;
	}
};

int main() {
	// создаём АВЛ дерево
	AVLTree<int> tree_int;

	// заполняем данными
	tree_int.insert(5);
	tree_int.insert(8);
	tree_int.insert(23);
	tree_int.insert(1);
	tree_int.insert(89);
	tree_int.insert(34);

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

	tree_int.remove(8);
	std::cout << "tree_int:    " << tree_int << std::endl;
	std::cout << std::endl;

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

	AVLTree<int> subtree_int;
	subtree_int.insert(4);
	subtree_int.insert(8);
	subtree_int.insert(45);
	subtree_int.insert(23);
	std::cout << "subtree_int: " << subtree_int << std::endl;
	tree_int.insert(subtree_int);
	std::cout << "tree_int:    " << tree_int << std::endl;
	subtree_int.clearTree();
	std::cout << "subtree_int: " << subtree_int << std::endl;
	std::cout << std::endl;


	Node<int>* subtree_node = tree_int.getSubtree(8);
	if (subtree_node != nullptr) {
		std::cout << "Node address: " << subtree_node << "; Root value: " << subtree_node->value << std::endl;
	} else {
		std::cout << "Node is not found" << std::endl;
	}
	std::cout << std::endl;


	AVLTree<double> tree_double;
	tree_double.insert(6);
	tree_double.insert(54.34);
	tree_double.insert(9);
	std::cout << "tree_double: " << tree_double << std::endl;
	std::cout << std::endl;


	AVLTree<TestClass> tree_class;
	tree_class.insert(TestClass(5));
	tree_class.insert(TestClass(67));
	tree_class.insert(TestClass(34));
	tree_class.insert(TestClass(3));
	std::cout << "tree_class:  " << tree_class << std::endl;
	std::cout << std::endl;

	return 0;
}