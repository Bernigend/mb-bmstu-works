package main

import (
	"task16/cmd/circle"
)

const (
	inputFilePath  = "E:/Development/MB_BMSTU/mb-bmstu-works/programming-in-high-level-languages/2nd-semester/task-16-go/cmd/input.txt"
	outputFilePath = "E:/Development/MB_BMSTU/mb-bmstu-works/programming-in-high-level-languages/2nd-semester/task-16-go/cmd/output.txt"
)

func main() {
	circles, err := circle.LoadFromFile(inputFilePath)
	if err != nil {
		panic(err)
	}

	err = circle.WriteAllCommonPoints(outputFilePath, circles)
	if err != nil {
		panic(err)
	}
}
