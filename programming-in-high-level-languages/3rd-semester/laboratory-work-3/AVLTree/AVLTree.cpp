//
// Created by Bernigend on 05.06.2020.
//

#include "AVLTree.h"


// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //


AVLTree::AVLTree() : root(nullptr) {}

AVLTree::AVLTree(const AVLTree& tree): root(nullptr)
{
	this->insert(tree);
}

AVLTree::AVLTree(AVLTree&& tree) noexcept
{
	this->root = tree.root;
	tree.root = nullptr;
}

AVLTree::~AVLTree()
{
	delete this->root;
	this->root = nullptr;
}


// --------------------- //
// СТАТИЧЕСКИЕ МЕТОДЫ
// --------------------- //


int AVLTree::max(int a1, int a2)
{
    return (a1 > a2) ? a1 : a2;
}


Node* AVLTree::getMinNode(Node* node)
{
    if (node == nullptr) return nullptr;
    else if (node->left == nullptr) return node;
    else return getMinNode(node->left);
}


int AVLTree::nodeHeight(Node* node)
{
    if (node == nullptr) return 0;
    return node->height;
}


void AVLTree::fixNodeHeight(Node* node)
{
    if (node == nullptr) return;
    node->height = max(nodeHeight(node->left), nodeHeight(node->right)) + 1;
}


int AVLTree::getNodeBalance(Node* node)
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
    if (node == nullptr) return new Node(value);

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


Node* AVLTree::search(int value, Node* node)
{
    if (node == nullptr) return nullptr;

    if (value < node->value) {
        return AVLTree::search(value, node->left);
    } else if (value > node->value) {
        return AVLTree::search(value, node->right);
    }

    return node;
}


void AVLTree::preOrderMove(Node* node, const std::function<void(int)>& callback)
{
	if (node == nullptr) { return; }
	callback(node->value);
	AVLTree::preOrderMove(node->left, callback);
	AVLTree::preOrderMove(node->right, callback);
}


void AVLTree::inOrderMove(Node* node, const std::function<void(int)>& callback)
{
	if (node == nullptr) { return; }
	AVLTree::inOrderMove(node->left, callback);
	callback(node->value);
	AVLTree::inOrderMove(node->right, callback);
}


void AVLTree::postOrderMove(Node* node, const std::function<void(int)>& callback)
{
	if (node == nullptr) { return; }
	AVLTree::postOrderMove(node->left, callback);
	AVLTree::postOrderMove(node->right, callback);
	callback(node->value);
}


// --------------------- //
// МЕТОДЫ
// --------------------- //


void AVLTree::insert(int value)
{
    this->root = AVLTree::insert(value, this->root);
}

void AVLTree::insert(const AVLTree& tree)
{
	AVLTree::inOrderMove(tree.root, [=](int value) {
		this->insert(value);
	});
}


void AVLTree::remove(int value)
{
    this->root = AVLTree::remove(value, this->root);
}

void AVLTree::clearTree()
{
	delete this->root;
	this->root = nullptr;
}


Node* AVLTree::search(int value) const
{
    return AVLTree::search(value, this->root);
}


void AVLTree::preOrderPrint(std::ostream& out) const
{
	AVLTree::preOrderMove(this->root, [&out](int value) {
		out << value << ' ';
	});
}

void AVLTree::inOrderPrint(std::ostream& out) const
{
	AVLTree::inOrderMove(this->root, [&out](int value) {
		out << value << ' ';
	});
}

void AVLTree::postOrderPrint(std::ostream& out) const
{
	AVLTree::postOrderMove(this->root, [&out](int value) {
		out << value << ' ';
	});
}


// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //


std::ostream& operator<< (std::ostream& out, const AVLTree& tree)
{
	tree.inOrderPrint(out);
	return out;
}