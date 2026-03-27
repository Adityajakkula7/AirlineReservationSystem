#include "SMSNotification.h"
#include <iostream>

SMSNotification::SMSNotification(string phoneNumber)
    : phoneNumber(phoneNumber) {}

void SMSNotification::update(const string &event, const string &details)
{
    cout << "[SMS to " << phoneNumber << "]" << endl;
    cout << "  Event   : " << event << endl;
    cout << "  Details : " << details << endl;
}