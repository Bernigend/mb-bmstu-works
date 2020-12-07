//
// Created by bernigend on 07.12.2020.
// https://github.com/Bernigend/mb-bmstu-works/tree/master/programming-in-high-level-languages/3rd-semester/laboratory-work-1/array
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