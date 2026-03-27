#pragma once
#include <string>
#include <algorithm>
#include "Passenger.h"
#include "Flight.h"
#include "Seat.h"
#include "ISubject.h"
using namespace std;

enum class BookingStatus
{
    CONFIRMED,
    CANCELLED,
    PENDING
};

class Booking : public ISubject
{
private:
    string bookingId;
    Passenger passenger;
    Flight flight;
    Seat seat;
    BookingStatus status;
    double totalAmount;

public:
    Booking() : status(BookingStatus::PENDING), totalAmount(0) {}
    Booking(string bookingId, Passenger passenger, Flight flight, Seat seat);

    string getBookingId() const;
    BookingStatus getStatus() const;
    double getTotalAmount() const;
    string getStatusAsString() const;
    bool cancel();
    void printSummary() const;
};