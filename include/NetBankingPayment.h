#pragma once
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class NetBankingPayment : public PaymentStrategy
{
private:
    string bankName;
    string accountNumber;

public:
    NetBankingPayment(string bankName, string accountNumber);
    bool pay(double amount) override;
};