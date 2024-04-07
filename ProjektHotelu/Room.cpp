
#include "Room.h"

Room::Room(int _RoomNum, int _PlacesInRoom, std::string _Description) {
this -> RoomNum = _RoomNum;
this -> PlacesInRoom = _PlacesInRoom;
this -> Description = _Description;
}

Room::~Room() {

}

int Room::getRoomNum() {
    return this -> RoomNum;
}

int Room::getPlacesInRoom() {
    return this -> PlacesInRoom;
}

std::string Room::getDescription() {
    return this -> Description;
}

bool Room::operator==(const Room &room) const {
    return this->RoomNum == room.RoomNum;
}

bool Room::operator<(const Room &room) const {
    return this->PlacesInRoom < room.PlacesInRoom;
}

bool Room::operator>(const Room &room) const {
    return this->PlacesInRoom > room.PlacesInRoom;;
}
