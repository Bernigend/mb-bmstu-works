package main

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
)

// LinearEquation
// линейное алгебраическое уравнение
type LinearEquation struct {
	Coefficients []float64
	Value        float64
}

// LinearEquationList
// список линейных алгебраических уравнений (система, СЛАУ)
type LinearEquationList []LinearEquation

// createClone
// клонирует объект
func (list LinearEquationList) createClone() LinearEquationList {
	equationsCount := list.getCount()
	clone := make(LinearEquationList, equationsCount)

	for i := 0; i < equationsCount; i++ {
		clone[i].Coefficients = make([]float64, len(list[i].Coefficients))
		copy(clone[i].Coefficients, list[i].Coefficients)
		clone[i].Value = list[i].Value
	}

	return clone
}

// createLinearEquationListFromScanner
// создаёт объект LinearEquationList
func createLinearEquationListFromScanner(scanner *bufio.Scanner) (LinearEquationList, error) {
	matrix := LinearEquationList{}

	for scanner.Scan() {
		linearEquation := LinearEquation{}

		equationLine := scanner.Text()
		if len(equationLine) == 0 {
			break
		}

		explodedLine := strings.Split(equationLine, " ")
		numbersCount := len(explodedLine)

		for i := 0; i < numbersCount; i++ {
			stringNumber := explodedLine[i]
			if len(stringNumber) == 0 {
				continue
			}

			tmpFloat, err := strconv.ParseFloat(stringNumber, 64)
			if err != nil {
				return nil, err
			}

			if i + 1 != numbersCount {
				linearEquation.Coefficients = append(linearEquation.Coefficients, tmpFloat)
			} else {
				linearEquation.Value = tmpFloat
			}
		}

		matrix = append(matrix, linearEquation)
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}

	// матрица должна быть только квадратной
	matrixSize := matrix.getCount()
	for _, equation := range matrix {
		if len(equation.Coefficients) != matrixSize {
			return nil, fmt.Errorf("the number of equations and coefficients in them must be the same")
		}
	}

	return matrix, nil
}

// getCount
// выводит количество уравнений в системе
func (list LinearEquationList) getCount() int {
	return len(list)
}

// print
// выводит СЛАУ на экран
func (list LinearEquationList) print(writer *bufio.Writer) error {
	size := list.getCount()

	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			_, err := writer.WriteString(fmt.Sprintf("%.2f*x%d", list[i].Coefficients[j], j))
			if err != nil {
				return err
			}

			if j < size-1 {
				_, err = writer.WriteString(" + ")
				if err != nil {
					return err
				}
			}
		}

		_, err := writer.WriteString(fmt.Sprintf(" = %.2f\n", list[i].Value))
		if err != nil {
			return err
		}
	}

	return nil
}
