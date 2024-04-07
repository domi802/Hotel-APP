

#ifndef PROJEKTHOTELU_RESERVATION_H
#define PROJEKTHOTELU_RESERVATION_H


#include "Person.h"
#include "Room.h"
#include "date.h"

class Reservation{
int ReservationNumber;
Person PersonOfReservation;
date DateFrom;
date DateTo;
int HowPeople;
std::vector<Room> RoomList;

public:
    Reservation(int _ReservationNumber, Person _PersonOfReservation, date _DateFrom, date _DateTo, int _HowPeople, std::vector<Room> _RoomList);
    ~Reservation();

    int getReservationNumber();
    Person getPersonOfReservation();
    date getDateFrom();
    date getDateTo();
    int getHowPeople();
    std::vector<Room> getRoomList();

};


#endif //PROJEKTHOTELU_RESERVATION_H
