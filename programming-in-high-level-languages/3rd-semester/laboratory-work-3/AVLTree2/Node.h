//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_NODE_H
#define LABORATORY_WORK_8_NODE_H


template<typename Type>
class Node {
public:
    Type value;
    int height = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    explicit Node(Type _value)
    {
        this->value = _value;
    }

    ~Node()
    {
        delete this->left;
        this->left = nullptr;
        delete this->right;
        this->right = nullptr;
    }
};

#endif //LABORATORY_WORK_8_NODE_H