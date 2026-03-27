#pragma once
#include "BookingState.h"
#include <string>
using namespace std;

class BookingContext
{
private:
    BookingState *currentState;

public:
    BookingContext();
    ~BookingContext();

    void setState(BookingState *newState);
    void confirm();
    void cancel();
    string getStateName() const;
};
