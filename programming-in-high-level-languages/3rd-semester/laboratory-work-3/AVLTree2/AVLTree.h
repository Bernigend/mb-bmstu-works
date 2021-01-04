//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_8_AVLTREE_H
#define LABORATORY_WORK_8_AVLTREE_H


#include <ostream>
#include <functional>
#include <mutex>
#include "Node.h"

template<typename Type>
class AVLTree {
protected:
    mutable std::recursive_mutex _mtx;
    Node<Type>* root = nullptr;

    Node<Type>* getMinNode(Node<Type>* node) const;
    int nodeHeight(Node<Type>* node) const;
    void fixNodeHeight(Node<Type>* node);
    int getNodeBalance(Node<Type>* node) const;

    Node<Type>* fixNodeBalanceInsert(Node<Type>* node, Type value);
    Node<Type>* fixNodeBalanceRemove(Node<Type>* node);
    Node<Type>* rightRotation(Node<Type>* node);
    Node<Type>* doubleRightRotation(Node<Type>* node);
    Node<Type>* leftRotation(Node<Type>* node);
    Node<Type>* doubleLeftRotation(Node<Type>* node);

    Node<Type>* insert(Type, Node<Type>* node);
    Node<Type>* remove(Type value, Node<Type>* node);
    Node<Type>* search(Type, Node<Type>* node) const;

    void preOrderMove(Node<Type>* node, const std::function<void(Type)>& callback) const;
    void inOrderMove(Node<Type>* node, const std::function<void(Type)>& callback) const;
    void postOrderMove(Node<Type>* node, const std::function<void(Type)>& callback) const;

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