#include <iostream>

/**
 * Проверяет результат работы функци scanf
 *
 * @param result - возвращаемое значение функции scanf
 * @param countVars - количество переменных для ввода
 * @return false при несоответствии данных, иначе true
 */
bool checkScanfResult(int result, int countVars)
{
	return !(result == EOF || result != countVars);
}

/**
 * Проверяет корректность введённой даты
 *
 * @param day - день
 * @param month - месяц
 * @param year - год
 * @return false при несоответствии данных, иначе true
 */
bool checkDate(int day, int month, int year)
{
	return !(day < 1 || day > 31 || month < 1 || month > 12);
}

/**
 * Проверяет корректность введённого времени
 *
 * @param hour - часы
 * @param min - минуты
 * @param sec - секунды
 * @return false при несоответствии данных, иначе true
 */
bool checkTime(int hour, int min, int sec)
{
	return !(hour < 0 || hour > 24 || min < 0 || min > 59 || sec < 0 || sec > 59);
}

/**
 * Проверяет корректность введённых данных
 *
 * @param day - день
 * @param month - месяц
 * @param year - год
 * @param hour - часы
 * @param min - минуты
 * @param sec - секунды
 * @param result - возвращаемое значение функции scanf
 * @param countVars - количество переменных для ввода
 * @return описание ошибки, иначе пустую строку
 */
std::string checkInputData(int day, int month, int year, int hour, int min, int sec, int result, int countVars)
{
	if (!checkScanfResult(result, countVars))
		return "Error: date or time format is invalid!";

	if (!checkDate(day, month, year))
		return "Error: date is invalid!";

	if (!checkTime(hour, min, sec))
		return "Error: time is invalid!";

	return "";
}