#include "NetBankingPayment.h"
#include <iostream>

NetBankingPayment::NetBankingPayment(string bankName, string accountNumber)
    : bankName(bankName), accountNumber(accountNumber) {}

bool NetBankingPayment::pay(double amount)
{
    cout << "Processing Net Banking payment of Rs." << amount
         << " via " << bankName << endl;
    cout << "Net Banking Payment Successful!" << endl;
    return true;
}