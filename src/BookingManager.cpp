#include "BookingManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>

string BookingManager::generateBookingId()
{
    ostringstream oss;
    oss << "BK" << setw(3) << setfill('0') << bookingCounter++;
    return oss.str();
}

Booking BookingManager::createBooking(Passenger &passenger, Flight &flight, Seat &seat)
{
    string id = generateBookingId();
    seat.book();
    Booking b(id, passenger, flight, seat);
    bookings.insert({id, b});
    return b;
}

Booking *BookingManager::getBooking(const string &bookingId)
{
    auto it = bookings.find(bookingId);
    if (it != bookings.end())
    {
        return &it->second;
    }
    return nullptr;
}

bool BookingManager::cancelBooking(const string &bookingId)
{
    Booking *b = getBooking(bookingId);
    if (b != nullptr)
    {
        return b->cancel();
    }
    return false;
}

void BookingManager::listAllBookings() const
{
    cout << "---- All Bookings ----" << endl;
    for (const auto &pair : bookings)
    {
        cout << pair.first
             << " | " << pair.second.getTotalAmount()
             << " | " << pair.second.getStatusAsString()
             << endl;
    }
    cout << "----------------------" << endl;
}