#include "BookingContext.h"
#include "PendingState.h"

BookingContext::BookingContext()
{
    currentState = new PendingState(); // always starts Pending
}

BookingContext::~BookingContext()
{
    delete currentState;
}

void BookingContext::setState(BookingState *newState)
{
    delete currentState; // free old state
    currentState = newState;
}

void BookingContext::confirm()
{
    currentState->confirm(*this);
}

void BookingContext::cancel()
{
    currentState->cancel(*this);
}

string BookingContext::getStateName() const
{
    return currentState->getStateName();
}