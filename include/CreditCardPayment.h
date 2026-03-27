#pragma once
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class CreditCardPayment : public PaymentStrategy
{
private:
    string cardNumber;
    string cardHolder;

public:
    CreditCardPayment(string cardNumber, string cardHolder);
    bool pay(double amount) override;
};