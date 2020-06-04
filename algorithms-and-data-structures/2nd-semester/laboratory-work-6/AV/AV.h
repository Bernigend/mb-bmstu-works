#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 04.06.2020.
//

#ifndef LABORATORY_WORK_6_AV_H
#define LABORATORY_WORK_6_AV_H


#include "../Tree/BinaryTree.h"

class AV {
protected:
    BinaryTree* values;

    void charToBinaryTree(const std::string&, BinaryTree*&);
    static void toLine(std::string&, BinaryTree*);

public:
    explicit AV(const std::string&);
    friend std::ostream& operator<< (std::ostream&, const AV&);
};


#endif //LABORATORY_WORK_6_AV_H