package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	var err error
	var system LinearEquationList

	//fmt.Println("Enter a system of equations.")
	//fmt.Println("One equation = one line.")
	//fmt.Println("The separator is a space.")
	//fmt.Println("The rightmost number is the value of the expression.")
	//
	//fmt.Println()
	//
	//scanner := bufio.NewScanner(os.Stdin)
	//system, err := createLinearEquationListFromScanner(scanner)
	//if err != nil {
	//	log.Fatalln(err)
	//}

	// --------------------------------------------------------

	//system = LinearEquationList{
	//	LinearEquation{
	//		Coefficients: []float64{ 5, 2 },
	//		Value:        7,
	//	},
	//	LinearEquation{
	//		Coefficients: []float64{ 2, 1 },
	//		Value:        9,
	//	},
	//}

	system = LinearEquationList{
		LinearEquation{
			Coefficients: []float64{2, 1, 1},
			Value:        2,
		},
		LinearEquation{
			Coefficients: []float64{1, -1, 0},
			Value:        -2,
		},
		LinearEquation{
			Coefficients: []float64{3, -1, 2},
			Value:        2,
		},
	}

	fmt.Println("Your linear list system:") // --------------------------------------------------------
	writer := bufio.NewWriter(os.Stdout)
	err = system.print(writer)
	if err != nil {
		log.Fatalln(err)
	}
	writer.Flush()

	fmt.Println() // --------------------------------------------------------

	fmt.Println("Solve by Gauss")
	res, err := system.createClone().solveByGauss()
	if err != nil {
		fmt.Println("error:", err)
	} else {
		fmt.Println(res)
	}

	fmt.Println() // --------------------------------------------------------

	fmt.Println("Solve by Kramer")
	res, err = system.createClone().solveByKramer()
	if err != nil {
		fmt.Println("error:", err)
	} else {
		fmt.Println(res)
	}
}
