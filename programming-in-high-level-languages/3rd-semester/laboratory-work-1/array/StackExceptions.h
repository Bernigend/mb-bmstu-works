//
// Created by Bernigend on 19.09.2020.
//

#ifndef ARRAY_STACKEXCEPTIONS_H
#define ARRAY_STACKEXCEPTIONS_H

#include <exception>


namespace lab {

class bad_stack_capacity : public std::exception {
public:
	[[nodiscard]] const char *what() const noexcept override {
		return exception::what();
	}
};

class pop_out_of_index : public std::exception {
public:
	[[nodiscard]] const char *what() const noexcept override {
		return exception::what();
	}
};

}

#endif //ARRAY_STACKEXCEPTIONS_H
