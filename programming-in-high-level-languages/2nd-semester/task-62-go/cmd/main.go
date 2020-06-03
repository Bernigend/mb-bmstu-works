package main

import (
	"fmt"
	"task62/internal"
)

func main() {
	var pages internal.Pages
	var inputString string
	var numPages int

	fmt.Println("Enter number of pages:")
	_, err := fmt.Scan(&numPages)
	if err != nil {
		panic(err)
	}

	fmt.Println("Enter the page ranges (1-3,4-7 etc):")
	_, err = fmt.Scan(&inputString)
	if err != nil {
		panic(err)
	}

	pages = internal.Pages{}
	err = pages.Init(numPages, &inputString)
	if err != nil {
		panic(err)
	}

	fmt.Println("Number of pages for print:", len(pages))
}
