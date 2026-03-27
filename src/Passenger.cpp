#include "Passenger.h"

Passenger::Passenger(string passengerId, string name, string email, string phone)
    : passengerId(passengerId), name(name), email(email), phone(phone)
{
}

string Passenger::getPassengerId() const { return passengerId; }
string Passenger::getName() const { return name; }
string Passenger::getEmail() const { return email; }
string Passenger::getPhone() const { return phone; }