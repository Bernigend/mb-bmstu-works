#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_AVLTREE_H
#define LABORATORY_WORK_8_AVLTREE_H


#include <ostream>
#include "Node.h"

class AVLTree {
protected:
    Node* root;

    static int max(int a1, int a2);
    static Node* getMinNode(Node* node);

    static int nodeHeight(Node* node);
    static void fixNodeHeight(Node* node);

    static int getNodeBalance(Node* node);
    static Node* fixNodeBalanceInsert(Node* node, int value);
    static Node* fixNodeBalanceRemove(Node* node);

    static Node* rightRotation(Node* node);
    static Node* doubleRightRotation(Node* node);
    static Node* leftRotation(Node* node);
    static Node* doubleLeftRotation(Node* node);

    static Node* insert(int, Node* node);
    static Node* remove(int value, Node* node);
    static Node* search(int, Node* node);

    static void print(std::ostream& out, const Node* node);

public:
    AVLTree();

    void insert(int value);
    void remove(int value);
    Node* search(int value) const;

    friend std::ostream& operator<< (std::ostream& out, const AVLTree& tree);
};


#endif //LABORATORY_WORK_8_AVLTREE_H