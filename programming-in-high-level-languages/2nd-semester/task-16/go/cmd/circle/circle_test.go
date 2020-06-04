package circle

import (
	"io/ioutil"
	"os"
	"testing"
)

func Test0Points(t *testing.T) {
	circle1 := Circle{
		X: 2,
		Y: 2,
		R: 4,
	}
	circle2 := Circle{
		X: 10,
		Y: 10,
		R: 2,
	}

	if res := circle1.GetNumCommonPointsWith(&circle2); res != 0 {
		t.Error("[1] Expected 0, got", res)
	}

	if res := circle2.GetNumCommonPointsWith(&circle1); res != 0 {
		t.Error("[2] Expected 0, got", res)
	}
}

func Test1Point(t *testing.T) {
	circle1 := Circle{
		X: 0,
		Y: 0,
		R: 2,
	}
	circle2 := Circle{
		X: 4,
		Y: 0,
		R: 2,
	}

	if res := circle1.GetNumCommonPointsWith(&circle2); res != 1 {
		t.Error("[1] Expected 1, got", res)
	}

	if res := circle2.GetNumCommonPointsWith(&circle1); res != 1 {
		t.Error("[2] Expected 1, got", res)
	}
}

func Test2Points(t *testing.T) {
	circle1 := Circle{
		X: 0,
		Y: 0,
		R: 4,
	}
	circle2 := Circle{
		X: 4,
		Y: 0,
		R: 2,
	}

	if res := circle1.GetNumCommonPointsWith(&circle2); res != 2 {
		t.Error("[1] Expected 2, got", res)
	}

	if res := circle2.GetNumCommonPointsWith(&circle1); res != 2 {
		t.Error("[2] Expected 2, got", res)
	}
}

func TestLoadFromFile(t *testing.T) {
	workingDir, err := os.Getwd()
	if err != nil {
		t.Error(err)
	}

	circles, err := LoadFromFile(workingDir + string(os.PathSeparator) + "test_input.txt")
	if err != nil {
		t.Error(err)
	}

	expected := []*Circle{
		{
			X: 0,
			Y: 0,
			R: 2,
		},
		{
			X: 1,
			Y: 2,
			R: 3,
		},
		{
			X: 5,
			Y: 7,
			R: 2,
		},
	}

	if lc, le := len(circles), len(expected); lc != le {
		t.Error("Expected len =", le, ", got", lc)
	}

	for index, tmp := range circles {
		if *tmp != *expected[index] {
			t.Error("Expected", *expected[index], ", got", *tmp)
		}
	}
}

func TestWriteAllCommonPoints(t *testing.T) {
	workingDir, err := os.Getwd()
	if err != nil {
		t.Error(err)
	}

	inputFile := workingDir + string(os.PathSeparator) + "test_input.txt"
	outputFile := workingDir + string(os.PathSeparator) + "test_output.txt"

	circles, err := LoadFromFile(inputFile)
	if err != nil {
		t.Error(err)
	}

	err = WriteAllCommonPoints(outputFile, circles)
	if err != nil {
		t.Error(err)
	}

	file, err := os.Open(outputFile)
	if err != nil {
		t.Error(err)
	}

	data, err := ioutil.ReadAll(file)
	if err != nil {
		t.Error(err)
	}

	const expected = `-1
2
1
0`

	if string(data) != expected {
		t.Error("Expected", expected, ", got", string(data))
	}
}
