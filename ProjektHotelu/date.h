
#ifndef PROJEKTHOTELU_DATE_H
#define PROJEKTHOTELU_DATE_H
#include <iostream>

class date {

private:
    int day;
    int month;
    int year;
    bool isLeapYear();
    int daysInMonth();
public:
    date();
    date(int d, int m, int y) ;

    date(const date& other);

    void setDay(int d);

    void setMonth(int m);

    void setYear(int y);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void printDate() const;

    bool operator<(const date& other) const;

    bool operator>(const date& other) const;

    bool operator<=(const date& other) const;

    bool operator>=(const date& other) const;

    bool operator==(const date& other) const;

    bool operator!=(const date& other) const;

    date & operator=(const date& other);

    date operator++(int i);
};



#endif //PROJEKTHOTELU_DATE_H
