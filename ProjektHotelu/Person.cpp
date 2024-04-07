
#include <iostream>
#include <algorithm>
#include "Person.h"

Person::Person(std::string _Name, std::string _Surname, int _PhoneNumber, std::string _Mail) {
    this -> Id = nextId++;
    this -> Name = _Name;
    this -> Surname = _Surname;
    this -> PhoneNumber = _PhoneNumber;
    this -> Mail = _Mail;
    std::cout << "Twoj identyfikator ID to: " << this -> Id << std::endl;
}

Person::~Person() {

}

int Person::getId() {
    return this -> Id;
}

std::string Person::getName() {
    return this -> Name;
}

std::string Person::getSurname() {
    return this -> Surname;
}

int Person::getPhoneNumber() {

    return this -> PhoneNumber;
}

std::string Person::getMail() {
    return this -> Mail;
}

std::vector<int> Person::getReservationList() {
    return this -> ReservationsList;
}

void Person::addReservation(int ReservationNum) {
    this -> ReservationsList.push_back(ReservationNum);
}

void Person::removeReservation(int ReservationNum) {
    this -> ReservationsList.erase(std::remove(ReservationsList.begin(), ReservationsList.end(), ReservationNum ), ReservationsList.end());
}

