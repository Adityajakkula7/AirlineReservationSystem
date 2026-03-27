#pragma once

class PaymentStrategy
{
public:
    virtual bool pay(double amount) = 0; // pure virtual
    virtual ~PaymentStrategy() {}
};