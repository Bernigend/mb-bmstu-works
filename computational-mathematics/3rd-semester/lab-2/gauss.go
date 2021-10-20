package main

import (
	"fmt"
	"math"
)

// solveByGauss
// возвращает список решений СЛАУ по методу Гаусса
// @see https://prog-cpp.ru/gauss/
func (list LinearEquationList) solveByGauss() ([]float64, error) {
	var max, temp float64
	var index int
	var handledEquationsCount = 0
	var eps = 0.00001
	var equationsCount = list.getCount()

	var x = make([]float64, equationsCount)

	for handledEquationsCount < equationsCount {
		// Поиск строки с максимальным a[i][k]
		max = math.Abs(list[handledEquationsCount].Coefficients[handledEquationsCount])
		index = handledEquationsCount

		for i := handledEquationsCount + 1; i < equationsCount; i++ {
			if tmp := math.Abs(list[i].Coefficients[handledEquationsCount]); tmp > max {
				max = tmp
				index = i
			}
		}

		// Перестановка строк
		if max < eps {
			// нет ненулевых диагональных элементов
			return nil, fmt.Errorf("решение получить невозможно из-за нулевого столбца %d матрицы A", index)
		}

		for j := 0; j < equationsCount; j++ {
			list[handledEquationsCount].Coefficients[j],
				list[index].Coefficients[j] = list[index].Coefficients[j],
				list[handledEquationsCount].Coefficients[j]
		}

		list[handledEquationsCount].Value,
			list[index].Value = list[index].Value,
			list[handledEquationsCount].Value

		// Нормализация уравнений
		for i := handledEquationsCount; i < equationsCount; i++ {
			temp = list[i].Coefficients[handledEquationsCount]

			// для нулевого коэффициента пропустить
			if math.Abs(temp) < eps {
				continue
			}

			for j := 0; j < equationsCount; j++ {
				list[i].Coefficients[j] = list[i].Coefficients[j] / temp
			}

			list[i].Value = list[i].Value / temp

			// уравнение не вычитать само из себя
			if i == handledEquationsCount {
				continue
			}

			for j := 0; j < equationsCount; j++ {
				list[i].Coefficients[j] = list[i].Coefficients[j] - list[handledEquationsCount].Coefficients[j]
			}
			list[i].Value = list[i].Value - list[handledEquationsCount].Value
		}
		handledEquationsCount++
	}

	// обратная подстановка
	for handledEquationsCount = equationsCount - 1; handledEquationsCount >= 0; handledEquationsCount-- {
		x[handledEquationsCount] = list[handledEquationsCount].Value
		for i := 0; i < handledEquationsCount; i++ {
			list[i].Value = list[i].Value - list[i].Coefficients[handledEquationsCount]*x[handledEquationsCount]
		}
	}

	return x, nil
}
