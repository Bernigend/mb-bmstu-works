#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Sort/bsort.h"
#include "Sort/ssort.h"
#include "Sort/qsort.h"

int* createArray(int* array, unsigned int size);
template< typename Type > void printArray(Type* array, unsigned int size, unsigned int compareNum, unsigned int swapNum);

int main()
{
    const unsigned int SIZE_1 = 9;
    const unsigned int SIZE_2 = 20;

    int array1[SIZE_1];
    int array2[SIZE_2];

    unsigned int compareNum, swapNum;

    // -------------- //

    std::cout << " ----<---- QSORT ---->---- " << std::endl << std::endl;

    createArray(array1, SIZE_1); lab12::qsort(array1, 0, SIZE_1-1, compareNum = 0, swapNum = 0);
    printArray(array1, SIZE_1, compareNum, swapNum);

    createArray(array2, SIZE_2); lab12::qsort(array2, 0, SIZE_2-1, compareNum = 0, swapNum = 0);
    printArray(array2, SIZE_2, compareNum, swapNum);

    // -------------- //

    std::cout << " ----<---- SSORT ---->---- " << std::endl << std::endl;

    createArray(array1, SIZE_1); lab12::ssort(array1, SIZE_1, compareNum = 0, swapNum = 0);
    printArray(array1, SIZE_1, compareNum, swapNum);

    createArray(array2, SIZE_2); lab12::ssort(array2, SIZE_2, compareNum = 0, swapNum = 0);
    printArray(array2, SIZE_2, compareNum, swapNum);

    // -------------- //

    std::cout << " ----<---- BSORT ---->---- " << std::endl << std::endl;

    createArray(array1, SIZE_1); lab12::bsort(array1, SIZE_1, compareNum = 0, swapNum = 0);
    printArray(array1, SIZE_1, compareNum, swapNum);

    createArray(array2, SIZE_2); lab12::bsort(array2, SIZE_2, compareNum = 0, swapNum = 0);
    printArray(array2, SIZE_2, compareNum, swapNum);

    return 0;
}

/**
 * Заполняет массив случайными числами
 * @param array массив для заполнения
 * @param size размер массива
 */
int* createArray(int* array, unsigned int size)
{
    std::srand((unsigned int)time(NULL));
    for (unsigned int i = 0; i < size; i++) array[i] = std::rand() % 200 - 100;
    return array;
}

/**
 * Выводит массив в стандартный поток вывода
 * @tparam Type тип массива
 * @param array массив для вывода
 * @param size размер массива
 */
template< typename Type >
void printArray(Type* array, unsigned int size, unsigned int compareNum, unsigned int swapNum)
{
    for (unsigned int i = 0; i < size; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
    std::cout << "Compare: " << compareNum << "; Swap: " << swapNum << ";" << std::endl;
    std::cout << std::endl;
}