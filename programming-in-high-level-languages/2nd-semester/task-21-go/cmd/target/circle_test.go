package target

import (
	"testing"
)

func TestCircles_Sort(t *testing.T) {
	var circles, expectedCircles Circles

	circles = Circles{
		{30},
		{3},
		{4},
		{15},
		{20},
	}

	expectedCircles = Circles{
		{30},
		{20},
		{15},
		{4},
		{3},
	}

	circles.Sort()

	for index, circle := range expectedCircles {
		if ce, cr := *circle, *circles[index]; cr != ce {
			t.Error("expected", ce, "received", cr)
			return
		}
	}
}

func TestCircles_Search(t *testing.T) {
	var circles = Circles{
		{30},
		{20},
		{15},
		{4},
		{3},
	}

	_, err := circles.Search(nil)
	if err == nil {
		t.Error("expected error, but error is nil")
		return
	}
}
