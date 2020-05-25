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
String::String() : head{nullptr} {}

/**
 * Конструктор строки из массива символов
 * @param cString - массив символов char
 */
String::String(const char* cString) : String()
{
	pByte* tmp  = &this->head;
	pByte  prev = nullptr;
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
String::String(const String& string) : String()
{
	auto   byteNow = string.head;
	pByte* tmp     = &this->head;
	pByte  prev    = nullptr;

	while (byteNow != nullptr) {
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
String::String(const pByte& start, unsigned int numberBytes) : String()
{
	auto   byteNow = start;
	pByte* tmp     = &this->head;
	pByte  prev    = nullptr;
	uInt   i       = 0;

	while (i < numberBytes && byteNow != nullptr) {
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
	while (next != nullptr) {
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

	auto startByte = this->operator[](position);
	if (startByte == nullptr) { return; }

	if (startByte->prev == nullptr) {
		startByte->prev = new Byte();
		startByte->prev->next = startByte;
	}

	startByte      = startByte->prev;
	auto endByte   = startByte->next;
	auto newString = new String(string);

	if (newString->head == nullptr) { return; }

	startByte->next       = newString->head;
	newString->head->prev = startByte;

	newString->getLastByte()->next = endByte;
	if (endByte != nullptr) { endByte->prev = newString->getLastByte(); }

	if (position == 0) {
		this->head       = startByte->next;
		this->head->prev = nullptr;
		delete startByte;
	}
}

/**
 * Ищет в строке подстроку string и возвращает байт первого вхождения строки
 * @param string - подстрока для поиска
 * @return байт первого вхождения строки или nullptr, если search нет в строке
 */
pByte String::search(const String& string) const
{
	auto  strLen  = string.length();
	auto  byteNow = this->head;
	uInt  i       = 0;

	while (byteNow != nullptr) {
		if (byteNow->value == string.head->value) {
			if (this->substr(i, strLen) == string) { return this->operator[](i); }
		}
		byteNow = byteNow->next;
		i++;
	}

	return nullptr;
}

/**
 * Заменяет в строке подстроку search на подстроку replace
 * @param search - подстрока для поиска
 * @param replace - подстрока для замены
 */
void String::replace(const String& search, const String& replace)
{
	auto  strLen  = search.length();
	auto  byteNow = this->head;
	uInt  i       = 0;

	while (byteNow != nullptr) {
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
	auto strLen = this->length();
	if (startPosition > strLen-1) { return *(new String(*this)); }
	if (length == 0) { length = strLen - startPosition; }

	auto startByte = this->operator[](startPosition);
	auto newString = new String(startByte, length);

	return *newString;
}

/**
 * @return длина строки
 */
unsigned int String::length() const
{
	auto byteNow = this->head;
	uInt i       = 0;

	while (byteNow != nullptr) {
		byteNow = byteNow->next;
		i++;
	}

	return i;
}

/**
 * @return последний байт строки или nullptr, если такого нет
 */
pByte String::getLastByte()
{
	auto byteNow = this->head;
	if (byteNow == nullptr) { return nullptr; }
	while (byteNow->next != nullptr) { byteNow = byteNow->next; }
	return byteNow;
}

/**
 * Возвращает байт на позиции position из строки
 * @param position - позиция байта (отсчёт с нуля)
 * @return байт на позиции position
 */
pByte String::operator[] (unsigned int position)
{
	auto byteNow = this->head;
	uInt i       = 0;
	while (i < position && byteNow != nullptr) {
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
	auto byteNow = &this->head;
	uInt i       = 0;
	while (i < position && byteNow != nullptr) {
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
	auto byte = this->operator[](position);
	if (byte == nullptr) { return '\0'; }
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
	auto string1 = new String(left);
	auto string2 = new String(right);

	if (string1->head == nullptr) { return *string2; }
	if (string2->head == nullptr) { return *string1; }

	auto end = string1->getLastByte();

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
	auto   newString = new String(left);
	pByte* tmp       = &newString->head;
	auto   rLen      = right.length();
	uInt   i         = 0;

	while (*tmp != nullptr) {
		if ((*tmp)->value == right.head->value) {
			if (newString->substr(i, rLen) == right) {
				auto start = newString->operator[](i)->prev;
				auto end   = (i+rLen >= newString->length()) ? nullptr : newString->operator[](i + rLen);

				uInt k = 0;
				pByte current, next = newString->head;
				while (next != nullptr) {
					current = next;
					next    = current->next;
					if (k >= i && k <= rLen+i-1) { delete current; }
					k++;
				}

				if (start == nullptr) {
					newString->head = end;
				} else {
					start->next = end;
				}
				if (end != nullptr) { end->prev = start; }
			}
		}

		i++;
		if ((*tmp) == nullptr) { break; }
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
	auto byteNow = string.head;
	while (byteNow != nullptr) {
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

	auto leftTmp  = left.head;
	uInt position = 0;

	while (leftTmp != nullptr) {
		if (right.at(position) != leftTmp->value) { return false;}
		leftTmp = leftTmp->next;
		position++;
	}

	return true;
}