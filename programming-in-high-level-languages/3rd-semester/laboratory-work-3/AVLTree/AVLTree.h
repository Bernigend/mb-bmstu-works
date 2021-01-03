//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_AVLTREE_H
#define LABORATORY_WORK_8_AVLTREE_H


#include <ostream>
#include <functional>
#include "Node.h"

template<typename Type>
class AVLTree {
protected:
    Node<Type>* root = nullptr;

    static Node<Type>* getMinNode(Node<Type>* node);
    static int nodeHeight(Node<Type>* node);
    static void fixNodeHeight(Node<Type>* node);
    static int getNodeBalance(Node<Type>* node);

    static Node<Type>* fixNodeBalanceInsert(Node<Type>* node, Type value);
    static Node<Type>* fixNodeBalanceRemove(Node<Type>* node);
    static Node<Type>* rightRotation(Node<Type>* node);
    static Node<Type>* doubleRightRotation(Node<Type>* node);
    static Node<Type>* leftRotation(Node<Type>* node);
    static Node<Type>* doubleLeftRotation(Node<Type>* node);

    static Node<Type>* insert(Type, Node<Type>* node);
    static Node<Type>* remove(Type value, Node<Type>* node);
    static Node<Type>* search(Type, Node<Type>* node);

    static void preOrderMove(Node<Type>* node, const std::function<void(Type)>& callback);
    static void inOrderMove(Node<Type>* node, const std::function<void(Type)>& callback);
    static void postOrderMove(Node<Type>* node, const std::function<void(Type)>& callback);

public:
    AVLTree();
    AVLTree(const AVLTree& tree);
    AVLTree(AVLTree&& tree) noexcept;
    ~AVLTree();

    void insert(Type value);
    void insert(const AVLTree& tree);
    void remove(Type value);
    void clearTree();
    bool search(Type value) const;

    Node<Type>* getSubtree(Type rootValue);

    void preOrderPrint(std::ostream& out) const;
    void inOrderPrint(std::ostream& out) const;
    void postOrderPrint(std::ostream& out) const;

    template<typename Type2>
    friend std::ostream& operator<<(std::ostream& out, const AVLTree<Type2>& tree);
};

#include "AVLTree.hpp"


#endif //LABORATORY_WORK_8_AVLTREE_H