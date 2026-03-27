#pragma once
#include <string>
using namespace std;

class Passenger
{
private:
    string passengerId;
    string name;
    string email;
    string phone;

public:
    Passenger() {};
    Passenger(string passengerId, string name, string email, string phone);

    string getPassengerId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;
};