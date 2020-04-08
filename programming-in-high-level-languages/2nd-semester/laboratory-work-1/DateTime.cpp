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


DateTime::DateTime(DateTime& _dateTime)
{
    this->year  = _dateTime.getYear();
    this->month = _dateTime.getMonth();
    this->day   = _dateTime.getDay();

    this->hour   = _dateTime.getHour();
    this->minute = _dateTime.getMinute();
    this->second = _dateTime.getSecond();
}


DateTime::DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second)
{
    this->year  = _year;
    this->month = _month;
    this->day   = _day;

    this->hour   = _hour;
    this->minute = _minute;
    this->second = _second;
}


bool DateTime::isValid()
{
    if (!isValidDate(this->year, this->month, this->day)) {
        return false;
    }

    return isValidTime(this->hour, this->minute, this->second);
}


bool DateTime::isValidTime(int _hour, int _minute, int _second)
{
    if (_hour < 0 || _hour > 24) {
        return false;
    }

    if (_minute < 0 || _minute > 59) {
        return false;
    }

    return !(_second < 0 || _second > 60);
}


bool DateTime::isValidDate(int _year, int _month, int _day)
{
    if (_year < 1) {
        return false;
    }

    if (_month < 1 || _month > 12) {
        return false;
    }

    if (_day < 1 || _day > 32) {
        return false;
    }

    if ((_day == 31) && (_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11)) {
        return false;
    }

    if ((_day == 30) && (_month == 2)) {
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 4 != 0)) {
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 400 == 0)) {
        return true;
    }

    if ((_month == 2) && (_day == 29) && (_year % 100 == 0)) {
        return false;
    }

    if ((_month == 2) && (_day == 29) && (_year % 4 == 0)) {
        return true;
    }

    return true;
}


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


std::string DateTime::getDate()
{
    return toString("Y.m.d");
}


std::string DateTime::getTime()
{
    return toString("H:i:s");
}


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


void DateTime::print(std::ostream& stream)
{
    stream << toString();
}


DateTime DateTime::fromString(const std::string& rawString)
{
    int yy, month, dd, hh, mm, ss;
    const char *zStart = rawString.c_str();

    sscanf(zStart, "%d.%d.%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);

//    std::cout << yy << std::endl;
//    std::cout << month << std::endl;
//    std::cout << dd << std::endl;
//    std::cout << hh << std::endl;
//    std::cout << mm << std::endl;
//    std::cout << ss << std::endl;

    DateTime newDateTime(yy, month, dd, hh, mm, ss);
    return newDateTime;
}