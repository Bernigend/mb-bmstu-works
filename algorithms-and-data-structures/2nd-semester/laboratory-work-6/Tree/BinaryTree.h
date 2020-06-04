#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 04.06.2020.
//

#include <ostream>

#ifndef LABORATORY_WORK_6_BINARYTREE_H
#define LABORATORY_WORK_6_BINARYTREE_H


#ifndef NULL
#define NULL 0
#endif

class BinaryTree {
    char value;
    BinaryTree* left;
    BinaryTree* right;

public:
    explicit BinaryTree(char _value, BinaryTree* _left = NULL, BinaryTree* _right = NULL)
    : value(_value), left(_left), right(_right) {}

    static void push(char _value, BinaryTree*& node)
    {
        node = new BinaryTree(_value);
    }

    char getValue() const
    {
        return this->value;
    }

    BinaryTree** getLeftPointer()
    {
        return &this->left;
    }

    BinaryTree** getRightPointer()
    {
        return &this->right;
    }

    BinaryTree* getLeft()
    {
        return this->left;
    }

    BinaryTree* getRight()
    {
        return this->right;
    }
};


#endif //LABORATORY_WORK_6_BINARYTREE_H