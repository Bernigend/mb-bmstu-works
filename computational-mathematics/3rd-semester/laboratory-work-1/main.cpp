#include <iostream>
#include <cmath>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "LoopDoesntUseConditionVariableInspection"

int main()
{
	const double EPSILON = 0.00000001; // требуемая точность
	long double x = 0;                 // точка для поиска значения функции
	long double count = 1.0;           // количество членов разложения
	long double totalValue = 0.0;      // результат вычислений
	long double currentElement = 0.0;  // текущий член разложения
	long double toPositive = -1.0;     // для смены знака члена разложения
	bool changeSign = false;           // нужно ли сменить знак у результата

	if (x < 0.0) {
		throw std::invalid_argument("x < 0");
	}

	std::cout.precision(10);
	std::cout << "Enter x:";
	std::cin >> x;
	std::cout << "Log(x) from library: " << std::log(x) << std::endl;

	// обращаем внимание на то, что ln(1+x) сходится при -1 < x < 1, а ln(x) = -ln(1/x)
	if (x >= 2.0) {
		x = 1.0 / x;
		changeSign = true;
	}

	do {
		// вычисляем член разложения
		// см. http://mathprofi.ru/tablica_razlozhenij_funkcij_v_ryady.pdf
		currentElement = (-1.0 * toPositive) * (std::pow(x-1, count) / count);
		// прибавляем его к общему результату
		totalValue += currentElement;
		// увеличиваем количество членов разложения
		count++;
		// меняем знак следующего члена
		toPositive = toPositive == -1.0 ? 1.0 : -1.0;
	// проходимся по циклу пока очередной член разложения не станет меньше требуемой точности
	} while (std::fabs(currentElement) >= EPSILON);

	// меняем знак
	if (changeSign) {
		totalValue *= -1.0;
	}

	std::cout << "Log(x) from me:      " << totalValue << std::endl;
	std::cout << "Decision:            " << EPSILON << std::endl;
	std::cout << "Count:               " << --count << std::endl;

	return 1;
}
#pragma clang diagnostic pop