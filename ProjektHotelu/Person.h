

#ifndef PROJEKTHOTELU_PERSON_H
#define PROJEKTHOTELU_PERSON_H
#include <string>
#include <vector>

class Person {
static int nextId;
int Id;
std::string Name;
std::string Surname;
int PhoneNumber;
std::string Mail;
std::vector<int> ReservationsList;

public:
Person(std::string _Name, std::string _Surname, int _PhoneNumber, std::string _Mail);

~Person();

int getId();
std::string getName();
std::string getSurname();
int getPhoneNumber();
std::string getMail();
std::vector<int> getReservationList();
void addReservation(int ReservationNum);
void removeReservation(int ReservationNum);
};


#endif //PROJEKTHOTELU_PERSON_H
