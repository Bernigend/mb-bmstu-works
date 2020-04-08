#include <iostream>
#include "Table/Table.h"
#include "KeyOrdTable/KeyOrdTable.h"
#include "ValueOrdTable/ValueOrdTable.h"

int main() {
	// Простая таблица
	auto table = new Table;

	table->addToStart(1,1);
	table->addToStart(2,1);
	table->addToStart(3,4);

	table->addToEnd(1,1);
	table->addToEnd(2,1);
	table->addToEnd(3,4);

	std::cout << "Regular table:" << std::endl;
	table->print();
	std::cout << std::endl;

	// Таблица, отсортированная по ключам элементов
	auto keyOrdTable = new KeyOrdTable;

	keyOrdTable->addElement(3, 8);
	keyOrdTable->addElement(5, 1);
	keyOrdTable->addElement(2, 3);
	keyOrdTable->addElement(1, 56);
	keyOrdTable->addElement(4, 8);

	std::cout << "Table sorted by key:" << std::endl;
	keyOrdTable->print();
	std::cout << std::endl;

	// Таблица, отсортированная по значениям элементов
	auto valueOrdTable = new ValueOrdTable;

	valueOrdTable->addElement(5, 4);
	valueOrdTable->addElement(7, 10);
	valueOrdTable->addElement(1, 6);
	valueOrdTable->addElement(3, 2);

	std::cout << "Table sorted by value:" << std::endl;
	valueOrdTable->print();
}