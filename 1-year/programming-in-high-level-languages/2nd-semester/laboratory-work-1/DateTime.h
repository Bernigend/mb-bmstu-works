//
// Created by Bernigend on 22.03.2020.
//

#include <iostream>
#include <ctime>
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

public:
    /**
     * Конструктор класса по умолчанию
     */
    DateTime();

    /**
     * Конструктор класса (копирование)
     *
     * @param _dateTime
     */
    DateTime(DateTime& _dateTime);

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
    DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second);

    /**
     * Проверяет корректность данных, уже установленных в объекте класса
     * @return
     */
    bool isValid();

    /**
     * Проверяет корректность значений времени
     *
     * @param _hour
     * @param _minute
     * @param _second
     *
     * @return true, если всё верно, иначе false
     */
    static bool isValidTime(int _hour, int _minute, int _second);

    /**
     * Проверяет корректность значений даты
     *
     * @param _year
     * @param _month
     * @param _day
     *
     * @return true, если всё верно, иначе false
     */
    static bool isValidDate(int _year, int _month, int _day);

    /**
     * Устанавливает текущее время в объекте класса
     */
    void setNow();

    /**
     * Возвращает дату, установленную в объекте класса в виде строки
     * @return
     */
    std::string getDate();

    /**
     * Возвращает время, установленное в объекте класса в виде строки
     * @return
     */
    std::string getTime();

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
    std::string toString(std::string format = "Y.m.d H:i:s");

    /**
     * Выводит дату и время в переданный поток вывода
     *
     * @param stream
     */
    void print(std::ostream& stream);

    /**
     * Возвращает инициализированный объект класса данными из строки
     *
     * @param rawString
     *
     * @return
     */
    static DateTime fromString(const std::string& rawString);

    // // //
    // Setters
    // // //

    inline bool setYear(int _year);

    inline bool setMonth(int _month);

    inline bool setDay(int _day);

    inline bool setHour(int _hour);

    inline bool setMinute(int _minute);

    inline bool setSecond(int _second);

    // // //
    // Getters
    // // //

    inline int getYear() const;

    inline int getMonth() const;

    inline int getDay() const;

    inline int getHour() const;

    inline int getMinute() const;

    inline int getSecond() const;
};


bool DateTime::setYear(int _year) {
    if (!DateTime::isValidDate(_year, this->month, this->day)) {
        return false;
    }
    this->year = _year;
    return true;
}


bool DateTime::setMonth(int _month) {
    if (!DateTime::isValidDate(this->year, _month, this->day)) {
        return false;
    }
    this->month = _month;
    return true;
}


bool DateTime::setDay(int _day) {
    if (!DateTime::isValidDate(this->year, this->month, _day)) {
        return false;
    }
    this->day = _day;
    return true;
}


bool DateTime::setHour(int _hour) {
    if (!DateTime::isValidTime(_hour, this->minute, this->second)) {
        return false;
    }
    this->hour = _hour;
    return true;
}


bool DateTime::setMinute(int _minute) {
    if (!DateTime::isValidTime(this->hour, _minute, this->second)) {
        return false;
    }
    this->minute = _minute;
    return true;
}


bool DateTime::setSecond(int _second) {
    if (!DateTime::isValidTime(this->hour, this->minute, _second)) {
        return false;
    }
    this->second = _second;
    return true;
}


int DateTime::getYear() const {
    return this->year;
}


int DateTime::getMonth() const {
    return this->month;
}


int DateTime::getDay() const {
    return this->day;
}


int DateTime::getHour() const {
    return this->hour;
}


int DateTime::getMinute() const {
    return this->minute;
}


int DateTime::getSecond() const {
    return this->second;
}


#endif //LABORATORY_WORK_1_DATETIME_H
