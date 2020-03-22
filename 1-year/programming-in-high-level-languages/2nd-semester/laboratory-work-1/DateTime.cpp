//
// Created by Bernigend on 22.03.2020.
//

#include "DateTime.h"

DateTime::DateTime()
{
    this->year  = 0;
    this->month = 0;
    this->day   = 0;

    this->hour   = 0;
    this->minute = 0;
    this->second = 0;

    this->setNow();
}

/**
 * Конструктор класса (копирование)
 *
 * @param _dateTime
 */
DateTime::DateTime(DateTime& _dateTime)
{
    this->year  = _dateTime.getYear();
    this->month = _dateTime.getMonth();
    this->day   = _dateTime.getDay();

    this->hour   = _dateTime.getHour();
    this->minute = _dateTime.getMinute();
    this->second = _dateTime.getSecond();
}

/**
 * Конструктор класса с параметрами
 *
 * @param _year
 * @param _month
 * @param _day
 * @param _hour
 * @param _minute
 * @param _second
 */
DateTime::DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second)
{
    this->year  = _year;
    this->month = _month;
    this->day   = _day;

    this->hour   = _hour;
    this->minute = _minute;
    this->second = _second;
}

/**
 * Проверяет корректность данных, уже установленных в объекте класса
 * @return
 */
bool DateTime::isValid()
{
    if (!isValidDate(this->year, this->month, this->day)) {
        return false;
    }

    return isValidTime(this->hour, this->minute, this->second);
}

/**
 * Проверяет корректность значений времени
 *
 * @param _hour
 * @param _minute
 * @param _second
 *
 * @return true, если всё верно, иначе false
 */
bool DateTime::isValidTime(int _hour, int _minute, int _second)
{
    if (_hour < 0 || _hour > 24) {
        setLastError("The number of hours is out of bounds");
        return false;
    }

    if (_minute < 0 || _minute > 59) {
        setLastError("The number of minutes is out of bounds");
        return false;
    }

    if (_second < 0 || _second > 60) {
        setLastError("The number of seconds is out of bounds");
        return false;
    }

    return true;
}

/**
 * Проверяет корректность значений времени
 *
 * @param _hour
 * @param _minute
 * @param _second
 *
 * @return true, если всё верно, иначе false
 */
bool DateTime::isValidDate(int _year, int _month, int _day)
{
    if (_year < 1 || _year > MAX_YEAR) {
        setLastError("The number of year is out of bounds");
        return false;
    }

    if (_month < 1 || _month > 12) {
        setLastError("The number of month is out of bounds");
        return false;
    }

    if (_day < 1 || _day > 32) {
        setLastError("The number of day is out of bounds");
        return false;
    }

    if ((_day == 31) && (_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11)) {
        setLastError("There is no 31 date in this month");
        return false;
    }

    if ((_day == 30) && (_month == 2)) {
        setLastError("There is no 30 date in this month");
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 4 != 0)) {
        setLastError("There is no 29 date in this month");
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 400 == 0)) {
        setLastError("There is no 29 date in this month");
        return true;
    }

    if ((_month == 2) && (_day == 29) && (_year % 100 == 0)) {
        setLastError("There is no 29 date in this month");
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 4 == 0)) {
        setLastError("There is no 29 date in this month");
        return true;
    }

    return true;
}

/**
 * Устанавливает текущее время в объекте класса
 */
void DateTime::setNow()
{
    time_t rawTime = time(nullptr);
    struct tm* timeInfo = localtime(&rawTime);

    this->year  = timeInfo->tm_year + 1900;
    this->month = timeInfo->tm_mon + 1;
    this->day   = timeInfo->tm_mday;

    this->hour   = timeInfo->tm_hour;
    this->minute = timeInfo->tm_min;
    this->second = timeInfo->tm_sec;
}

/**
 * Возвращает дату, установленную в объекте класса в виде строки
 * @return
 */
std::string DateTime::getDate()
{
    std::string _return = std::to_string(this->year) + "." + std::to_string(this->month) + "." + std::to_string(this->day);
    return _return;
}

/**
 * Возвращает время, установленное в объекте класса в виде строки
 * @return
 */
std::string DateTime::getTime()
{
    std::string _return = std::to_string(this->hour) + "." + std::to_string(this->minute) + "." + std::to_string(this->second);
    return _return;
}

/**
 * Вовзращает дату и время в виде строки в указанном формате
 *
 * Форматы:
 * - Y - год
 * - m - месяц с ведущим нулём
 * - d - день с ведущим нулём
 * - H - часы в 24-часовом формате с ведущим нулём
 * - i - минуты с ведущим нулём
 * - s - секунды с ведущим нулём
 *
 * @param format Y.m.d - H:i:s
 *
 * @return
 */
std::string DateTime::toString(std::string format)
{
    int position;
    std::string tmp;

    // замена года
    position = format.find('Y');
    if (position >= 0) {
        tmp = std::to_string(this->year);
        format.replace(position, 1, tmp);
    }

    // замена месяца
    position = format.find('m');
    if (position >= 0) {
        tmp = std::to_string(this->month);
        if (tmp.length() < 2) {
            tmp = "0" + tmp;
        }
        format.replace(position, 1, tmp);
    }

    // замена дня
    position = format.find('d');
    if (position >= 0) {
        tmp = std::to_string(this->day);
        if (tmp.length() < 2) {
            tmp = "0" + tmp;
        }
        format.replace(position, 1, tmp);
    }

    // замена часа
    position = format.find('H');
    if (position >= 0) {
        tmp = std::to_string(this->hour);
        if (tmp.length() < 2) {
            tmp = "0" + tmp;
        }
        format.replace(position, 1, tmp);
    }

    // замена минуты
    position = format.find('i');
    if (position >= 0) {
        tmp = std::to_string(this->minute);
        if (tmp.length() < 2) {
            tmp = "0" + tmp;
        }
        format.replace(position, 1, tmp);
    }

    // замена секунды
    position = format.find('s');
    if (position >= 0) {
        tmp = std::to_string(this->second);
        if (tmp.length() < 2) {
            tmp = "0" + tmp;
        }
        format.replace(position, 1, tmp);
    }

    return format;
}

/**
 * Выводит дату и время в переданный поток вывода
 *
 * @param stream
 */
void DateTime::print(std::ostream& stream)
{
    stream << toString();
}

/**
 * Возвращает временной тип данных time_t
 *
 * @param rawString
 *
 * @return
 */
time_t DateTime::fromString(const std::string& rawString)
{
    int yy, month, dd, hh, mm, ss;
    tm whenStart{};
    const char *zStart = rawString.c_str();

    scanf(zStart, "%d.%d.%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
    whenStart.tm_year = yy - 1900;
    whenStart.tm_mon = month - 1;
    whenStart.tm_mday = dd;
    whenStart.tm_hour = hh;
    whenStart.tm_min = mm;
    whenStart.tm_sec = ss;
    whenStart.tm_isdst = -1;

    return mktime(&whenStart);
}