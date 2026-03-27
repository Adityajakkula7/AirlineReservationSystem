#include "Booking.h"
#include <iostream>

Booking::Booking(string bookingId, Passenger passenger, Flight flight, Seat seat)
    : bookingId(bookingId), passenger(passenger), flight(flight), seat(seat),
      status(BookingStatus::CONFIRMED), totalAmount(seat.getPrice())
{
}

string Booking::getBookingId() const { return bookingId; }
BookingStatus Booking::getStatus() const { return status; }
double Booking::getTotalAmount() const { return totalAmount; }

string Booking::getStatusAsString() const
{
    if (status == BookingStatus::CONFIRMED)
        return "Confirmed";
    if (status == BookingStatus::CANCELLED)
        return "Cancelled";
    return "Pending";
}

bool Booking::cancel()
{
    if (status == BookingStatus::CONFIRMED)
    {
        status = BookingStatus::CANCELLED;
        notifyObservers("BOOKING CANCELLED",
                        "Booking " + bookingId + " for flight " +
                            flight.getFlightNumber() + " has been cancelled.");
        return true;
    }
    return false;
}

void Booking::printSummary() const
{
    cout << "---- Booking Summary ----" << endl;
    cout << "Booking ID : " << bookingId << endl;
    cout << "Passenger  : " << passenger.getName() << endl;
    cout << "Flight     : " << flight.getFlightNumber() << endl;
    cout << "From       : " << flight.getOrigin().getCity() << endl;
    cout << "To         : " << flight.getDestination().getCity() << endl;
    cout << "Seat       : " << seat.getSeatNumber() << " (" << seat.getTypeAsString() << ")" << endl;
    cout << "Amount     : Rs." << totalAmount << endl;
    cout << "Status     : " << getStatusAsString() << endl;
    cout << "-------------------------" << endl;
}