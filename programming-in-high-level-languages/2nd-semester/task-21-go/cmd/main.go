package main

import (
	"bufio"
	"fmt"
	"os"
	"task21/cmd/target"
)

const (
	inputFilePath = "E:/Development/MB_BMSTU/mb-bmstu-works/programming-in-high-level-languages/2nd-semester/task-21-go/cmd/input.txt"
)

func main() {
	file, err := os.Open(inputFilePath)
	if err != nil {
		panic(err)
	}
	defer func() { _ = file.Close() }()

	scanner := bufio.NewScanner(file)
	var target1 target.Target

	err = target1.LoadData(scanner)
	if err != nil {
		panic(err)
	}

	sum, err := target1.CalculatePoints()
	if err != nil {
		panic(err)
	}

	fmt.Println(sum)
}
