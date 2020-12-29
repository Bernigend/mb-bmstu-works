//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_NODE_H
#define LABORATORY_WORK_8_NODE_H


struct Node {
    int value;
    int height;
    Node* left;
    Node* right;

    explicit Node(int _value)
    {
        this->value  = _value;
        this->height = 1;
        this->left   = nullptr;
        this->right  = nullptr;
    }

    ~Node()
    {
    	delete this->left;
    	delete this->right;
    }
};

#endif //LABORATORY_WORK_8_NODE_H