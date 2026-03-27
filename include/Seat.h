#pragma once
#include <string>
using namespace std;

enum class SeatType
{
    ECONOMY,
    BUSINESS,
    FIRST_CLASS
};

class Seat
{
private:
    string seatNumber;
    SeatType type;
    bool isBooked;
    double price;

public:
    Seat() : type(SeatType::ECONOMY), isBooked(false), price(0) {};
    Seat(string seatNumber, SeatType type, double price);

    string getSeatNumber() const;
    SeatType getType() const;
    double getPrice() const;
    bool getIsBooked() const;
    bool book();
    string getTypeAsString() const;
};