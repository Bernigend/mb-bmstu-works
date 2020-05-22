package target

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

// Ищет окружность, в которую попал выстрел
func (c Circles) Search(point *Point) int {
	return binarySearch(c, point, 0, len(c))
}

// Бинарный поиск окружности, в которую попал выстрел
func binarySearch(circles Circles, point *Point, left, right int) int {
	mid := (left + right) / 2

	if point.X*point.X+point.Y*point.Y > circles[mid].R*circles[mid].R {
		right = mid
		if right-left == 0 {
			return 0
		}
	} else {
		left = mid
		if right-left == 1 {
			return mid + 1
		}
	}

	return binarySearch(circles, point, left, right)
}
