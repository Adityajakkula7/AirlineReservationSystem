#pragma once
#include "BookingState.h"

class PendingState : public BookingState
{
public:
    void confirm(BookingContext &context) override;
    void cancel(BookingContext &context) override;
    string getStateName() const override;
};