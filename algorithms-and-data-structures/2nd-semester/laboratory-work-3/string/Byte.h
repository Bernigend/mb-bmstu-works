//
// Created by Bernigend on 23.05.2020.
//

#ifndef LABORATORY_WORK_3_V2_BYTE_H
#define LABORATORY_WORK_3_V2_BYTE_H

struct Byte {
	char  value;
	Byte* next;
	Byte* prev;

	Byte() {
		this->value = '\0';
		this->next  = NULL;
		this->prev  = NULL;
	}

	explicit Byte(char _value) {
		this->value = _value;
		this->next  = NULL;
		this->prev  = NULL;
	}

	Byte(const Byte& byte) {
		this->value = byte.value;
		this->next  = byte.next;
		this->prev  = byte.prev;
	}
};

typedef Byte* pByte;

#endif //LABORATORY_WORK_3_V2_BYTE_H
