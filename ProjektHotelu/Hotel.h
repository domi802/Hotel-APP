
#ifndef PROJEKTHOTELU_HOTEL_H
#define PROJEKTHOTELU_HOTEL_H

#include <map>
#include "Room.h"
#include "Person.h"
#include "date.h"
#include "Reservation.h"
#include <algorithm>

class Hotel {
    std::vector<Room> ListOfRooms;
    std::map<date, std::vector<Room>> FreeRooms;
    std::map<date, std::vector<Room>> FullRooms;
    std::vector<Reservation> ListOfReservations;
    int nextReservationNumber = 1;
public:
    Hotel(std::vector<Room> _ListOfRooms);
    ~Hotel();

    std::vector<Room> getFreeRooms(std::string Date);
    std::vector<Room> getFreeRooms(std::string DateFrom, std::string DateTo);
    std::vector<std::vector<Room>> getFreeRooms(date DateFrom, date DateTo, int HowPeople);

    std::vector<Room> getFullRooms(std::string Date);
    std::vector<Room> getFullRooms(std::string DateFrom, std::string DateTo);

    int makeReservation(std::vector<Room> RoomList, date DateFrom, date DateTo, int HowPeople, Person PersonOfReservation);
    bool cancelReservation(int ReservationNumber, int Id);
};


#endif //PROJEKTHOTELU_HOTEL_H
