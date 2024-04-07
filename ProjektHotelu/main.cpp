#include <iostream>
#include <limits>
#include "Hotel.h"
#include "Person.h"
int Person::nextId = 1;
using namespace std;
int main() {
    string name;
    string surname;
    int number;
    string mail;
    int personCount;
    int day;
    int month;
    int year;
    int dayl;
    int monthl;
    int yearl;
    int optRoom;
    int numRez;
    int personId;
    vector<Room> rooms;
    rooms.emplace_back(100, 1, "lazienka w pokoju z widokiem na morze");
    rooms.emplace_back(101, 4, "widok na morze");
    rooms.emplace_back(102, 3, "widok na gory");
    rooms.emplace_back(103, 3, "aneks kuchenny w pokoju");
    rooms.emplace_back(104, 2, "jacuzzi na tarasie");
    rooms.emplace_back(105, 2, "Ogromny telewizor i konsola do gier");
    rooms.emplace_back(106, 6, "ogromy stol obiadowy do wspolnych posilkow");
    Hotel mariott(rooms);

    date comeDate(1, 5, 2023);
    date leftDate(3, 5, 2023);
    Person Dominik("Dominik","Wozniak",695789123,"domat2010@xd.pl");
   auto firstRez = mariott.getFreeRooms(comeDate, leftDate, 7);
   auto reserwationNum = mariott.makeReservation(firstRez[0],comeDate,leftDate,7,Dominik);
    for(int i = 0; i < firstRez.size(); i++)
    {
        cout << "Wariant nr " << i+1 << ":" << endl;
        for(int j = 0; j < firstRez[i].size();j++){
            cout << "Pokoj nr: " << firstRez[i][j].getRoomNum()<< " " << firstRez[i][j].getPlacesInRoom()<< " osobowy" << std::endl;
        }
        std::cout<<std::endl;
    }
    cout << "Brawo "<< Dominik.getName() << " udao sie zarezerwowac pokoje" <<  endl;
    cout<< "Twoj numer rezerwacji to: " << reserwationNum << std::endl;

    auto anRez = mariott.cancelReservation(reserwationNum,Dominik.getId());
    cout << "rezerwacja numer " << reserwationNum << " Zostala anulowana pokoje wrocily do puli pokoi"<<endl;
    bool continueProgram = true;
    while (continueProgram) {
    int  opt;
    cout<< "Podaj co chcesz zrobic 1 - Nowa rezerwacja 2- Anuluj Rezerwacje" << endl;
        cin >> opt;
        switch (opt) {
            case 1: {
                cout << "podaj date kiedy planujesz przyjechac format d m r" << endl;
                cin >> day >> month >> year;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "podaj date kiedy planujesz przyjechac format d m r" << endl;
                    cin >> day >> month >> year;
                }
                cout << "Podaj date wyjazdu d m r " << endl;
                cin >> dayl >> monthl >> yearl;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Podaj date wyjazdu d m r " << endl;
                    cin >> dayl >> monthl >> yearl;
                }
                cout << "Podaj ile osob ma byc" << endl;
                cin >> personCount;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Podaj ile osob ma byc" << endl;
                    cin >> personCount;
                }
                date come(day, month, year);
                date out(dayl, monthl, yearl);
                if(come > out)
                {
                    cout << "Dada wyjazdu nie moze byc mniejsza od daty przyjazdu" << endl;
                }

                auto werPok = mariott.getFreeRooms(come, out, personCount);

                if (werPok.size() <= 0) {
                    cout << "Nie znaleziono pokoi na podane dni." << endl;
                    break;
                }

                for(int i = 0; i < werPok.size(); i++)
                {
                    cout << "Wariant nr " << i+1 << ":" << endl;
                        for(int j = 0; j < werPok[i].size();j++){
                        cout << "\tPokoj nr: " << werPok[i][j].getRoomNum()<< " " << werPok[i][j].getPlacesInRoom()<< " osobowy " << "\tInformacje dodatkowe:  " << werPok[i][j].getDescription() <<  std::endl;
                    }
                    std::cout<<std::endl;
                }

                cout << "Wybierz wariant pokoi ";
                cin >> optRoom;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Wybierz wariant pokoi ";
                    cin >> optRoom;
                }
                if (optRoom  > werPok.size() || optRoom < 1) {
                    optRoom = 1;
                }

                cout << "Podaj dane kontakowe" << endl;
                cout << "\tPodaj imie" << endl << "\t";
                cin >> name;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "\tPodaj imie" << endl << "\t";
                    cin >> name;
                }
                cout << "\tPodaj nazwisko" << endl << "\t";
                cin >> surname;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "\tPodaj nazwisko" << endl << "\t";
                    cin >> surname;
                }
                cout << "\tPodaj numer telefonu" << endl << "\t";
                cin >> number;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "\tPodaj numer telefonu" << endl << "\t";
                    cin >> number;
                }
                cout << "\tPodaj maila" << endl << "\t";
                cin >> mail;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                    cout << "\tPodaj maila" << endl << "\t";
                    cin >> mail;
                }
                Person guest(name, surname, number, mail);
                auto rez = mariott.makeReservation(werPok[optRoom-1], come, out, personCount, guest);
                cout << guest.getName() << " dokonales rezerwacji"<<endl;
                if(rez == 0)
                {
                    cout << "Nie udalo sie dokonac rezerwacji" << endl;
                }

                cout << "Twoj numer rezerwacji to: " << rez << endl;
                cout << "Twoj wariant pokoi to:  " << optRoom << endl;
                for(int j = 0; j < werPok[optRoom-1].size();j++){
                    cout << "\tPokoj nr: " << werPok[optRoom-1][j].getRoomNum()<< " " << werPok[optRoom-1][j].getPlacesInRoom()<< " osobowy " << "\tInformacje dodatkowe:  " << werPok[optRoom-1][j].getDescription() << std::endl;
                }
                cout << "Twoja data przyjazdu to: ";
                come.printDate();
                cout << "Opuszczasz nas: ";
                out.printDate();
                break;
            }
            case 2: {
                cout << "Podaj Numer rezerwacji " << endl;
                cin >> numRez;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Podaj Numer rezerwacji " << endl;
                    cin >> numRez;
                }
                cout << "Podaj swoje ID ";
                cin >> personId;
                while (cin.fail()) {
                    cin.clear();
                    cin.sync();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Podaj swoje ID: ";
                    cin >> personId;
                }
                auto anuRez = mariott.cancelReservation(numRez, personId);
                cout << "Twoja rezerwacja zostala anulowana a pokoje wrocily do puli dostepnych pokoi" << endl;
            }
        }
        char answer;
        cout << "Czy chcesz kontynuowac program? (T/N)" << endl;
        cin >> answer;
        if (tolower(answer) == 'n') {
            continueProgram = false;
        }
        else if(tolower(answer) == 't'){
            continue;
        }else{
            break;
        }

        return 0;
    }
}

