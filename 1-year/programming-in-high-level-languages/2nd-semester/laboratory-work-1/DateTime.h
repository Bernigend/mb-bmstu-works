//
// Created by Bernigend on 22.03.2020.
//

#include <string>

#ifndef LABORATORY_WORK_1_DATETIME_H
#define LABORATORY_WORK_1_DATETIME_H


class DateTime {
protected:
    int year;
    int month;
    int day;

    int hour;
    int minute;
    int second;

    static std::string lastError;

    static const unsigned int MAX_YEAR = 10000;

    static inline void setLastError(const std::string& _lastError) {
        DateTime::lastError = _lastError;
    }

public:
    DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second) {
        this->year  = _year;
        this->month = _month;
        this->day   = _day;

        this->hour   = _hour;
        this->minute = _minute;
        this->second = _second;
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
    static bool isValidTime(int _hour, int _minute, int _second)
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
    static bool isValidDate(int _year, int _month, int _day)
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

    // // //
    // Setters
    // // //

    inline void setYear(int _year) {
        this->year = _year;
    }

    inline void setMonth(int _month) {
        this->month = _month;
    }

    inline void setDay(int _day) {
        this->day = _day;
    }

    inline void setHour(int _hour) {
        this->hour = _hour;
    }

    inline void setMinute(int _minute) {
        this->minute = _minute;
    }

    inline void setSecond(int _second) {
        this->second = _second;
    }

    // // //
    // Getters
    // // //

    inline int getYear() const {
        return this->year;
    }

    inline int getMonth() const {
        return this->month;
    }

    inline int getDay() const {
        return this->day;
    }

    inline int getHour() const {
        return this->hour;
    }

    inline int getMinute() const {
        return this->minute;
    }

    inline int getSecond() const {
        return this->second;
    }

    inline static const std::string &getLastError() {
        return DateTime::lastError;
    }
};


#endif //LABORATORY_WORK_1_DATETIME_H
