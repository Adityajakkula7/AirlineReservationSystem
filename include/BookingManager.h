#pragma once
#include <map>
#include <string>
#include "Booking.h"
using namespace std;

class BookingManager
{
private:
    map<string, Booking> bookings;
    int bookingCounter;

    BookingManager() : bookingCounter(1) {}

public:
    BookingManager(const BookingManager &) = delete;
    BookingManager &operator=(const BookingManager &) = delete;

    static BookingManager &getInstance()
    {
        static BookingManager instance;
        return instance;
    }

    string generateBookingId();
    Booking createBooking(Passenger &passenger, Flight &flight, Seat &seat);
    Booking *getBooking(const string &bookingId);
    bool cancelBooking(const string &bookingId);
    void listAllBookings() const;
};
