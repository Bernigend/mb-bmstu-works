package target

import (
	"fmt"
	"sort"
)

// Окружность для выстрела с радиусом
type Circle struct {
	R int
}

// Тип для хранения окружностей
type Circles []*Circle

// Реализуем интерфейс сортировки
func (c Circles) Len() int           { return len(c) }
func (c Circles) Swap(i, j int)      { c[i], c[j] = c[j], c[i] }
func (c Circles) Less(i, j int) bool { return c[i].R > c[j].R }
func (c Circles) Sort()              { sort.Sort(c) }

// Ищет окружность, в которую попал выстрел
func (c Circles) Search(point *Point) (int, error) {
	return binarySearch(c, point, 0, len(c))
}

// Бинарный поиск окружности, в которую попал выстрел
func binarySearch(circles Circles, point *Point, left, right int) (int, error) {
	if point == nil {
		return 0, fmt.Errorf("point is nil")
	}

	mid := (left + right) / 2

	if point.X*point.X+point.Y*point.Y > circles[mid].R*circles[mid].R {
		right = mid
		if right-left == 0 {
			return 0, nil
		}
	} else {
		left = mid
		if right-left == 1 {
			return mid + 1, nil
		}
	}

	return binarySearch(circles, point, left, right)
}
