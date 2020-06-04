#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 04.06.2020.
//

#include "AV.h"

// --------------------- //
// КОНСТРУКТОРЫ
// --------------------- //

AV::AV(const std::string& rawString) : values(NULL)
{
    this->charToBinaryTree(rawString, this->values);
}

// --------------------- //
// МЕТОДЫ
// --------------------- //

void AV::charToBinaryTree(const std::string& rawString, BinaryTree*& node)
{
    std::size_t stringLen   = rawString.length();
    std::size_t bracketsNum = 0;

    for (std::size_t i = 0; i < stringLen; i++) {
        char symbol = rawString[i];

        if (symbol == '(') {
            bracketsNum++;
            continue;
        }

        if (symbol == ')') {
            bracketsNum--;
            continue;
        }

        if (bracketsNum == 0 || bracketsNum == 1) {
            // избегаем случая (a+b), когда обработка идёт на a
            if (bracketsNum == 1 && symbol >= 'a' && symbol <= 'z') continue;
            // добавляем ариф. знак в дерево
            BinaryTree::push(symbol, node);
            // избегаем создания лишних узлов, когда rawString состоит из одного символа
            if (stringLen == 1) break;
            // обрабатываем левую часть операнда
            this->charToBinaryTree(
                    rawString.substr(bracketsNum, i-bracketsNum),
                    *node->getLeftPointer()
            );
            // обрабатываем правую часть операнда
            this->charToBinaryTree(
                    rawString.substr(i+1, stringLen-i-bracketsNum-1),
                    *node->getRightPointer()
            );
            break;
        }
    }
}

void AV::toLine(std::string& outString, BinaryTree* node)
{
    if (node == NULL) return;
    char symbol;

    if (node->getLeft() != NULL) {
        // ставим "("
        symbol = node->getLeft()->getValue();
        if (symbol >= 'a' && symbol <= 'z' || node->getLeft()->getLeft() != NULL) outString += '(';
        // идём дальше по остальным символам
        AV::toLine(outString, node->getLeft());
    }

    outString += node->getValue();

    if (node->getRight() != NULL) {
        // идём по остальным символам
        AV::toLine(outString, node->getRight());
        symbol = node->getRight()->getValue();
        // ставим ")"
        if (symbol >= 'a' && symbol <= 'z' || node->getRight()->getRight() != NULL) outString += ')';
    }
}

// --------------------- //
// ДРУЖЕСТВЕННЫЕ ФУНКЦИИ
// --------------------- //

std::ostream& operator<< (std::ostream& out, const AV& av)
{
    std::string tmp;
    AV::toLine(tmp, av.values);
    return out << tmp;
}