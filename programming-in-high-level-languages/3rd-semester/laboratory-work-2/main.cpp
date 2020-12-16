#include <iostream>
#include "Queue/Queue.h"
#include "Stack/Stack.h"

struct TempStruct {
    int value1 = 0;
    int value2 = 0;

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
    lab::Stack<int> tmpStackList ({ 1, 2, 3, 4, 5, 6, 7 });
    std::cout << "queue from stack: " << lab::Queue<int>(tmpStackList) << std::endl;
    std::cout << "prev stack:       " << tmpStackList << std::endl;

    lab::Stack<int> tmpStack = tmpStackList;
	std::cout << "stack operator=:  " << tmpStack << std::endl << std::endl;

    lab::Queue<int> tmpQueueList ({ 1, 2, 3, 4, 5, 6, 7 });
    std::cout << "stack from queue: " << lab::Stack<int>(tmpQueueList) << std::endl;
    std::cout << "prev queue:       " << tmpQueueList << std::endl;

    lab::Queue<int> tmp = tmpQueueList;
    std::cout << "queue operator=:  " << tmp << std::endl << std::endl;

    // очередь со списком инициализации
    lab::Queue<int> queueList ({ 1, 2, 3, 4, 5, 6, 7 });
    std::cout << "queue init list: " << queueList << std::endl;

    // очередь по дефолту
    lab::Queue<int> queueDefault;
    queueDefault.push(1);
    queueDefault.push(2);
    queueDefault.push(3);
    queueDefault.push(4);
    queueDefault.push(5);
    queueDefault.push(6);
    queueDefault.push(7);
    std::cout << "queue default:   " << queueDefault << std::endl;

    // очередь через копирование
    lab::Queue<int> queueCopy(queueDefault);
    std::cout << "queue copy:      " << queueCopy << std::endl;

    std::cout << std::endl;

    // изъятие элементов из очереди
    try {
        auto elementsNum = queueDefault.size();
        for (std::size_t i = 0; i < elementsNum; i++) {
            std::cout << "popped element: " << queueDefault.pop() << std::endl;
        }

        // искусственно делаем ошибку, которая выбросит исключение:
        // все элементы уже извлечены, но мы пытаемся получить очередное значение
        std::cout << "check pop: " << queueDefault.check_pop() << std::endl << std::endl;

    } catch (std::exception& e) {
        std::cout << std::endl << "[CAUGHT EXCEPTION] " << e.what() << std::endl << std::endl;
    }

    // проверяем, пустая ли очередь после извлечения элементов
    std::cout << "queue default empty check: " << queueDefault.empty() << std::endl;

    std::cout << std::endl;

    // снова выводим очереди
    std::cout << "queue init list: " << queueList << std::endl;
    std::cout << "queue default:   " << queueDefault << std::endl;
    std::cout << "queue copy:      " << queueCopy << std::endl;

    std::cout << std::endl;

    // очищаем очередь
    queueList.clean();
    std::cout << "queue list is empty (after clear): " << queueList.empty() << std::endl;

    std::cout << std::endl;

    // проверка очередь на других типах
    try {
        lab::Queue<double> queueDouble ({ 1.2, 3.4, 5.6, 7.8, 9.0 });
        std::cout << "double: " << queueDouble << std::endl;

        lab::Queue<TempStruct> queueStruct ({ TempStruct(1, 2), TempStruct(3, 4), TempStruct(5, 6) });
        std::cout << "struct: " << queueStruct << std::endl;

        lab::Queue<std::string> queueString ({ "1.2", "3.4", "5.6", "7.8", "9.0" });
        std::cout << "string: " << queueString << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR] " << e.what() << std::endl;
    }
    
    return EXIT_SUCCESS;
}
