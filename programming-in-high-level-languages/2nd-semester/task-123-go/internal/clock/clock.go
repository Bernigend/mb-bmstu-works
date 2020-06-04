package clock

import (
	"fmt"
	"strconv"
	"strings"
)

type Clock struct {
	Hour   int
	Minute int
}

func CalculateBangs(clockStart, clockEnd Clock) int {
	result := 0

	if clockStart.Hour > clockEnd.Hour {
		clockStart, clockEnd = clockEnd, clockStart
	}

	if clockStart.Minute == 0 {
		result += clockStart.Hour + 1
	} else if clockStart.Minute <= 30 {
		result += 1
	}

	for i := clockStart.Hour + 1; i < clockEnd.Hour; i++ {
		result += i + 1
		fmt.Println(i)
	}

	if clockEnd.Minute < 30 {
		result += clockEnd.Hour
	} else {
		result += clockEnd.Hour + 1
	}

	return result
}

func Create(rawString string) (Clock, error) {
	var hour, minute int
	data := strings.Split(rawString, " ")

	hour, err := strconv.Atoi(data[0])
	if err != nil {
		return Clock{}, err
	}

	if hour < 0 || hour > 24 {
		return Clock{}, fmt.Errorf("hour (%v) is wrong", hour)
	}

	if len(data) == 1 {
		minute = 0
	} else {
		minute, err = strconv.Atoi(data[1])
		if err != nil {
			return Clock{}, err
		}
		if minute < 0 || minute > 59 {
			return Clock{}, fmt.Errorf("minute (%v) is wrong", minute)
		}
	}

	clock := Clock{
		Hour:   hour,
		Minute: minute,
	}

	return clock, nil
}
