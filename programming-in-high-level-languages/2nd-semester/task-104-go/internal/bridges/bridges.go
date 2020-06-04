package bridges

import (
	"bufio"
	"strconv"
	"task104/internal/bus"
)

type Bridges []int

// Считывает данные о высотах мостов.
// Возвращает порядковый номер моста, под которым не сможет проехать автобус.
// Возвращает ошибку, если не удалось получить число из строки.
func (b *Bridges) Init(scanner *bufio.Scanner) (int, error) {
	// пропускаем строку с указанием количества мостов (зачем она?)
	scanner.Scan()

	i := 1
	for scanner.Scan() {
		height, err := strconv.Atoi(scanner.Text())
		if err != nil {
			return 0, err
		}

		if height <= bus.Height {
			return i, nil
		}

		*b = append(*b, height)
		i++
	}

	return 0, nil
}
