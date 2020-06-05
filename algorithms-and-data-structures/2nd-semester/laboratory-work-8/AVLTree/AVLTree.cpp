#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#include "AVLTree.h"


// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //


AVLTree::AVLTree() : root(NULL) {}


// --------------------- //
// СТАТИЧЕСКИЕ МЕТОДЫ
// --------------------- //


int AVLTree::max(int a1, int a2)
{
    return (a1 > a2) ? a1 : a2;
}


/**
 * @param node
 * @return узел с самым минимальным значением
 */
Node* AVLTree::getMinNode(Node* node)
{
    if (node == NULL) return NULL;
    else if (node->left == NULL) return node;
    else return getMinNode(node->left);
}


int AVLTree::nodeHeight(Node* node)
{
    if (node == NULL) return 0;
    return node->height;
}


void AVLTree::fixNodeHeight(Node* node)
{
    if (node == NULL) return;
    node->height = max(nodeHeight(node->left), nodeHeight(node->right)) + 1;
}


int AVLTree::getNodeBalance(Node* node)
{
    if (node == NULL) return 0;
    return nodeHeight(node->left) - nodeHeight(node->right);
}


/**
 * Восстанавливает баланс дерева после вставки нового узла
 * @param node
 * @param value
 * @return
 */
Node* AVLTree::fixNodeBalanceInsert(Node* node, int value)
{
    int balance = getNodeBalance(node);

    if (balance > 1) {
        if (value > node->left->value) node->left = leftRotation(node->left);
        return rightRotation(node);
    } else if (balance < -1) {
        if (value < node->right->value) node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}


/**
 * Восстанавливает баланс дерева после удаления узла
 * @param node
 * @return
 */
Node* AVLTree::fixNodeBalanceRemove(Node* node)
{
    if (nodeHeight(node->left) - nodeHeight(node->right) == 2)
    {
        if (nodeHeight(node->left->left) - nodeHeight(node->left->right) == 1)
            return leftRotation(node);
        else return doubleLeftRotation(node);
    }
    else if (nodeHeight(node->right) - nodeHeight(node->left) == 2)
    {
        if (nodeHeight(node->right->right) - nodeHeight(node->right->left) == 1)
            return rightRotation(node);
        else return doubleRightRotation(node);
    }

    return node;
}


Node* AVLTree::rightRotation(Node* node)
{
    Node* tmp1 = node->left;
    Node* tmp2 = tmp1->right;

    tmp1->right = node;
    node->left = tmp2;

    fixNodeHeight(node);
    fixNodeHeight(tmp1);

    return tmp1;
}


Node* AVLTree::doubleRightRotation(Node* node)
{
    node->left = leftRotation(node->left);
    return rightRotation(node);
}


Node* AVLTree::leftRotation(Node* node)
{
    Node* tmp1 = node->right;
    Node* tmp2 = tmp1->left;

    tmp1->left = node;
    node->right = tmp2;

    fixNodeHeight(node);
    fixNodeHeight(tmp1);

    return tmp1;
}


Node* AVLTree::doubleLeftRotation(Node* node)
{
    node->right = rightRotation(node->right);
    return leftRotation(node);
}


Node* AVLTree::insert(int value, Node* node)
{
    if (node == NULL) return new Node(value);

    if (value < node->value) {
        node->left = insert(value, node->left);
    } else if (value > node->value) {
        node->right = insert(value, node->right);
    } else return node; // избегаем повторения значений

    fixNodeHeight(node);
    return fixNodeBalanceInsert(node, value);
}


Node* AVLTree::remove(int value, Node* node)
{
    Node* temp;

    if (node == NULL) return NULL;
    else if (value < node->value) node->left  = remove(value, node->left);
    else if (value > node->value) node->right = remove(value, node->right);
    // если у дерева два потомка
    else if (node->left && node->right)
    {
        temp = getMinNode(node->right);
        node->value = temp->value;
        node->right = remove(node->value, node->right);
    }
    // если у дерева 1 или 0 потомков
    else
    {
        temp = node;
        if (node->left == NULL) node = node->right;
        else if (node->right == NULL) node = node->left;
        delete temp;
    }

    if (node == NULL) return NULL;

    fixNodeHeight(node);
    return fixNodeBalanceRemove(node);
}


Node* AVLTree::search(int value, Node* node)
{
    if (node == NULL) return NULL;

    if (value < node->value) {
        return AVLTree::search(value, node->left);
    } else if (value > node->value) {
        return AVLTree::search(value, node->right);
    }

    return node;
}


void AVLTree::print(std::ostream& out, const Node* node)
{
    if (node == NULL) return;
    if (node->left != NULL) print(out, node->left);
    out << node->value << " ";
    if (node->right != NULL) print(out, node->right);
}


// --------------------- //
// МЕТОДЫ
// --------------------- //


void AVLTree::insert(int value)
{
    this->root = AVLTree::insert(value, this->root);
}


void AVLTree::remove(int value)
{
    this->root = AVLTree::remove(value, this->root);
}


Node* AVLTree::search(int value) const
{
    return AVLTree::search(value, this->root);
}


// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //


std::ostream& operator<< (std::ostream& out, const AVLTree& tree)
{
    if (tree.root == NULL) return out;
    tree.print(out, tree.root);
    return out;
}