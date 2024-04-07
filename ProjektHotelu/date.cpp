
#include "date.h"

date::date(int d, int m, int y) {
    if (m <= 12 && m > 0){
        this -> month = m;
    }else{
        std::cout << "Podane zly miesiac ustawiono domyslny 1" << std::endl;
        this -> month = 1;
    }
    if(d > 0 && daysInMonth() >= d){
        this -> day = d;
    }else{
        std::cout << "Podane zly dzien ustawiono domyslny 1" << std::endl;
        this -> day = 1;
    }
    if(y >= 2023)
    {
        this -> year = y;
    }else{
        std::cout << "Podane zly rok ustawiono domyslny 2023" << std::endl;
        this -> day = 2023;
    }





}

date::date(const date &other) {

    this->day = other.day;
    this->month = other.month;
    this->year = other.year;

}

bool date::isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int date::daysInMonth() {
    if (month == 2) {
        return isLeapYear() ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void date::setDay(int d) {
    day = d;
}

void date::setMonth(int m) {
    month = m;
}

void date::setYear(int y) {
    year = y;
}

int date::getDay() const {
    return day;
}

int date::getMonth() const {
    return month;
}

int date::getYear() const {
    return year;
}

bool date::operator<(const date &other) const {
    if (year != other.year) {
        return year < other.year;
    }
    else if (month != other.month) {
        return month < other.month;
    }
    else {
        return day < other.day;
    }
}

bool date::operator>(const date &other) const {
    return other < *this;
}

bool date::operator<=(const date &other) const {
    return !(other < *this);
}

bool date::operator>=(const date &other) const {
    return !(*this < other);
}

bool date::operator==(const date &other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool date::operator!=(const date &other) const {
    return !(*this == other);
}

void date::printDate() const {
   std::cout << day << "/" << month << "/" << year << std::endl;
}

date date::operator++(int i) {
    if (day + 1 <= daysInMonth()){
        day++;
    } else if (month + 1 <= 12){
        month++;
        day = 1;
    } else {
        year++;
        month = 1;
        day = 1;
    }

    return *this;
}

date & date::operator=(const date &other) {
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;

    return *this;
}















