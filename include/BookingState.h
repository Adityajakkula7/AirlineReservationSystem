#pragma once
#include <string>
using namespace std;

// Forward declaration — BookingContext will be defined later
class BookingContext;

class BookingState
{
public:
    virtual void confirm(BookingContext &context) = 0;
    virtual void cancel(BookingContext &context) = 0;
    virtual string getStateName() const = 0;
    virtual ~BookingState() {}
};