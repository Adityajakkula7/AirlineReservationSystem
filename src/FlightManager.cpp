#include "FlightManager.h"
#include <iostream>

void FlightManager::addFlight(const Flight &flight)
{
    flights.push_back(flight);
}

vector<Flight> FlightManager::searchFlights(const string &originCode, const string &destCode) const
{
    vector<Flight> results;
    for (const Flight &f : flights)
    {
        if (f.getOrigin().getCode() == originCode &&
            f.getDestination().getCode() == destCode)
        {
            results.push_back(f);
        }
    }
    return results;
}

void FlightManager::listAllFlights() const
{
    cout << "---- All Flights ----" << endl;
    for (const Flight &f : flights)
    {
        cout << f.getFlightNumber()
             << " | " << f.getOrigin().getCity()
             << " -> " << f.getDestination().getCity()
             << " | Seats: " << f.getAvailableSeats()
             << endl;
    }
    cout << "---------------------" << endl;
}