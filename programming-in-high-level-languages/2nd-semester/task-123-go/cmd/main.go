package main

import (
	"bufio"
	"fmt"
	"os"
	"task123/internal/clock"
)

const inputFilePath = "cmd/input.txt"

func main() {
	inputFile, err := os.Open(inputFilePath)
	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(inputFile)

	scanner.Scan()
	clockStart, err := clock.Create(scanner.Text())
	if err != nil {
		panic(err)
	}

	scanner.Scan()
	clockEnd, err := clock.Create(scanner.Text())
	if err != nil {
		panic(err)
	}

	result := clock.CalculateBangs(clockStart, clockEnd)
	fmt.Println(result)
}
