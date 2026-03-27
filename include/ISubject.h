#pragma once
#include "IObserver.h"
#include <vector>
using namespace std;

class ISubject
{
protected:
    vector<IObserver *> observers;

public:
    void addObserver(IObserver *observer)
    {
        observers.push_back(observer);
    }

    void removeObserver(IObserver *observer)
    {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end());
    }

    void notifyObservers(const string &event, const string &details)
    {
        for (IObserver *obs : observers)
        {
            obs->update(event, details);
        }
    }
};