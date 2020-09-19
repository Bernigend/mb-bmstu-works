//
// Created by Bernigend on 19.09.2020.
//

#ifndef LABORATORY_WORK_1_STACKEXCEPTIONS_H
#define LABORATORY_WORK_1_STACKEXCEPTIONS_H

#include <exception>

namespace lab {

	class PopOutOfRange : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override {
			return "cannot pop an item from an empty stack";
		}
	};

}

#endif //LABORATORY_WORK_1_STACKEXCEPTIONS_H
