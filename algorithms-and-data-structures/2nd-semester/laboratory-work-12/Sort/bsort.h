//
// Created by Bernigend on 06.06.2020.
//

#ifndef LABORATORY_WORK_12_BSORT_H
#define LABORATORY_WORK_12_BSORT_H

namespace lab12 {

    /**
     * Сортировка с помощью бинарных вставок
     * @tparam Type целочисленные или вещественные типы данных
     * @param array массив для сортировки
     * @param size размер массива
     */
    template< typename Type >
    void bsort(Type* array, unsigned int size, unsigned int& compareNum, unsigned int& swapNum)
    {
        Type x, left, middle, right;

        for (int i = 1; i < size; i++, compareNum++) {
            if (array[i-1] > array[i]) { compareNum++;
                x = array[i];
                left = 0; right = i-1;

                do {
                    middle = (left + right) / 2;
                    if (array[middle] < x)
                        left = middle + 1;
                    else
                        right = middle - 1;

                    compareNum++; // проверка условия
                    compareNum++; // проверка цикла
                } while (left <= right);

                for (int j = i-1; j >= left; j--, compareNum++, swapNum++) array[j+1] = array[j];
                array[left] = x; swapNum++;
            }
        }
    }

}

#endif //LABORATORY_WORK_12_BSORT_H
