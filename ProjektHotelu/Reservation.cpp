
#include "Reservation.h"
#include "date.h"
Reservation::Reservation(int _ReservationNumber, Person _PersonOfReservation, date _DateFrom,
                         date _DateTo, int _HowPeople, std::vector<Room> _RoomList) : PersonOfReservation(_PersonOfReservation) {
    this->ReservationNumber=_ReservationNumber;
    this->DateFrom = *new date(_DateFrom);
    this->DateTo = *new date(_DateTo);
    this->HowPeople=_HowPeople;
    this->RoomList=_RoomList;
}

date::date(){}

Reservation::~Reservation() {

}

int Reservation::getReservationNumber() {
    return this->ReservationNumber;
}

Person Reservation::getPersonOfReservation() {
    return this->PersonOfReservation;
}

date Reservation::getDateFrom() {
    return this->DateFrom;
}

date Reservation::getDateTo() {
    return this->DateTo;
}

int Reservation::getHowPeople() {
    return this->HowPeople;
}

std::vector<Room> Reservation::getRoomList() {
    return this->RoomList;
}









