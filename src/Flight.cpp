#include "Flight.h"

Flight::Flight(string flightNumber, Airport origin, Airport destination, int totalSeats)
    : flightNumber(flightNumber), origin(origin), destination(destination), totalSeats(totalSeats), availableSeats(totalSeats)
{
    // body is now empty — initialization done above
}

string Flight::getFlightNumber() const { return flightNumber; }
Airport Flight::getOrigin() const { return origin; }
Airport Flight::getDestination() const { return destination; }
int Flight::getAvailableSeats() const { return availableSeats; }

bool Flight::bookSeat()
{
    if (availableSeats > 0)
    {
        availableSeats--;
        return true;
    }
    return false;
}