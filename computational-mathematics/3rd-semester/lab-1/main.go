package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// количество членов разложения
	count := 1.0
	// результат вычислений
	totalValue := 0.0
	// текущий член разложения
	currentElement := 0.0
	// для смены знака члена разложения
	toPositive := -1.0
	// нужно ли сменить знак у результата
	changeSign := false

	consoleReader := bufio.NewReader(os.Stdin)

	// точка для поиска значения функции
	x, err := getFloatFromReader(consoleReader, "Enter x: ")
	if err != nil {
		log.Fatalf("Cannot parse X from input: %s", err.Error())
	}

	// точность вычислений
	precision, err := getIntFromReader(consoleReader, "Enter precision: ")
	if err != nil {
		log.Fatalf("Cannot parse precision from input: %s", err.Error())
	}

	epsilon := math.Pow(10, -float64(precision + 1))

	fmt.Println("---------")
	fmt.Printf("Log from library: %.*f\n", precision, math.Log(x))

	// обращаем внимание на то, что ln(1+x) сходится при -1 < x < 1, а ln(x) = -ln(1/x)
	if x >= 2.0 {
		x = 1.0 / x
		changeSign = true
	}

	for {
		// вычисляем член разложения
		// см. http://mathprofi.ru/tablica_razlozhenij_funkcij_v_ryady.pdf
		currentElement = (-1.0 * toPositive) * (math.Pow(x-1, count) / count)

		// прибавляем его к общему результату
		totalValue += currentElement

		// увеличиваем количество членов разложения
		count++

		// меняем знак следующего члена
		if toPositive == -1.0 {
			toPositive = 1.0
		} else {
			toPositive = -1.0
		}

		log.Printf("%.20f\n", math.Abs(currentElement))
		if math.Abs(currentElement) <= epsilon {
			break
		}
	}

	if changeSign {
		totalValue *= -1.0
	}

	fmt.Printf("Log from me:      %.*f\n", precision, totalValue)
	fmt.Println("---------")
	fmt.Printf("Precision: %.*f\n", precision, epsilon)
	fmt.Printf("Count: %.0f\n", count)
	fmt.Println("---------")
}

// getFloatFromReader возвращает число из потока ввода
func getFloatFromReader(reader *bufio.Reader, message string) (float64, error) {
	fmt.Print(message)
	stringX, err := reader.ReadString('\n')
	if err != nil {
		log.Fatalf("Cannot read string from console: %s", err.Error())
	}
	stringX = strings.Replace(stringX, "\n", "", -1)

	return strconv.ParseFloat(stringX, 64)
}

// getFloatFromReader возвращает число из потока ввода
func getIntFromReader(reader *bufio.Reader, message string) (int64, error) {
	fmt.Print(message)
	stringX, err := reader.ReadString('\n')
	if err != nil {
		log.Fatalf("Cannot read string from console: %s", err.Error())
	}
	stringX = strings.Replace(stringX, "\n", "", -1)

	tmp, err := strconv.Atoi(stringX)

	return int64(tmp), err
}
