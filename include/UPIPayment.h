#pragma once
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class UPIPayment : public PaymentStrategy
{
private:
    string upiId;

public:
    UPIPayment(string upiId);
    bool pay(double amount) override;
};