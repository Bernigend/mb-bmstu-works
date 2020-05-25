//
// Created by Bernigend on 23.05.2020.
//

#ifndef LABORATORY_WORK_3_V2_BYTE_H
#define LABORATORY_WORK_3_V2_BYTE_H

struct Byte {
	char  value = '\0';
	Byte* next = nullptr;
	Byte* prev = nullptr;

	Byte() = default;

	explicit Byte(char _value) {
		this->value = _value;
	}

	Byte(const Byte& byte) {
		this->value = byte.value;
		this->next  = byte.next;
		this->prev  = byte.prev;
	}
};

typedef Byte* pByte;

#endif //LABORATORY_WORK_3_V2_BYTE_H
