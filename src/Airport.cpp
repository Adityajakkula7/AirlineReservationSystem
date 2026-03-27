#include "Airport.h"

Airport::Airport(string code, string name, string city)
{
    this->code = code;
    this->name = name;
    this->city = city;
}

string Airport::getCode() const { return code; }
string Airport::getName() const { return name; }
string Airport::getCity() const { return city; }