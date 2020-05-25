#pragma clang diagnostic push
#pragma ide diagnostic ignored "google-explicit-constructor"
//
// Created by Bernigend on 23.05.2020.
//

#ifndef LABORATORY_WORK_3_V2_STRING_H
#define LABORATORY_WORK_3_V2_STRING_H


#include <ostream>
#include "Byte.h"

typedef unsigned int uInt;

class String {
protected:
	pByte head;

	// копирует строку по байтам
	String(const pByte& start, unsigned int numberBytes);

public:
	// конструктор по умолчанию
	String();
	// констуктор с параметром
	String(const char*);
	// конструктор копирования
	String(const String&);
	// деструктор
	~String();

	// подставляет строку string на место position, сдвигая часть строки вправо
	void addTo(unsigned int, const String&);

	// контестный поиск
	pByte search(const String&) const;

	// контекстная замена
	void replace(const String&, const String&);

	// возвращает подстроку от start до end
	// если length = 0, будет возвращена строка от start до её конца
	String& substr(unsigned int, unsigned int = 0) const;

	// возвращает количество символов в строке
	unsigned int length() const;

	// возвращает последний символ (байт) строки
	pByte getLastByte();

	// возвращает симол (байт) строки на указанной позиции
	pByte operator[] (unsigned int);
	const pByte& operator[] (unsigned int) const;
	// возвращает симол строки на указанной позиции
	char at(unsigned int) const;

	// конкатенация 2х строк
	friend String& operator+ (const String&, const String&);
	// удаление подстроки
	friend String& operator- (const String&, const String&);

	// вывод строки
	friend std::ostream& operator<< (std::ostream&, const String&);

	// оператор сравнения
	friend bool operator== (const String&, const String&);
};


#endif //LABORATORY_WORK_3_V2_STRING_H

#pragma clang diagnostic pop