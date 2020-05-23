//
// Created by Bernigend on 22.05.2020.
//

#ifndef LABORATORY_WORK_3_BYTE_H
#define LABORATORY_WORK_3_BYTE_H

struct Byte {
	char  value = '\0';
	Byte* next  = nullptr;
	Byte* prev  = nullptr;

	Byte() = default;

	explicit Byte(char c) {
		this->value = c;
	}
};

typedef Byte* pByte;

#endif //LABORATORY_WORK_3_BYTE_H
