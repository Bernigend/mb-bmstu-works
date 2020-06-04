package main

import (
	"bufio"
	"fmt"
	"os"
	bridgesPkg "task104/internal/bridges"
)

const inputFilePath = "cmd/input.txt"

func main() {
	inputFile, err := os.Open(inputFilePath)
	if err != nil {
		panic(err)
	}
	defer func() { _ = inputFile.Close() }()

	bridges := bridgesPkg.Bridges{}
	scanner := bufio.NewScanner(inputFile)

	numBridge, err := bridges.Init(scanner)
	if err != nil {
		panic(err)
	}

	if numBridge == 0 {
		fmt.Println("No crash")
	} else {
		fmt.Println("Crash", numBridge)
	}
}
