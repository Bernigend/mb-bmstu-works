#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 04.06.2020.
//

#include "BinaryTree.h"

// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

BinaryTree::BinaryTree(char _value, BinaryTree* _left, BinaryTree* _right)
: value(_value), left(_left), right(_right) {}

// --------------------- //
// МЕТОДЫ
// --------------------- //

void BinaryTree::push(char _value, BinaryTree*& node)
{
    node = new BinaryTree(_value);
}

char BinaryTree::getValue() const
{
    return this->value;
}

BinaryTree** BinaryTree::getLeftPointer()
{
    return &this->left;
}

BinaryTree** BinaryTree::getRightPointer()
{
    return &this->right;
}

BinaryTree* BinaryTree::getLeft()
{
    return this->left;
}

BinaryTree* BinaryTree::getRight()
{
    return this->right;
}