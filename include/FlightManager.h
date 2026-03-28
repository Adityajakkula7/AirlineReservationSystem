#pragma once
#include <vector>
#include "Flight.h"
using namespace std;

class FlightManager
{
private:
    vector<Flight> flights;

    FlightManager() {} // private constructor — nobody can do "new FlightManager()"

public:
    // Delete copy constructor and assignment — prevents copying the singleton
    FlightManager(const FlightManager &) = delete;
    FlightManager &operator=(const FlightManager &) = delete;
    vector<Flight> &getFlights() { return flights; };
    static FlightManager &getInstance()
    {
        static FlightManager instance; // created only once
        return instance;
    }

    void addFlight(const Flight &flight);
    vector<Flight> searchFlights(const string &originCode, const string &destCode) const;
    void listAllFlights() const;
};