#include "Seat.h"

Seat::Seat(string seatNumber, SeatType type, double price)
    : seatNumber(seatNumber), type(type), price(price), isBooked(false)
{
}

string Seat::getSeatNumber() const { return seatNumber; }
SeatType Seat::getType() const { return type; }
double Seat::getPrice() const { return price; }
bool Seat::getIsBooked() const { return isBooked; }

bool Seat::book()
{
    if (!isBooked)
    {
        isBooked = true;
        return true;
    }
    return false;
}

string Seat::getTypeAsString() const
{
    if (type == SeatType::ECONOMY)
        return "Economy";
    if (type == SeatType::BUSINESS)
        return "Business";
    return "First Class";
}