//
// Created by Dominik Woźniak on 19/04/2023.
//

#include "Hotel.h"
#include "Reservation.h"

Hotel::Hotel(std::vector<Room> _ListOfRooms) {
    std::sort(_ListOfRooms.begin(), _ListOfRooms.end());
    std::reverse(_ListOfRooms.begin(), _ListOfRooms.end());
    this->ListOfRooms = _ListOfRooms;
}

Hotel::~Hotel() {

}

std::vector<Room> Hotel::getFreeRooms(std::string Date) {
    return std::vector<Room>();
}

std::vector<Room> Hotel::getFreeRooms(std::string DateFrom, std::string DateTo){
    return std::vector<Room>();
}

std::vector<std::vector<Room>> Hotel::getFreeRooms(date DateFrom, date DateTo, int HowPeople) {
    std::vector<std::vector<Room>> roomsToReturn; //Zmienna roomsToReturn to wektor wektorów obiektów klasy Room, który zostanie zwrócony przez funkcję.

    date dateTemp(DateFrom.getDay(), DateFrom.getMonth(), DateFrom.getYear());
    while (dateTemp <= DateTo){  //Pętla while iteruje przez wszystkie daty w przedziale DateFrom-DateTo.
        if (FreeRooms.count(dateTemp) == 0){
            std::vector<Room> roomsTemp(ListOfRooms); //Jeśli nie ma wolnych pokojów w danym dniu (dateTemp) w mapie FreeRooms, do mapy zostaje dodany nowy wpis, w którym kluczem jest data, a wartością wektor pokojów (ListOfRooms).
            FreeRooms[dateTemp] = roomsTemp;
        }
        std::vector<std::vector<Room>> tempRoomsToReturn;
        for (int i = 0; i < FreeRooms[dateTemp].size(); i++){
            std::vector<Room> temp = std::vector<Room>();
            int peopleCount = 0;
            for (int j = i; j < FreeRooms[dateTemp].size(); j++){
                if (peopleCount + FreeRooms[dateTemp][j].getPlacesInRoom() < HowPeople){
                    temp.push_back(FreeRooms[dateTemp][j]);             //Pętla for iteruje po wektorze pokojów dla danego dnia i tworzy tymczasowy wektor temp, który przechowuje aktualnie przetwarzane pokoje.
                    peopleCount += FreeRooms[dateTemp][j].getPlacesInRoom();
                } else if (peopleCount + FreeRooms[dateTemp][j].getPlacesInRoom() == HowPeople) {
                    temp.push_back(FreeRooms[dateTemp][j]);
                    peopleCount += FreeRooms[dateTemp][j].getPlacesInRoom();
                    tempRoomsToReturn.push_back(temp);
                    break;
                }
            }
        }
        std::vector<std::vector<Room>> newRoomsToReturn;
        if (dateTemp > DateFrom){
            for (int i = 0; i < roomsToReturn.size(); i++){
                for (int j = 0; j < tempRoomsToReturn.size(); j++){ //Ten fragment kodu sprawdza, czy dany pokój był już zwrócony jako wolny w poprzednich dniach i jeśli tak, to dodaje go do nowego wektora
                    if (roomsToReturn[i] == tempRoomsToReturn[j]){
                        newRoomsToReturn.push_back(roomsToReturn[i]);
                    }
                }
            }

            roomsToReturn = newRoomsToReturn;
        }else{
            roomsToReturn = tempRoomsToReturn;
        }

        dateTemp++;
    }
    roomsToReturn.erase(std::unique(roomsToReturn.begin(), roomsToReturn.end()), roomsToReturn.end());
    return roomsToReturn;
}

std::vector<Room> Hotel::getFullRooms(std::string Date) {
    return std::vector<Room>();
}

std::vector<Room> Hotel::getFullRooms(std::string DateFrom, std::string DateTo) {
    return std::vector<Room>();
}

int Hotel::makeReservation(std::vector<Room> RoomList, date DateFrom, date DateTo, int HowPeople,
                           Person PersonOfReservation) { //    // Pobranie listy wolnych pokojów dla podanego przedziału dat
    std::vector<std::vector<Room>> available = Hotel::getFreeRooms(DateFrom,DateTo,HowPeople); // Posortowanie listy wybranych pokojów w kolejności malejącej
    std::sort(RoomList.begin(), RoomList.end());
    std::reverse(RoomList.begin(), RoomList.end());
    bool isFree = false; // // Sprawdzenie, czy wybrane pokoje są dostępne w podanym przedziale dat
    for(std::vector<Room> w : available){
        std::sort(w.begin(),w.end());
        std::reverse(w.begin(),w.end());
        if(w == RoomList)
        {
            isFree = true;
        }
    }
    if(!isFree)
    {
        return 0; // // Jeśli wybrane pokoje są już zajęte w podanym przedziale dat, zwracamy 0
    }
    // Usunięcie wybranych pokojów z listy wolnych pokoi
    for(date d = DateFrom; d <= DateTo; d++){
        if (FreeRooms.find(d) == FreeRooms.end()) { // Sprawdzamy, czy na ten dzień już istnieje wektor pustych pokojow
            std::vector<Room> roomsForDay(ListOfRooms); // Tworzymy nowy wektor pokojow dla tego dnia
            FreeRooms[d] = roomsForDay; // Dodajemy wektor do mapy FullRooms pod kluczem d
        }
        for(const auto& room : RoomList){ // // Usuwamy pokoj dla danego dnia
            FreeRooms[d].erase(std::remove(FreeRooms[d].begin(), FreeRooms[d].end(), room), FreeRooms[d].end()); // Usuwamy pokoj dla danego dnia
        }
        // Tworzenie nowej rezerwacji i dodanie jej do listy rezerwacji
        std::sort(FreeRooms[d].begin(), FreeRooms[d].end());
        std::reverse(FreeRooms[d].begin(), FreeRooms[d].end());
    }

    Reservation newReservation(nextReservationNumber++, PersonOfReservation, DateFrom, DateTo, HowPeople,RoomList);

    // Dodanie wybranych pokojów do listy zajętych pokoi na podane daty
    for(date d = DateFrom; d <= DateTo; d++){
        if (FullRooms.find(d) == FullRooms.end()) { // Sprawdzamy, czy na ten dzień już istnieje wektor rezerwacji
            std::vector<Room> roomsForDay; // Tworzymy nowy wektor pokojow dla tego dnia
            FullRooms[d] = roomsForDay; // Dodajemy wektor do mapy FullRooms pod kluczem d
        }
        for(const auto& room : RoomList){
            FullRooms[d].push_back(room); // Dodajemy pokoj na końcu wektora pokojow dla danego dnia
        }
        // Sortowanie i odwrócenie kolejności pokojów dla danego dnia
        std::sort(FullRooms[d].begin(), FullRooms[d].end());
        std::reverse(FullRooms[d].begin(), FullRooms[d].end());
    }

    ListOfReservations.push_back(newReservation);

    PersonOfReservation.addReservation(newReservation.getReservationNumber());

    return newReservation.getReservationNumber(); // Zwracamy numer rezerwacji
}

bool Hotel::cancelReservation(int ReservationNumber, int Id) {
    bool isCancelled = false;
    date DateFrom;
    date DateTo;
    std::vector<Room> RoomList;
    // Iterujemy przez wszystkie rezerwacje w hotelu
    for (auto reservation : ListOfReservations){
        if (reservation.getReservationNumber() == ReservationNumber){
            if (reservation.getPersonOfReservation().getId() == Id){
                isCancelled = true;
                DateFrom = reservation.getDateFrom();
                DateTo = reservation.getDateTo();
                RoomList = std::vector<Room>(reservation.getRoomList());
                reservation.getPersonOfReservation().removeReservation(reservation.getReservationNumber());
                break;
            }else{
                std::cout << "Wrong Person Id for cancelling the reservation." << std::endl;
            }
        }
    }
    // Jeżeli rezerwacja nie została anulowana, zwróć fałsz
    if (!isCancelled){
        std::cout << "Could not cancel the reservation." << std::endl;
        return false;
    }

    // Dodanie wybranych pokojów do listy wolnych pokoi
    for(date d = DateFrom; d <= DateTo; d++){
        for(const auto& room : RoomList){
            FreeRooms[d].push_back(room);  // Dodajemy pokoj dla danego dnia
        }

        std::sort(FreeRooms[d].begin(), FreeRooms[d].end());
        std::reverse(FreeRooms[d].begin(), FreeRooms[d].end());
    }

    // Usuniecie wybranych pokojów z listy zajętych pokoi na podane daty
    for(date d = DateFrom; d <= DateTo; d++){
        for(const auto& room : RoomList){
            FullRooms[d].erase(std::remove(FullRooms[d].begin(), FullRooms[d].end(), room), FullRooms[d].end()); // Usuwamy pokoj dla danego dnia
        }

        std::sort(FullRooms[d].begin(), FullRooms[d].end());
        std::reverse(FullRooms[d].begin(), FullRooms[d].end());
    }
    // Usunięcie rezerwacji z listy rezerwacji w hotelu
    auto isEqualToGivenReservationNumber = [&ReservationNumber](Reservation r) { return r.getReservationNumber() == ReservationNumber; };
    auto it = std::find_if(ListOfReservations.begin(), ListOfReservations.end(), isEqualToGivenReservationNumber);
    ListOfReservations.erase(it);

    return true;
}


