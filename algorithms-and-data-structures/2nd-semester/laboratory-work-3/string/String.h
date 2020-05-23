//
// Created by Bernigend on 22.05.2020.
//

#ifndef LABORATORY_WORK_3_STRING_H
#define LABORATORY_WORK_3_STRING_H

#include <ostream>
#include "Byte.h"

typedef unsigned int uInt;

class String {
protected:
	pByte head = nullptr;

public:
	// конструктор по умолчанию
	String() {
		this->head = new Byte();
	}

	// конструктор с параметром
	String(const char* rawString) {
		if (rawString == nullptr) {
			this->head = new Byte();
			return;
		}

		pByte* tmp  = &this->head;
		pByte  prev = nullptr;
		unsigned int i = 0;

		while (rawString[i] != '\0') {
			*tmp         = new Byte(rawString[i]);
			(*tmp)->prev = prev;
			prev         = *tmp;
			tmp          = &(*tmp)->next;
			i++;
		}
	}

	// конструктор копирования
	String(const String& string) {
		if (string.head == nullptr) {
			this->head = new Byte();
			return;
		}

		auto byteNow = string.head;
		pByte* tmp   = &this->head;
		pByte  prev  = nullptr;

		while(byteNow != nullptr) {
			*tmp         = new Byte(byteNow->value);
			(*tmp)->prev = prev;
			prev         = *tmp;
			tmp          = &(*tmp)->next;
			byteNow      = byteNow->next;
		}
	}

	// деструктор
	~String() {
		pByte current, next = this->head;
		while (next != nullptr) {
			current = next;
			next    = current->next;
			delete current;
		}
	}

	// возвращает две строки, получившиеся в результате разделения на указанный символ
	// static String* split(const String& string, char divider);

	// удаляет подстроку
	void deleteSubstr(const String& string) {
		auto tmp        = this->head;
		uInt i          = 0, j;
		uInt strLen     = string.length();
		bool equivalent = true;

		while (tmp != nullptr) {
			if (tmp->value == string.head->value) {

				j = i;
				// проверяем, что это та самая требумая подстрока
				for (uInt k = 0; k < strLen; k++, j++) {
					if (string.at(k) != this->at(j)) {
						equivalent = false;
						break;
					}
					if (!equivalent) { break; }
				}

				j = i;
				// удаляем подстроку
				auto start = ((*this)[j]->prev == nullptr) ? this->head : (*this)[j]->prev;
				auto end   = (i+strLen > this->length()) ? nullptr : (*this)[i+strLen];

				uInt k = 0;
				pByte current, next = this->head;
				while (next != nullptr) {
					current = next;
					next    = current->next;

					if (k >= j && k <= strLen+j-1) {
						delete current;
					}

					k++;
				}

				if (start == this->head) {
					this->head = end;
				} else {
					start->next = end;
				}
				if (end != nullptr) { end->prev = start; }

				tmp = end;
				i++;
				continue;

			}
			i++;
			tmp = tmp->next;
		}
	}

	// возвращает объединение двух строк
	void concat(const String& string) {
		auto tmp = new String(string);
		auto end = this->getLastByte();

		if (end == nullptr) {
			this->head = tmp->head;
			tmp->head  = this->head;
			return;
		}

		tmp->head->prev = end;
		end->next       = tmp->head;
	}

	// возвращает длину строки
	unsigned int length() const {
		uInt i   = 0;
		auto tmp = this->head;

		while (tmp != nullptr) {
			i++;
			tmp = tmp->next;
		}

		return i;
	}

	// возвращает строку в виде массива char
	char* c_str() {
		auto strLen = this->length();
		if (strLen == 0) { return nullptr; }

		char* result = new char[this->length()];
		auto  tmp    = this->head;
		uInt  i      = 0;

		while (tmp != nullptr) {
			result[i] = tmp->value;
			i++;
			tmp = tmp->next;
		}

		return result;
	}

	// возвращает последний байт строки
	pByte getLastByte() const {
		if (this->head == nullptr) { return nullptr; }

		auto tmp = this->head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}

		return tmp;
	}

	// возвращает байт строки на указанной позиции
	pByte operator[] (unsigned int position) {
		auto tmp = this->head;
		uInt i   = 0;
		while (i < position && tmp != nullptr) {
			i++;
			tmp = tmp->next;
		}
		return tmp;
	}
	// возвращает значение байта строки на указанной позиции
	char at(unsigned int position) const {
		auto tmp = this->head;
		uInt i   = 0;
		while (i < position && tmp != nullptr) {
			i++;
			tmp = tmp->next;
		}
		return tmp->value;
	}

	// выводит строку
	friend std::ostream& operator<< (std::ostream& out, const String& string) {
		auto tmp = string.head;
		while (tmp != nullptr) {
			out << tmp->value;
			tmp = tmp->next;
		}
		return out;
	}
};


#endif //LABORATORY_WORK_3_STRING_H
