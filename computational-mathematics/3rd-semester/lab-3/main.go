package main

import "fmt"

func main() {
	equation := Equation{ 2, -2, 4, 0.5 }
	fmt.Println(equation)
	fmt.Println(equation.polovinnoeDelenie(-9, -8))
	fmt.Println(equation.kasatelnyeNewtona(Equation{ -4, 12, 2 }, 100))
}
