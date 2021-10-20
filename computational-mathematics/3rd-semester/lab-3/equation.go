package main

import (
	"fmt"
	"math"
)

const Epsilon = 0.0001

// Equation
// Уравнение.
type Equation []float64

// Подставляет переданный корень и возвращает решение.
func (e Equation) solve(x float64) float64 {
	var solution float64 = 0
	//var degree = len(e) - 1

	for degree, coefficient := range e {
		solution += coefficient * math.Pow(x, float64(degree+1))
		//degree--
	}

	return solution
}

// Метод половинного деления.
// Метод половинного деления основан на последовательном делении отрезка локализации корня пополам.
// Определяется знак функции в точке c = (a + b) / 2 - середине отрезка [a, b].
// Если он противоположен знаку функции в точке a, то корень локализован на отрезке [a, c],
// если же нет – то на отрезке [c, b].
// url: https://studfile.net/preview/6736203/page:2/
func (e Equation) polovinnoeDelenie(a, b float64) float64 {
	signA := e.solve(a)

	for b - a > Epsilon {
		tmpX := (a + b) / 2
		signTmp := e.solve(tmpX)

		if signA * signTmp <= 0 {
			b = tmpX
		} else {
			a = tmpX
			signA = signTmp
		}
	}

	return (a + b) / 2
}

// Метод касательных Ньютона — это итерационный метод поиска корня
// и относится к численному методу решения нелинейного уравнения.
// Формула касательных (Ньютона): X_k+1 = X_k - (f(X_k) / f'(X_k))
// при этом | X_k+1 - X_k | < Epsilon
// url: https://www.matematicus.ru/diskretnaya-matematika/reshenie-uravnenij-metodom-kasatelnyh-nyutona
func (e Equation) kasatelnyeNewtona(proizvodnaya Equation, x float64) float64 {
	X_k := x
	X_k1 := X_k - (e.solve(X_k) / proizvodnaya.solve(X_k))

	for math.Abs(X_k1 - X_k) > Epsilon {
		X_k = X_k1
		X_k1 = X_k - (e.solve(X_k) / proizvodnaya.solve(X_k))
	}

	return X_k1
}

func (e Equation) String() string {
	output := ""

	for degree, coefficient := range e {
		if degree+1 > 1 {
			output += fmt.Sprint(" + ")
		}

		output += fmt.Sprintf("%f*x^%d", coefficient, degree+1)
	}

	return output
}
