#include <iostream>

/**
 * ��������� ��������� ������ ������ scanf
 *
 * @param result - ������������ �������� ������� scanf
 * @param countVars - ���������� ���������� ��� �����
 * @return false ��� �������������� ������, ����� true
 */
bool checkScanfResult(int result, int countVars)
{
	return !(result == EOF || result != countVars);
}

/**
 * ��������� ������������ �������� ����
 *
 * @param day - ����
 * @param month - �����
 * @param year - ���
 * @return false ��� �������������� ������, ����� true
 */
bool checkDate(int day, int month, int year)
{
	return !(day < 1 || day > 31 || month < 1 || month > 12);
}

/**
 * ��������� ������������ ��������� �������
 *
 * @param hour - ����
 * @param min - ������
 * @param sec - �������
 * @return false ��� �������������� ������, ����� true
 */
bool checkTime(int hour, int min, int sec)
{
	return !(hour < 0 || hour > 24 || min < 0 || min > 59 || sec < 0 || sec > 59);
}

/**
 * ??????????????? ??????? ??? ????? ???? ? ???????
 *
 * @param day - ����
 * @param month - �����
 * @param year - ���
 * @param hour - ����
 * @param min - ������
 * @param sec - �������
 * @param result - ������������ �������� ������� scanf
 * @param countVars - ���������� ���������� ��� �����
 * @return �������� ������, ����� ������ ������
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