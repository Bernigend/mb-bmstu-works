//
// Created by Bernigend on 06.06.2020.
//

#ifndef LABORATORY_WORK_12_QSORT_H
#define LABORATORY_WORK_12_QSORT_H

namespace lab12 {

    /**
     * Быстрая сортировка Хоара (или qsort в Си)
     * @tparam Type целочисленные или вещественные типы данных
     * @param array массив для сортировки
     * @param first начальный элемент (индекс)
     * @param last последний элемент (индекс)
     */
    template< typename Type >
    void qsort(Type *array, int first, int last, unsigned int& compareNum, unsigned int& swapNum) {
        int i = first, j = last;
        Type tmp, x = array[(first + last) / 2];

        do {
            while (array[i] < x) { i++; compareNum++; }
            while (array[j] > x) { j--; compareNum++; }

            if (i <= j) { compareNum++;
                if (i < j) { compareNum++;
                    tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                    swapNum++;
                }
                i++; j--;
            }

            compareNum++;
        } while (i < j);

        if (i < last)  lab12::qsort(array, i, last, ++compareNum, swapNum);
        if (first < j) lab12::qsort(array, first, j, ++compareNum, swapNum);
    }

}

#endif //LABORATORY_WORK_12_QSORT_H
