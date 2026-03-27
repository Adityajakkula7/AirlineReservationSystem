#include "CreditCardPayment.h"
#include <iostream>

CreditCardPayment::CreditCardPayment(string cardNumber, string cardHolder)
    : cardNumber(cardNumber), cardHolder(cardHolder) {}

bool CreditCardPayment::pay(double amount)
{
    cout << "Processing Credit Card payment of Rs." << amount
         << " for " << cardHolder << endl;
    cout << "Credit Card Payment Successful!" << endl;
    return true;
}