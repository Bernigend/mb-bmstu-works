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
     * Проверяет корректность значений времени
     *
     * @param _hour
     * @param _minute
     * @param _second
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
     * Возвращает временной тип данных time_t
     *
     * @param rawString
     *
     * @return
     */
    static time_t fromString(const std::string& rawString);

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
};


#endif //LABORATORY_WORK_1_DATETIME_H
