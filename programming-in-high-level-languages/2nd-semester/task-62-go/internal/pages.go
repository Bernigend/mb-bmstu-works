package internal

import (
	"strconv"
	"strings"
)

type Pages map[int]bool

func (p *Pages) Init(numPages int, line *string) error {
	var int1, int2 int
	var err error
	ranges := strings.Split(*line, ",")

	for _, pageRange := range ranges {
		pages := strings.Split(pageRange, "-")

		int1, err = strconv.Atoi(pages[0])
		if err != nil {
			return err
		}

		if pagesLen := len(pages); pagesLen == 1 {
			if int1 > numPages {
				continue
			}
			(*p)[int1] = true
		} else {
			int2, err = strconv.Atoi(pages[1])
			if err != nil {
				return err
			}

			if int1 > int2 {
				continue
			}

			if int2 > numPages {
				int2 = numPages
			}

			for k := int1; k <= int2; k++ {
				(*p)[k] = true
			}
		}
	}

	return nil
}
