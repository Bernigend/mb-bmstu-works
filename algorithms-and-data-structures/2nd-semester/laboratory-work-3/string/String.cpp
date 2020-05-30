#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 23.05.2020.
//

#include "String.h"

// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

/**
 * Конструктор по умолчанию
 */
String::String()
{
	this->head = NULL;
}

/**
 * Конструктор строки из массива символов
 * @param cString - массив символов char
 */
String::String(const char* cString)
{
	this->head = NULL;
	
	pByte* tmp  = &this->head;
	pByte  prev = NULL;
	uInt   i    = 0;

	while (cString[i] != '\0') {
		*tmp         = new Byte(cString[i]);
		(*tmp)->prev = prev;
		prev         = *tmp;
		tmp          = &((*tmp)->next);
		i++;
	}
}

/**
 * Конструктор копирования (создаёт новую строку на основе переданной)
 * @param string - строка для копирования
 */
String::String(const String& string)
{
	this->head = NULL;

	pByte  byteNow = string.head;
	pByte* tmp     = &this->head;
	pByte  prev    = NULL;

	while (byteNow != NULL) {
		*tmp         = new Byte(byteNow->value);
		(*tmp)->prev = prev;
		prev         = *tmp;
		tmp          = &((*tmp)->next);
		byteNow      = byteNow->next;
	}
}

/**
 * Защищённый конструктор, который копирует строку по байтам, начиная с start глубиной numberBytes
 * @param start - байт для начала копирования
 * @param numberBytes - количество байт для копирования
 */
String::String(const pByte& start, unsigned int numberBytes)
{
	this->head = NULL;

	pByte  byteNow = start;
	pByte* tmp     = &this->head;
	pByte  prev    = NULL;
	uInt   i       = 0;

	while (i < numberBytes && byteNow != NULL) {
		*tmp         = new Byte(byteNow->value);
		(*tmp)->prev = prev;
		prev         = *tmp;
		tmp          = &((*tmp)->next);
		byteNow      = byteNow->next;
		i++;
	}
}

/**
 * Деструктор
 */
String::~String()
{
	pByte current, next = this->head;
	while (next != NULL) {
		current = next;
		next    = current->next;
		delete current;
	}
}

// --------------------- //
// МЕТОДЫ
// --------------------- //

/**
 * Подставляет подстроку string на место position, сдвигая оставшуюся часть строки вправо
 * @param position - позиция символа в строке (отсчёт с нуля)
 * @param string - подстрока для подстановки
 */
void String::addTo(unsigned int position, const String& string)
{
	if (string.length() == 0) { return; }

	pByte startByte = this->operator[](position);
	if (startByte == NULL) { return; }

	if (startByte->prev == NULL) {
		startByte->prev = new Byte();
		startByte->prev->next = startByte;
	}

	startByte       = startByte->prev;
	pByte endByte   = startByte->next;
	String* newString = new String(string);

	if (newString->head == NULL) { return; }

	startByte->next       = newString->head;
	newString->head->prev = startByte;

	newString->getLastByte()->next = endByte;
	if (endByte != NULL) { endByte->prev = newString->getLastByte(); }

	if (position == 0) {
		this->head       = startByte->next;
		this->head->prev = NULL;
		delete startByte;
	}
}

/**
 * Ищет в строке подстроку string и возвращает байт первого вхождения строки
 * @param string - подстрока для поиска
 * @return байт первого вхождения строки или NULL, если search нет в строке
 */
pByte String::search(const String& string) const
{
	uInt  strLen  = string.length();
	pByte byteNow = this->head;
	uInt  i       = 0;

	while (byteNow != NULL) {
		if (byteNow->value == string.head->value) {
			if (this->substr(i, strLen) == string) { return this->operator[](i); }
		}
		byteNow = byteNow->next;
		i++;
	}

	return NULL;
}

/**
 * Заменяет в строке подстроку search на подстроку replace
 * @param search - подстрока для поиска
 * @param replace - подстрока для замены
 */
void String::replace(const String& search, const String& replace)
{
	uInt  strLen  = search.length();
	pByte byteNow = this->head;
	uInt  i       = 0;

	while (byteNow != NULL) {
		if (byteNow->value == search.head->value) {
			if (this->substr(i, strLen) == search) {
				*this = *this - search;
				this->addTo(static_cast<int>(i), replace);
			}
		}
		byteNow = byteNow->next;
		i++;
	}
}

/**
 * Возвращает подстроку длиной length от startPosition
 * @param startPosition - с какого символа вернуть подстроку (отсчёт с нуля)
 * @param length - длина подстроки, если 0, будет возвращена подстрока от startPosition до её конца
 * @return подстрока от startPosition длиной length
 */
String& String::substr(unsigned int startPosition, unsigned int length) const
{
	uInt strLen = this->length();
	if (startPosition > strLen-1) { return *(new String(*this)); }
	if (length == 0) { length = strLen - startPosition; }

	pByte startByte = this->operator[](startPosition);
	String* newString = new String(startByte, length);

	return *newString;
}

/**
 * @return длина строки
 */
unsigned int String::length() const
{
	pByte byteNow = this->head;
	uInt i       = 0;

	while (byteNow != NULL) {
		byteNow = byteNow->next;
		i++;
	}

	return i;
}

/**
 * @return последний байт строки или NULL, если такого нет
 */
pByte String::getLastByte()
{
	pByte byteNow = this->head;
	if (byteNow == NULL) { return NULL; }
	while (byteNow->next != NULL) { byteNow = byteNow->next; }
	return byteNow;
}

/**
 * Возвращает байт на позиции position из строки
 * @param position - позиция байта (отсчёт с нуля)
 * @return байт на позиции position
 */
pByte String::operator[] (unsigned int position)
{
	pByte byteNow = this->head;
	uInt i       = 0;
	while (i < position && byteNow != NULL) {
		i++;
		byteNow = byteNow->next;
	}
	return byteNow;
}

/**
 * Возвращает константный байт на позиции position из строки (константная версия)
 * @param position - позиция байта (отсчёт с нуля)
 * @return байт на позиции position
 */
const pByte& String::operator[] (unsigned int position) const
{
	const pByte* byteNow = &this->head;
	uInt i       = 0;
	while (i < position && byteNow != NULL) {
		i++;
		byteNow = &(*byteNow)->next;
	}
	return *byteNow;
}

/**
 * Возвращает символ строки на указанной позиции
 * @param position - позиция символа в строке (отсчёт от нуля)
 * @return символ на позиции position или '\0', если того нет в строке
 */
char String::at(unsigned int position) const
{
	pByte byte = this->operator[](position);
	if (byte == NULL) { return '\0'; }
	return byte->value;
}

// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //

/**
 * Конкатенация строк
 * @param left - строка для присоединения слева
 * @param right - строка для присоединения справа
 * @return новая строка, образованная соединением left и right
 */
String& operator+ (const String& left, const String& right)
{
	String* string1 = new String(left);
	String* string2 = new String(right);

	if (string1->head == NULL) { return *string2; }
	if (string2->head == NULL) { return *string1; }

	pByte end = string1->getLastByte();

	end->next     = string2->head;
	string2->head = end;

	return *string1;
}

/**
 * Вычёркивание подстроки
 * @param left - строка, из которой следует удалить подстроку
 * @param right - строка для удаления
 * @return новая строка left, но без right
 */
String& operator- (const String& left, const String& right)
{
	String* newString = new String(left);
	pByte*  tmp       = &newString->head;
	uInt    rLen      = right.length();
	uInt    i         = 0;

	while (*tmp != NULL) {
		if ((*tmp)->value == right.head->value) {
			if (newString->substr(i, rLen) == right) {
				pByte start = newString->operator[](i)->prev;
				pByte end   = (i+rLen >= newString->length()) ? NULL : newString->operator[](i + rLen);

				uInt k = 0;
				pByte current, next = newString->head;
				while (next != NULL) {
					current = next;
					next    = current->next;
					if (k >= i && k <= rLen+i-1) { delete current; }
					k++;
				}

				if (start == NULL) {
					newString->head = end;
				} else {
					start->next = end;
				}
				if (end != NULL) { end->prev = start; }
			}
		}

		i++;
		if ((*tmp) == NULL) { break; }
		tmp = &((*tmp)->next);
	}

	return *newString;
}

/**
 * @param out - поток для вывода
 * @param string - строка для вывода
 * @return
 */
std::ostream& operator<< (std::ostream& out, const String& string)
{
	pByte byteNow = string.head;
	while (byteNow != NULL) {
		out << byteNow->value;
		byteNow = byteNow->next;
	}
	return out;
}

/**
 * Сравнивает два объекта класса String
 * @param left
 * @param right
 * @return true, если оба объекта одинаковы
 */
bool operator== (const String& left, const String& right)
{
	if (left.length() != right.length()) { return false; }

	pByte leftTmp  = left.head;
	uInt position = 0;

	while (leftTmp != NULL) {
		if (right.at(position) != leftTmp->value) { return false;}
		leftTmp = leftTmp->next;
		position++;
	}

	return true;
}
#pragma clang diagnostic pop