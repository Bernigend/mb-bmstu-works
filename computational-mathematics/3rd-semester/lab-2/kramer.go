package main

import "fmt"

// solveByKramer
// возвращает список решений СЛАУ по методу Крамера
func (list LinearEquationList) solveByKramer() ([]float64, error) {
	equationsCount := list.getCount()

	mainDeterminant := calculateMainDeterminant(list)
	if mainDeterminant == 0.0 {
		return nil, fmt.Errorf("main determinant is 0")
	}

	result := make([]float64, equationsCount)
	for i := 0; i < equationsCount; i++ {
		tmpDeterminant := calculateColumnDeterminant(list, i)
		result[i] = tmpDeterminant / mainDeterminant
	}

	return result, nil
}

// calculateMainDeterminant
// вычисляет общий определитель системы
func calculateMainDeterminant(list LinearEquationList) float64 {
	return calculateMatrixDeterminant(list)
}

// calculateColumnDeterminant
// вычисляет опеределитель, заменяя указанный столбец на свободные члены
func calculateColumnDeterminant(list LinearEquationList, column int) float64 {
	equationsCount := list.getCount()
	tmpList := list.createClone()

	for i := 0; i < equationsCount; i++ {
		tmpList[i].Coefficients[column] = list[i].Value
	}

	return calculateMatrixDeterminant(tmpList)
}

// calculateMatrixDeterminant
// вычисляет определитель переданной матрицы
func calculateMatrixDeterminant(list LinearEquationList) float64 {
	equationsCount := list.getCount()

	if equationsCount == 1 {
		return list[0].Coefficients[0]
	}

	if equationsCount == 2 {
		return (list[0].Coefficients[0] * list[1].Coefficients[1]) - (list[1].Coefficients[0] * list[0].Coefficients[1])
	}

	leftPart := 0.0
	for i := 0; i < equationsCount; i++ {
		tmp := 1.0
		for row := 0; row < equationsCount; row++ {
			coefficientIndex := row + i
			if coefficientIndex >= equationsCount {
				coefficientIndex = coefficientIndex % equationsCount
			}

			coefficient := list[row].Coefficients[coefficientIndex]
			tmp *= coefficient
		}
		leftPart += tmp
	}

	rightPart := 0.0
	for i := 0; i < equationsCount; i++ {
		tmp := 1.0
		for row := equationsCount - 1; row >= 0; row-- {
			coefficientIndex := ((equationsCount - 1) - row) + i
			if coefficientIndex >= equationsCount {
				coefficientIndex = coefficientIndex % equationsCount
			}

			coefficient := list[row].Coefficients[coefficientIndex]
			tmp *= coefficient
		}
		rightPart += tmp
	}

	return leftPart - rightPart
}
