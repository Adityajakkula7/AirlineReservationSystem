#pragma once
#include <string>
using namespace std;

class IObserver
{
public:
    virtual void update(const string &event, const string &details) = 0;
    virtual ~IObserver() {}
};