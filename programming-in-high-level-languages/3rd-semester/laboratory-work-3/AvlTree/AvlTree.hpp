//
// Created by Bernigend on 04.01.2021.
//

#include "AvlTree.h"


// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //


template<typename Type>
AvlTree<Type>::AvlTree() : _root(nullptr) {}


template<typename Type>
AvlTree<Type>::AvlTree(const AvlTree<Type>& tree) : AvlTree()
{
    this->insert(tree);
}


template<typename Type>
AvlTree<Type>::AvlTree(AvlTree&& tree) noexcept : AvlTree()
{
    this->_root = tree._root;
    tree._root = nullptr;
}


template<typename Type>
AvlTree<Type>::~AvlTree()
{
    if (this->_root == nullptr) return;

    this->_root->clearChildren();
    delete this->_root;
    this->_root = nullptr;
}


template<typename Type>
AvlTree<Type>::AvlTree(std::initializer_list<Type> values_list) : AvlTree()
{
    for (const Type& value : values_list) {
        this->insert(value);
    }
}


// --------------------- //
// PROTECTED МЕТОДЫ
// --------------------- //


template<typename Type>
int AvlTree<Type>::getNodeHeight(const Node* node) const noexcept
{
    return node == nullptr ? 0 : node->height;
}

template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::nodeRightRotation(Node* node)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);

    Node* tmp_left = node->left;
    Node* tmp_left_right = tmp_left->right;

    tmp_left->right = node;
    node->left = tmp_left_right;

    node->height = std::max(this->getNodeHeight(node->left), this->getNodeHeight(node->right)) + 1;
    tmp_left->height = std::max(this->getNodeHeight(tmp_left->left), this->getNodeHeight(tmp_left->right)) + 1;

    return tmp_left;
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::nodeLeftRotation(Node* node)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);

    Node* tmp_right = node->right;
    Node* tmp_right_left = tmp_right->left;

    tmp_right->left = node;
    node->right = tmp_right_left;

    node->height = std::max(this->getNodeHeight(node->left), this->getNodeHeight(node->right)) + 1;
    tmp_right->height = std::max(this->getNodeHeight(tmp_right->left), this->getNodeHeight(tmp_right->right)) + 1;

    return tmp_right;
}


template<typename Type>
int AvlTree<Type>::getNodeBalance(const Node* node) const noexcept
{
    if (node == nullptr) return 0;
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    return this->getNodeHeight(node->left) - this->getNodeHeight(node->right);
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::getNodeWithMinimalValue(Node* node)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}


template<typename Type>
void AvlTree<Type>::updateNodeHeight(Node* node) noexcept
{
    if (node == nullptr) return;
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    node->height = 1 + std::max(this->getNodeHeight(node->left), this->getNodeHeight(node->right));
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::updateNodeBalanceAfterInsert(Node* node, const Type& value)
{
    if (node == nullptr) return nullptr;

    std::lock_guard<std::recursive_mutex> locker(_mtx);

    int balance = this->getNodeBalance(node);

    if (balance > 1 && value < node->left->value) {
        return this->nodeRightRotation(node);
    }

    if (balance < -1 && value > node->right->value) {
        return this->nodeLeftRotation(node);
    }

    if (balance > 1 && value > node->left->value) {
        node->left = this->nodeLeftRotation(node->left);
        return this->nodeRightRotation(node);
    }

    if (balance < -1 && value < node->right->value) {
        node->right = this->nodeRightRotation(node->right);
        return this->nodeLeftRotation(node);
    }

    return node;
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::updateBalanceAfterRemove(Node* root)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);

    int balance = this->getNodeBalance(root);

    if (balance > 1 && this->getNodeBalance(root->left) >= 0) {
        return this->nodeRightRotation(root);
    }

    if (balance > 1 && this->getNodeBalance(root->left) < 0) {
        root->left = this->nodeLeftRotation(root->left);
        return this->nodeRightRotation(root);
    }

    if (balance < -1 && this->getNodeBalance(root->right) <= 0) {
        return this->nodeLeftRotation(root);
    }

    if (balance < -1 && this->getNodeBalance(root->right) > 0) {
        root->right = this->nodeRightRotation(root->right);
        return this->nodeLeftRotation(root);
    }

    return root;
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::insert(Node* node, const Type& value)
{
    if (node == nullptr) return new Node(value);

    std::lock_guard<std::recursive_mutex> locker(_mtx);

    if (value < node->value) {
        node->left = this->insert(node->left, value);
    } else if (value > node->value) {
        node->right = this->insert(node->right, value);
    } else {
        return node;
    }

    this->updateNodeHeight(node);
    return this->updateNodeBalanceAfterInsert(node, value);
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::deleteNode(Node* root, const Type& value)
{
    if (root == nullptr) return root;

    std::lock_guard<std::recursive_mutex> locker(_mtx);

    if (value < root->value) {
        root->left = this->deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = this->deleteNode(root->right, value);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = this->getNodeWithMinimalValue(root->right);
            root->value = temp->value;
            root->right = this->deleteNode(root->right, temp->value);
        }
    }

    if (root == nullptr) return root;
    this->updateNodeHeight(root);
    return this->updateBalanceAfterRemove(root);
}


template<typename Type>
typename AvlTree<Type>::Node* AvlTree<Type>::searchNode(Node* node, const Type& value) const
{
    if (node == nullptr) return nullptr;

    std::lock_guard<std::recursive_mutex> locker(_mtx);

    if (value < node->value) {
        return this->searchNode(node->left, value);
    } else if (value > node->value) {
        return this->searchNode(node->right, value);
    }

    return node;
}


template<typename Type>
void AvlTree<Type>::preOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler)
{
    if (node == nullptr) return;
    nodeValueHandler(node->value);
    AvlTree::preOrderMove(node->left, nodeValueHandler);
    AvlTree::preOrderMove(node->right, nodeValueHandler);
}


template<typename Type>
void AvlTree<Type>::inOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler)
{
    if (node == nullptr) { return; }
    AvlTree::inOrderMove(node->left, nodeValueHandler);
    nodeValueHandler(node->value);
    AvlTree::inOrderMove(node->right, nodeValueHandler);
}


template<typename Type>
void AvlTree<Type>::postOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler)
{
    if (node == nullptr) { return; }
    AvlTree::postOrderMove(node->left, nodeValueHandler);
    AvlTree::postOrderMove(node->right, nodeValueHandler);
    nodeValueHandler(node->value);
}


// --------------------- //
// PUBLIC МЕТОДЫ
// --------------------- //


template<typename Type>
void AvlTree<Type>::insert(const Type& value)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    this->_root = this->insert(this->_root, value);
}


template<typename Type>
void AvlTree<Type>::insert(const AvlTree<Type>& tree)
{
    AvlTree::inOrderMove(tree._root, [=](const Type& value) {
        std::lock_guard<std::recursive_mutex> locker(_mtx);
        this->insert(value);
    });
}


template<typename Type>
void AvlTree<Type>::remove(const Type& value)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    this->_root = this->deleteNode(this->_root, value);
}


template<typename Type>
void AvlTree<Type>::clearTree()
{
    if (this->_root == nullptr) return;

    this->_root->clearChildren();
    delete this->_root;
    this->_root = nullptr;
}


template<typename Type>
bool AvlTree<Type>::search(const Type& value) const
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    return this->searchNode(this->_root, value) != nullptr;
}


template<typename Type>
AvlTree<Type>* AvlTree<Type>::getSubtree(const Type& rootValue)
{
    std::lock_guard<std::recursive_mutex> locker(_mtx);
    Node* foundNode = this->searchNode(this->_root, rootValue);
    if (foundNode == nullptr) return nullptr;

    auto* result = new AvlTree<Type>;
    AvlTree::inOrderMove(foundNode, [&result](const Type& value) {
        result->insert(value);
    });

    return result;
}


template<typename Type>
void AvlTree<Type>::preOrderPrint(std::ostream& out) const
{
    AvlTree::preOrderMove(this->_root, [&out](const Type& value) {
        out << value << ' ';
    });
}


template<typename Type>
void AvlTree<Type>::inOrderPrint(std::ostream& out) const
{
    AvlTree::inOrderMove(this->_root, [&out](const Type& value) {
        out << value << ' ';
    });
}


template<typename Type>
void AvlTree<Type>::postOrderPrint(std::ostream& out) const
{
    AvlTree::postOrderMove(this->_root, [&out](const Type& value) {
        out << value << ' ';
    });
}


// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //


template<typename OutputType>
std::ostream& operator<<(std::ostream& out, const AvlTree<OutputType>& tree)
{
    tree.inOrderPrint(out);
    return out;
}
