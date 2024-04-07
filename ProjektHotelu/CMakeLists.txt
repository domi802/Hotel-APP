cmake_minimum_required(VERSION 3.24)
project(ProjektHotelu)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjektHotelu main.cpp Room.cpp Room.h Person.cpp Person.h Reservation.cpp Reservation.h Hotel.cpp Hotel.h date.cpp date.h)
