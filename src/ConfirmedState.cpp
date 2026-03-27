#include "ConfirmedState.h"
#include "CancelledState.h"
#include "BookingContext.h"
#include <iostream>

void ConfirmedState::confirm(BookingContext &context)
{
    cout << "Booking is already confirmed!" << endl;
}

void ConfirmedState::cancel(BookingContext &context)
{
    cout << "Booking cancelled successfully!" << endl;
    context.setState(new CancelledState());
}

string ConfirmedState::getStateName() const
{
    return "Confirmed";
}