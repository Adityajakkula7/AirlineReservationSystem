#include "UPIPayment.h"
#include <iostream>

UPIPayment::UPIPayment(string upiId) : upiId(upiId) {}

bool UPIPayment::pay(double amount)
{
    cout << "Processing UPI payment of Rs." << amount
         << " from UPI ID: " << upiId << endl;
    cout << "UPI Payment Successful!" << endl;
    return true;
}