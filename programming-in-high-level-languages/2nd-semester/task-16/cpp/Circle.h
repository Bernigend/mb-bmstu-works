/**
 * Created by Bernigend on 11.05.2020.
 */

#ifndef TASK_16_CIRCLE_H
#define TASK_16_CIRCLE_H


#include <vector>
#include <string>

enum CircleErrors {
	SUCCESS = 1,
	CIRCLES_LIST_IS_NULL,
	CIRCLES_NUM_IS_ODD,
	CANNOT_OPEN_FILE
};

class Circle {
protected:
	// x координата
	int X = 0;
	// y координата
	int Y = 0;
	// длина радиуса
	int R = 0;

public:
	// конструктор по умолчанию
	Circle();
	// конструктор копирования
	Circle(const Circle&);
	// конструктор с параметрами
	Circle(int, int, int);

	// возвращает количество общих точек,
	// либо -1, если окружности совпадают
	int getCommonPoints(const Circle&);

	// возвращает данные о Circles из файла
	// каждая строка - отдельный Circle
	// строка вида "%d %d %d": x, y и длина радиуса соответственно
	static CircleErrors getFromFile(const std::string&, std::vector<Circle>*);

	// записывает в файл общие точки каждой пары Circles
	static CircleErrors writeAllCommonPoints(const std::string&, std::vector<Circle>*);

	// выводит информацию об ошибке
	static void printError(std::ostream&, CircleErrors);
};


#endif //TASK_16_CIRCLE_H
