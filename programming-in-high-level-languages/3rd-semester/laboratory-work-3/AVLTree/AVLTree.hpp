//
// Created by Bernigend on 05.06.2020.
//

#include <algorithm>
#include "AVLTree.h"


// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //


template<typename Type>
AVLTree<Type>::AVLTree(): root(nullptr) {}

template<typename Type>
AVLTree<Type>::AVLTree(const AVLTree& tree): root(nullptr)
{
	this->insert(tree);
}

template<typename Type>
AVLTree<Type>::AVLTree(AVLTree&& tree) noexcept
{
	this->root = tree.root;
	tree.root = nullptr;
}

template<typename Type>
AVLTree<Type>::~AVLTree()
{
	delete this->root;
	this->root = nullptr;
}


// --------------------- //
// СТАТИЧЕСКИЕ МЕТОДЫ
// --------------------- //

template<typename Type>
Node<Type>* AVLTree<Type>::getMinNode(Node<Type>* node)
{
    if (node == nullptr) return nullptr;
    else if (node->left == nullptr) return node;
    else return getMinNode(node->left);
}


template<typename Type>
int AVLTree<Type>::nodeHeight(Node<Type>* node)
{
    if (node == nullptr) return 0;
    return node->height;
}


template<typename Type>
void AVLTree<Type>::fixNodeHeight(Node<Type>* node)
{
    if (node == nullptr) return;
    node->height = std::max(nodeHeight(node->left), nodeHeight(node->right)) + 1;
}


template<typename Type>
int AVLTree<Type>::getNodeBalance(Node<Type>* node)
{
    if (node == nullptr) return 0;
    return nodeHeight(node->left) - nodeHeight(node->right);
}


/**
 * Восстанавливает баланс дерева после вставки нового узла
 * @param node
 * @param value
 * @return
 */
template<typename Type>
Node<Type>* AVLTree<Type>::fixNodeBalanceInsert(Node<Type>* node, Type value)
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
template<typename Type>
Node<Type>* AVLTree<Type>::fixNodeBalanceRemove(Node<Type>* node)
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


template<typename Type>
Node<Type>* AVLTree<Type>::rightRotation(Node<Type>* node)
{
    Node<Type>* tmp1 = node->left;
    Node<Type>* tmp2 = tmp1->right;

    tmp1->right = node;
    node->left = tmp2;

    fixNodeHeight(node);
    fixNodeHeight(tmp1);

    return tmp1;
}


template<typename Type>
Node<Type>* AVLTree<Type>::doubleRightRotation(Node<Type>* node)
{
    node->left = leftRotation(node->left);
    return rightRotation(node);
}


template<typename Type>
Node<Type>* AVLTree<Type>::leftRotation(Node<Type>* node)
{
    Node<Type>* tmp1 = node->right;
    Node<Type>* tmp2 = tmp1->left;

    tmp1->left = node;
    node->right = tmp2;

    fixNodeHeight(node);
    fixNodeHeight(tmp1);

    return tmp1;
}


template<typename Type>
Node<Type>* AVLTree<Type>::doubleLeftRotation(Node<Type>* node)
{
    node->right = rightRotation(node->right);
    return leftRotation(node);
}


template<typename Type>
Node<Type>* AVLTree<Type>::insert(Type value, Node<Type>* node)
{
    if (node == nullptr) return new Node<Type>(value);

    if (value < node->value) {
        node->left = insert(value, node->left);
    } else if (value > node->value) {
        node->right = insert(value, node->right);
    } else return node; // избегаем повторения значений

    fixNodeHeight(node);
    return fixNodeBalanceInsert(node, value);
}


template<typename Type>
Node<Type>* AVLTree<Type>::remove(Type value, Node<Type>* node)
{
    Node<Type>* temp;

    if (node == nullptr) return nullptr;
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
        if (node->left == nullptr) node = node->right;
        else if (node->right == nullptr) node = node->left;
        delete temp;
    }

    if (node == nullptr) return nullptr;

    fixNodeHeight(node);
    return fixNodeBalanceRemove(node);
}


template<typename Type>
Node<Type>* AVLTree<Type>::search(Type value, Node<Type>* node)
{
    if (node == nullptr) return nullptr;

    if (value < node->value) {
        return AVLTree::search(value, node->left);
    } else if (value > node->value) {
        return AVLTree::search(value, node->right);
    }

    return node;
}


template<typename Type>
void AVLTree<Type>::preOrderMove(Node<Type>* node, const std::function<void(Type)>& callback)
{
	if (node == nullptr) { return; }
	callback(node->value);
	AVLTree::preOrderMove(node->left, callback);
	AVLTree::preOrderMove(node->right, callback);
}


template<typename Type>
void AVLTree<Type>::inOrderMove(Node<Type>* node, const std::function<void(Type)>& callback)
{
	if (node == nullptr) { return; }
	AVLTree::inOrderMove(node->left, callback);
	callback(node->value);
	AVLTree::inOrderMove(node->right, callback);
}


template<typename Type>
void AVLTree<Type>::postOrderMove(Node<Type>* node, const std::function<void(Type)>& callback)
{
	if (node == nullptr) { return; }
	AVLTree::postOrderMove(node->left, callback);
	AVLTree::postOrderMove(node->right, callback);
	callback(node->value);
}


// --------------------- //
// МЕТОДЫ
// --------------------- //


template<typename Type>
void AVLTree<Type>::insert(Type value)
{
    this->root = AVLTree::insert(value, this->root);
}

template<typename Type>
void AVLTree<Type>::insert(const AVLTree<Type>& tree)
{
	AVLTree::inOrderMove(tree.root, [=](Type value) {
		this->insert(value);
	});
}


template<typename Type>
void AVLTree<Type>::remove(Type value)
{
    this->root = AVLTree::remove(value, this->root);
}

template<typename Type>
void AVLTree<Type>::clearTree()
{
	delete this->root;
	this->root = nullptr;
}


template<typename Type>
bool AVLTree<Type>::search(Type value) const
{
    return AVLTree::search(value, this->root) != nullptr;
}

template<typename Type>
Node<Type>* AVLTree<Type>::getSubtree(Type rootValue)
{
	return AVLTree::search(rootValue, this->root);
}


template<typename Type>
void AVLTree<Type>::preOrderPrint(std::ostream& out) const
{
	AVLTree::preOrderMove(this->root, [&out](Type value) {
		out << value << ' ';
	});
}

template<typename Type>
void AVLTree<Type>::inOrderPrint(std::ostream& out) const
{
	AVLTree::inOrderMove(this->root, [&out](Type value) {
		out << value << ' ';
	});
}

template<typename Type>
void AVLTree<Type>::postOrderPrint(std::ostream& out) const
{
	AVLTree::postOrderMove(this->root, [&out](Type value) {
		out << value << ' ';
	});
}


// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //


template<typename Type>
std::ostream& operator<< (std::ostream& out, const AVLTree<Type>& tree)
{
	tree.inOrderPrint(out);
	return out;
}