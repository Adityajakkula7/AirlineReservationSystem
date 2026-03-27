#pragma once
#include <string>
#include "Airport.h"
using namespace std;

class Flight
{
private:
    string flightNumber;
    Airport origin;
    Airport destination;
    int totalSeats;
    int availableSeats;

public:
    Flight() : totalSeats(0), availableSeats(0) {};
    Flight(string flightNumber, Airport origin, Airport destination, int totalSeats);

    string getFlightNumber() const;
    Airport getOrigin() const;
    Airport getDestination() const;
    int getAvailableSeats() const;
    bool bookSeat();
};