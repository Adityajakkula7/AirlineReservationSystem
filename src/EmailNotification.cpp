#include "EmailNotification.h"
#include <iostream>

EmailNotification::EmailNotification(string emailAddress)
    : emailAddress(emailAddress) {}

void EmailNotification::update(const string &event, const string &details)
{
    cout << "[EMAIL to " << emailAddress << "]" << endl;
    cout << "  Event   : " << event << endl;
    cout << "  Details : " << details << endl;
}