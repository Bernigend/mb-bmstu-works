#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 04.06.2020.
//

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
    explicit BinaryTree(char, BinaryTree* = NULL, BinaryTree* = NULL);

    static void push(char, BinaryTree*&);

    BinaryTree** getLeftPointer();
    BinaryTree** getRightPointer();
    BinaryTree* getLeft();
    BinaryTree* getRight();
    char getValue() const;
};


#endif //LABORATORY_WORK_6_BINARYTREE_H