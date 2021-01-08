//
// Created by Bernigend on 04.01.2021.
//

#ifndef LABORATORY_WORK_3_AVLTREE_H
#define LABORATORY_WORK_3_AVLTREE_H


#include <algorithm>
#include <functional>
#include <ostream>
#include <mutex>

template<typename Type>
class AvlTree {
protected:

    class Node {
    public:
        Type value{};
        int height = 0;
        Node* left = nullptr;
        Node* right = nullptr;

        explicit Node(Type value)
        {
            this->value = value;
        }

        void clearChildren()
        {
            if (this->left != nullptr) this->left->clearChildren();
            delete this->left;
            this->left = nullptr;

            if (this->right != nullptr) this->right->clearChildren();
            delete this->right;
            this->right = nullptr;
        }
    };

    mutable std::recursive_mutex _mtx;
    Node* _root = nullptr;

    /**
     * Возвращает height узла дерева
     * @param node
     * @return
     */
    int getNodeHeight(const Node* node) const noexcept;

    /**
     * Выполняет поворот направо указанного узла
     * @param node
     * @return
     */
    Node* nodeRightRotation(Node* node);

    /**
     * Выполняет поворот налево указанного узла
     * @param node
     * @return
     */
    Node* nodeLeftRotation(Node* node);

    /**
     * Возвращет значение балансировки указанного узла
     * @param node
     * @return
     */
    int getNodeBalance(const Node* node) const noexcept;

    /**
     * Возвращает узел с наименьшим значением
     * @param node
     * @return
     */
    Node* getNodeWithMinimalValue(Node* node);

    /**
     * Автоматически исправляет height указанного узла
     * @param node
     */
    void updateNodeHeight(Node* node) noexcept;

    /**
     * Автоматически исправляет балансировку указанного узла после добавления нового узла
     * @param node
     * @param value
     * @return
     */
    Node* updateNodeBalanceAfterInsert(Node* node, const Type& value);

    /**
     * Автоматически исправляет балансировку указанного узла после удаления
     * @param root
     * @return
     */
    Node* updateBalanceAfterRemove(Node* root);

    /**
     * Добавляет новый узел в дерево
     * @param node
     * @param value
     * @return
     */
    Node* insert(Node* node, const Type& value);

    /**
     * Удаляет узел из дерева
     * @param root
     * @param value
     * @return
     */
    Node* deleteNode(Node* root, const Type& value);

    /**
     * Выполняет поиск узла с указанным значением
     * @param node
     * @param value
     * @return
     */
    Node* searchNode(Node* node, const Type& value) const;

    /**
     * Выполняет Корень - Левое поддерево - Правое поддерево (КЛП) обход
     * @param node
     * @param nodeValueHandler
     */
    static void preOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler);

    /**
     * Выполняет Левое поддерево - Корень - Правое поддерево (ЛКП) обход
     * @param node
     * @param nodeValueHandler
     */
    static void inOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler);

    /**
     * Выполняет Левое поддерево - Правое поддерево - Корень (ЛПК) обход
     * @param node
     * @param nodeValueHandler
     */
    static void postOrderMove(Node* node, const std::function<void(const Type&)>& nodeValueHandler);

public:

    /**
     * Конструктор по умолчанию
     */
    AvlTree() noexcept;

    /**
     * Конструктор копирования
     * @param tree
     */
    AvlTree(const AvlTree<Type>& tree);

    /**
     * Конструктор перемещения
     * @param tree
     */
    AvlTree(AvlTree&& tree) noexcept;

    /**
     * Деструктор
     */
    ~AvlTree();

    /**
     * Конструктор со списком инициализации
     * @param values_list
     */
    AvlTree(std::initializer_list<Type> values_list);

    /**
     * Добавляет элемент в дерево
     * @param value
     */
    void insert(const Type& value);

    /**
     * Добавляет элементы другого дерева в текущее
     * @param tree
     */
    void insert(const AvlTree<Type>& tree);

    /**
     * Удаляет элемент из дерева
     * @param value
     */
    void remove(const Type& value);

    /**
     * Очищает дерево от элементов
     */
    void clearTree();

    /**
     * Возвращает true, если существует элемент с указанным значением
     * @param value
     * @return
     */
    bool search(const Type& value) const;

    /**
     * Возвращает true, если у дерева нет элементов
     * @return
     */
    bool isEmpty() const;

    /**
     * Возвращает поддерево, корнем которого является указанное значение
     * @param rootValue
     * @return
     */
    AvlTree<Type> getSubtree(const Type& rootValue);

    /**
     * Выводит элементы в порядке КЛП
     * @param out
     */
    void preOrderPrint(std::ostream& out) const;

    /**
     * Выводит элементы в порядке ЛКП
     * @param out
     */
    void inOrderPrint(std::ostream& out) const;

    /**
     * Выводит элементы в порядке ЛПК
     * @param out
     */
    void postOrderPrint(std::ostream& out) const;

    /**
     * Выводит элементы в порядке ЛПК
     * @param out
     */
    template<typename OutputType>
    friend std::ostream& operator<<(std::ostream& out, const AvlTree<OutputType>& tree);
};


#include "AvlTree.hpp"

#endif //LABORATORY_WORK_3_AVLTREE_H
