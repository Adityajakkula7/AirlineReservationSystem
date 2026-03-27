#pragma once
#include <string>
#include "IObserver.h"
using namespace std;

class SMSNotification : public IObserver
{
private:
    string phoneNumber;

public:
    SMSNotification(string phoneNumber);
    void update(const string &event, const string &details) override;
};