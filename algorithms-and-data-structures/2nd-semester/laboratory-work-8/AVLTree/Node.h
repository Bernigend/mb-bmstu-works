#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_NODE_H
#define LABORATORY_WORK_8_NODE_H


#ifndef NULL
#define NULL 0
#endif

struct Node {
    int value;
    int height;
    Node* left;
    Node* right;

    explicit Node(int _value)
    {
        this->value  = _value;
        this->height = 1;      // TODO: или 0
        this->left   = NULL;
        this->right  = NULL;
    }
};

#endif //LABORATORY_WORK_8_NODE_H