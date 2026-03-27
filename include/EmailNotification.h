#pragma once
#include <string>
#include "IObserver.h"
using namespace std;

class EmailNotification : public IObserver
{
private:
    string emailAddress;

public:
    EmailNotification(string emailAddress);
    void update(const string &event, const string &details) override;
};