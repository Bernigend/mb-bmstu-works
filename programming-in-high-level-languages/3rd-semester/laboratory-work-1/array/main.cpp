//
// Created by Bernigend on 19.09.2020.
//

#include <stack>
#include <queue>
#include <deque>
#include "Stack.hpp"

struct TempStruct {
	int value1 = 0;
	int value2 = 0;

	TempStruct() = default;

	TempStruct(int v1, int v2)
	{
		this->value1 = v1;
		this->value2 = v2;
	}

	friend std::ostream& operator<< (std::ostream& out, const TempStruct& tempStruct)
	{
		return out << "{ " << tempStruct.value1 << "; " << tempStruct.value2 << " }";
	}
};

int main() {

	std::stack<int> st;

	for (std::size_t i = 0; i < 999999999999999; i++)
		st.push(1);

//	st.emplace(1);
//
//	while(!st.empty()) {
//		auto tmp = st.top();
//		std::cout << tmp << " ";
//		st.pop();
//	}

//	std::queue<int> queue;
//
//	for (std::size_t i = 0; i < 10000000; i++)
//		queue.push(1);
//
//	while(!queue.empty()) {
//		auto tmp = queue.front();
//		std::cout << tmp << " ";
//		queue.pop();
//	}

//	std::deque<int> deque;
//
//	deque.push_back(1);

	return 0;

	// стек со списком инициализации
	lab::Stack<int> stackList ({ 1, 2, 3, 4, 5, 6, 7 });
	std::cout << "stack init list: " << stackList << std::endl;

	// стек по дефолту
	lab::Stack<int> stackDefault;
	stackDefault.push(1);
	stackDefault.push(2);
	stackDefault.push(3);
	stackDefault.push(4);
	stackDefault.push(5);
	stackDefault.push(6);
	stackDefault.push(7);
	std::cout << "stack default:   " << stackDefault << std::endl;

	// стек через копирование
	lab::Stack<int> stackCopy(stackDefault);
	std::cout << "stack copy:      " << stackCopy << std::endl;

	// стек с указанием вместимости
	lab::Stack<int> stackCapacity(20);
	stackCapacity.push(1);
	stackCapacity.push(2);
	stackCapacity.push(3);
	stackCapacity.push(4);
	stackCapacity.push(5);
	std::cout << "stack capacity:  " << stackCapacity << std::endl;

	std::cout << std::endl;

	// изъятие элементов из стека
	try {
		auto elementsNum = stackDefault.size();
		for (std::size_t i = 0; i < elementsNum; i++) {
			std::cout << "popped element: " << stackDefault.pop() << std::endl;
		}

		// искусственно делаем ошибку, которая выбросит исключение:
		// все элементы уже извлечены, но мы пытаемся получить очередное значение
		std::cout << "check pop: " << stackDefault.check_pop() << std::endl << std::endl;

	} catch (lab::pop_out_of_index& e) {
		std::cout << std::endl << "[ERROR] cannot pop element" << std::endl << std::endl;
	}

	// проверяем, пустой ли стек после извлечения элементов
	std::cout << "stack default empty: " << stackDefault.empty() << std::endl;

	std::cout << std::endl;

	// снова выводим стеки
	std::cout << "stack init list: " << stackList << std::endl;
	std::cout << "stack default:   " << stackDefault << std::endl;
	std::cout << "stack copy:      " << stackCopy << std::endl;

	std::cout << std::endl;

	// очищаем стек
	stackList.clear();
	std::cout << "stack init list empty (after clear): " << stackList.empty() << std::endl;

	std::cout << std::endl;

	// проверка стека на других типах
	try {
		lab::Stack<double> stackDouble ({ 1.2, 3.4, 5.6, 7.8, 9.0 });
		std::cout << "double: " << stackDouble << std::endl;

		lab::Stack<TempStruct> stackStruct ({ TempStruct(1, 2), TempStruct(3, 4), TempStruct(5, 6) });
		std::cout << "struct: " << stackStruct << std::endl;

		lab::Stack<std::string> stackString ({ "1.2", "3.4", "5.6", "7.8", "9.0" });
		std::cout << "string: " << stackString << std::endl;
	} catch (std::exception& e) {
		std::cout << "[ERROR] " << e.what() << std::endl;
	}

}