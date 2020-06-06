//
// Created by Bernigend on 06.06.2020.
//

#ifndef LABORATORY_WORK_12_SSORT_H
#define LABORATORY_WORK_12_SSORT_H

namespace lab12 {

    /**
     * Сортировка прямым выбором
     * @tparam Type целочисленные или вещественные типы данных
     * @param array массив для сортировки
     * @param size размер массива
     */
    template< typename Type >
    void ssort(Type* array, unsigned int size, unsigned int& compareNum, unsigned int& swapNum)
    {
        Type min, temp;

        for (unsigned int i = 0; i < size-1; i++, compareNum++) {
            min = i;
            for (unsigned int j = i+1; j < size; j++, compareNum++) {
                if (array[j] < array[min]) { min = j; compareNum++; }
            }

            temp       = array[i];
            array[i]   = array[min];
            array[min] = temp;
            swapNum++;
        }
    }

}

#endif //LABORATORY_WORK_12_SSORT_H
