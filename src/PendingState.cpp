#include "PendingState.h"
#include "ConfirmedState.h"
#include "BookingContext.h"
#include <iostream>

void PendingState::confirm(BookingContext &context)
{
    cout << "Booking confirmed successfully!" << endl;
    context.setState(new ConfirmedState());
}

void PendingState::cancel(BookingContext &context)
{
    cout << "Cannot cancel a Pending booking. Confirm it first!" << endl;
}

string PendingState::getStateName() const
{
    return "Pending";
}