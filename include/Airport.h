#pragma once
#include <string>
using namespace std;

class Airport
{
private:
    string code; // e.g. "BOM"
    string name; // e.g. "Chhatrapati Shivaji"
    string city; // e.g. "Mumbai"

public:
    Airport() {};
    Airport(string code, string name, string city);

    string getCode() const;
    string getName() const;
    string getCity() const;
};