
#ifndef PROJEKTHOTELU_ROOM_H
#define PROJEKTHOTELU_ROOM_H
#include <string>

class Room {
int RoomNum;
int PlacesInRoom;
std::string Description;

public:

Room(int _RoomNum, int _PlacesInRoom, std::string _Description);

~Room();

int getRoomNum();
int getPlacesInRoom();
std::string getDescription();

bool operator ==(const Room& room) const;
bool operator <(const Room& room) const;
bool operator >(const Room& room) const;
};


#endif //PROJEKTHOTELU_ROOM_H
