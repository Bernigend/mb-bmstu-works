package target

import (
	"bufio"
	"strings"
	"testing"
)

func TestTarget_LoadData(t *testing.T) {
	var input = `5 5
12
15
9
6
3
3 4
5 6
7 8
9 10
11 12`

	var expectedCircles = []*Circle{
		{15}, // 1
		{12}, // 2
		{9},  // 3
		{6},  // 4
		{3},  // 5
	}

	var expectedPoints = []*Point{
		{3, 4},   // 4
		{5, 6},   // 4
		{7, 8},   // 3
		{9, 10},  // 2
		{11, 12}, // 2
	}

	var target Target
	scanner := bufio.NewScanner(strings.NewReader(input))

	err := target.LoadData(scanner)
	if err != nil {
		t.Error(err)
		return
	}

	if len1, len2 := len(expectedCircles), len(target.Circles); len1 != len2 {
		t.Error("expected numbers of circles", len1, "received", len2)
		return
	}

	if len1, len2 := len(expectedPoints), len(target.Points); len1 != len2 {
		t.Error("expected numbers of points", len1, "received", len2)
		return
	}

	for i, tmp := range expectedCircles {
		if circle1, circle2 := *tmp, *target.Circles[i]; circle1 != circle2 {
			t.Error("expected", circle1, "received", circle2)
			return
		}
	}

	for i, tmp := range expectedPoints {
		if point1, point2 := *tmp, *target.Points[i]; point1 != point2 {
			t.Error("expected", point1, "received", point2)
			return
		}
	}
}

func TestTarget_CalculatePoints(t *testing.T) {
	var targetCircles = []*Circle{
		{15}, // 1 балл
		{10}, // 2 балла
		{5},  // 3 балла
	}

	var targetPoints = []*Point{
		{0, 4},  // +3 балла
		{0, 10}, // +2 балла
		{0, 11}, // +1 балл
		{2, 2},  // +3 балла
		{-2, 2}, // +3 балла
		{6, 1},  // +2 балла
		{1, 6},  // +2 балла
		{6, 8},  // +2 балла
		{20, 4}, // +0 баллов
	}

	var target = Target{
		Circles: targetCircles,
		Points:  targetPoints,
	}

	var expectedSum = 18

	sum, err := target.CalculatePoints()

	if err != nil {
		t.Error(err)
		return
	}

	if sum != expectedSum {
		t.Error("expected sum", expectedSum, "received", sum)
		return
	}
}
