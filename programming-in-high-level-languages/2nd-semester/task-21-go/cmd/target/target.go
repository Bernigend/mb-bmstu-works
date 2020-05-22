package target

import (
	"bufio"
	"fmt"
	"strconv"
	"strings"
)

// Мишень хранит данные об окружностях и выстрелах
type Target struct {
	Circles Circles
	Points  Points
}

// Загружает данные о мишени и выстрелах
func (target *Target) LoadData(scanner *bufio.Scanner) error {
	var err error
	var pointsNum, circlesNum int

	// ---
	// считываем первую строку
	// ---

	if !scanner.Scan() {
		return fmt.Errorf("no data on circles and / or shots")
	}
	err = numbersFromString(scanner.Text(), &circlesNum, &pointsNum)
	if err != nil {
		return err
	}

	// ---
	// считываем данные об окружностях
	// ---

	prev, needSort := 0, false
	for i := 0; i < circlesNum && scanner.Scan(); i++ {
		circle := new(Circle)
		circle.R, err = strconv.Atoi(scanner.Text())
		if err != nil {
			return err
		}

		if circle.R > prev {
			needSort = true
		}
		prev = circle.R

		target.Circles = append(target.Circles, circle)
	}

	// если радиусы окружностей идут не по убыванию (как указано в условии) - сортируем
	if needSort {
		//sort.Sort(target.Circles)
		target.Circles.Sort()
	}

	// ---
	// считываем данные о выстрелах
	// ---

	for i := 0; i < pointsNum && scanner.Scan(); i++ {
		point := new(Point)
		err = numbersFromString(scanner.Text(), &point.X, &point.Y)
		if err != nil {
			return err
		}
		target.Points = append(target.Points, point)
	}

	return nil
}

// Подсчитывает очки игрока за выстрелы
func (target Target) CalculatePoints() (int, error) {
	circlesNum := len(target.Circles)

	switch {
	case target.Circles == nil || circlesNum == 0:
		return 0, fmt.Errorf("circles slice is nil")
	case target.Points == nil || len(target.Points) == 0:
		return 0, fmt.Errorf("points slice is nil")
	}

	var sum int

	for _, point := range target.Points {
		res, err := target.Circles.Search(point)
		if err != nil {
			return 0, err
		}
		sum += res
	}

	return sum, nil
}

// Считывает несколько целых чисел из строки и присваивает их значения переданным переменным
func numbersFromString(input string, integers ...*int) error {
	numbers := strings.Split(input, " ")

	if len(integers) < len(numbers) {
		return fmt.Errorf("there are not enough input variables")
	}

	for index, val := range numbers {
		tmp, err := strconv.Atoi(val)
		if err != nil {
			return err
		}
		*integers[index] = tmp
	}

	return nil
}
