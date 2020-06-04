package circle

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const Eps = 1e-12

type Circle struct {
	X int
	Y int
	R int
}

// возвращает количество общих точек окружностей
func (c Circle) GetNumCommonPointsWith(other *Circle) int {
	distance := 0
	distance += (other.X - c.X) * (other.X - c.X)
	distance += (other.Y - c.Y) * (other.Y - c.Y)

	switch {
	// проверяем, не совпадают ли окружности
	case (c.X == other.X) && (c.Y == other.Y) && (c.R == other.R):
		return -1
	// проверяем условие внешнего касания
	case math.Abs(float64((c.R+other.R)*(c.R+other.R)-distance)) < Eps:
		fallthrough
	// проверяем условие внутреннего касания
	case math.Abs(float64((c.R-other.R)*(c.R-other.R)-distance)) < Eps:
		return 1
	// рассматриваем случаи, когда окружности не имеют общих точек (1)
	case float64((c.R+other.R)*(c.R+other.R)-distance) < -Eps:
		fallthrough
	// рассматриваем случаи, когда окружности не имеют общих точек (2)
	case float64((c.R-other.R)*(c.R-other.R)-distance) > Eps:
		return 0
	// если не прошли проверки выше, значит у Circles две общие точки
	default:
		return 2
	}
}

// загружает данные о Circles из файла
// новая строка - новая сущность
// строки вида "int int int": x, y и длина радиуса соответственно
func LoadFromFile(path string) ([]*Circle, error) {
	file, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer func() { err = file.Close() }()

	scanner := bufio.NewScanner(file)
	var result []*Circle

	for scanner.Scan() {
		data := strings.Split(scanner.Text(), " ")
		if len(data) != 3 {
			continue
		}

		xPoint, err := strconv.Atoi(data[0])
		if err != nil {
			return nil, err
		}

		yPoint, err := strconv.Atoi(data[1])
		if err != nil {
			return nil, err
		}

		rLength, err := strconv.Atoi(data[2])
		if err != nil {
			return nil, err
		}

		result = append(result, &Circle{
			X: xPoint,
			Y: yPoint,
			R: rLength,
		})
	}

	return result, nil
}

// записывает количество общих точек пар Circles
func WriteAllCommonPoints(path string, circles []*Circle) error {
	if circles == nil {
		return fmt.Errorf("the list of Circles is empty")
	}

	circlesNum := len(circles)
	if circlesNum%2 != 0 {
		return fmt.Errorf("the number of Circles is odd")
	}

	file, err := os.Create(path)
	if err != nil {
		return err
	}

	for i := 0; i < circlesNum/2; i++ {
		line := strconv.Itoa(circles[0+i*2].GetNumCommonPointsWith(circles[1+i*2]))

		if i == 0 {
			_, err = file.WriteString(line)
		} else {
			_, err = file.WriteString("\n" + line)
		}

		if err != nil {
			return err
		}
	}

	return nil
}
