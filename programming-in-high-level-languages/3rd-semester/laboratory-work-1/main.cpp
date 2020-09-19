//
// Created by Bernigend on 19.09.2020.
//

#include "Stack.hpp"

int main() {
	lab::Stack<int> stack;

	std::cout << "stack size:  " << stack.size() << std::endl;
	std::cout << "stack empty: " << stack.empty() << std::endl << std::endl;

	stack.push(1);
	std::cout << "stack size:  " << stack.size() << std::endl;
	std::cout << "check pop:   " << stack.check_pop() << std::endl;
	std::cout << "stack empty: " << stack.empty() << std::endl << std::endl;

	stack.push(2);
	stack.push(3);
	stack.push(4);

	lab::Stack<int> stack2 (stack);
	std::cout << "stack2: " << stack2 << std::endl << std::endl;
	stack2.clear();
	std::cout << std::endl;

	std::cout << "stack1: " << stack << std::endl << std::endl;

	int tmp;

	tmp = stack.pop();
	std::cout << "popped " << tmp << std::endl;

	tmp = stack.pop();
	std::cout << "popped " << tmp << std::endl << std::endl;

	std::cout << "check pop:  " << stack.check_pop() << std::endl;
	std::cout << "stack size: " << stack.size() << std::endl << std::endl;

	tmp = stack.pop();
	std::cout << "popped " << tmp << std::endl;

	tmp = stack.pop();
	std::cout << "popped " << tmp << std::endl << std::endl;

	std::cout << "stack size:  " << stack.size() << std::endl;
	std::cout << "stack empty: " << stack.empty() << std::endl << std::endl;

	stack.push(34);
	stack.push(35);
	stack.push(37);
	stack.clear();

	stack.push(40);
}