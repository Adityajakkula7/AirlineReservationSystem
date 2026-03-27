#include "CancelledState.h"
#include "BookingContext.h"
#include <iostream>

void CancelledState::confirm(BookingContext &context)
{
    cout << "Cannot confirm a Cancelled booking!" << endl;
}

void CancelledState::cancel(BookingContext &context)
{
    cout << "Booking is already cancelled!" << endl;
}

string CancelledState::getStateName() const
{
    return "Cancelled";
}