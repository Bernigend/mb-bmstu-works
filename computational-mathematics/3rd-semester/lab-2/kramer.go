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

	leftPart := 0.0
	for i := 0; i < equationsCount; i++ {
		tmp := 1.0
		for row := 0; row < equationsCount; row++ {
			coefficientIndex := row+i
			if coefficientIndex >= equationsCount {
				coefficientIndex = coefficientIndex % equationsCount
			}

			tmp *= list[row].Coefficients[coefficientIndex]
		}
		leftPart += tmp
	}

	rightPart := 0.0
	for i := 0; i < equationsCount; i++ {
		tmp := 1.0
		for row := equationsCount-1; row >= 0; row-- {
			coefficientIndex := ((equationsCount-1) - row)+i
			if coefficientIndex >= equationsCount {
				coefficientIndex = coefficientIndex % equationsCount
			}

			tmp *= list[row].Coefficients[coefficientIndex]
		}
		rightPart += tmp
	}

	return leftPart - rightPart
}
