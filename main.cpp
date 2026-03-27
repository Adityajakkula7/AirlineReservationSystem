#include <iostream>
#include <vector>
#include "include/Airport.h"
#include "include/Flight.h"
#include "include/Seat.h"
#include "include/Passenger.h"
#include "include/Booking.h"
#include "include/FlightManager.h"
#include "include/BookingManager.h"
#include "include/UPIPayment.h"
#include "include/CreditCardPayment.h"
#include "include/NetBankingPayment.h"
#include "include/EmailNotification.h"
#include "include/SMSNotification.h"
#include "include/BookingContext.h"
using namespace std;

void printDivider(string title)
{
    cout << "\n========== " << title << " ==========" << endl;
}

int main()
{

    // ─── STEP 1: Setup Airports ───────────────────────────
    printDivider("SETTING UP AIRPORTS");
    Airport bom("BOM", "Chhatrapati Shivaji", "Mumbai");
    Airport del("DEL", "Indira Gandhi", "Delhi");
    Airport blr("BLR", "Kempegowda", "Bangalore");
    cout << "Airports created: BOM, DEL, BLR" << endl;

    // ─── STEP 2: Setup Flights ────────────────────────────
    printDivider("SETTING UP FLIGHTS");
    Flight f1("AI101", bom, del, 3); // only 3 seats for demo
    Flight f2("6E202", bom, del, 2);
    Flight f3("SG303", bom, blr, 5);

    FlightManager &fm = FlightManager::getInstance();
    fm.addFlight(f1);
    fm.addFlight(f2);
    fm.addFlight(f3);
    fm.listAllFlights();

    // ─── STEP 3: Search Flights ───────────────────────────
    printDivider("SEARCHING FLIGHTS: Mumbai -> Delhi");
    vector<Flight> results = fm.searchFlights("BOM", "DEL");
    if (results.empty())
    {
        cout << "No flights found!" << endl;
    }
    else
    {
        for (Flight &f : results)
        {
            cout << "Found: " << f.getFlightNumber()
                 << " | Seats available: " << f.getAvailableSeats()
                 << endl;
        }
    }

    // ─── STEP 4: Create Passengers ────────────────────────
    printDivider("PASSENGERS");
    Passenger p1("P001", "Akshath", "akshath@gmail.com", "9999999999");
    Passenger p2("P002", "Rahul", "rahul@gmail.com", "8888888888");
    cout << "Passengers created: " << p1.getName() << ", " << p2.getName() << endl;

    // ─── STEP 5: Setup Seats ──────────────────────────────
    printDivider("SEATS");
    Seat s1("1A", SeatType::FIRST_CLASS, 15000);
    Seat s2("25C", SeatType::ECONOMY, 3000);
    Seat s3("10B", SeatType::BUSINESS, 8000);
    cout << "Seats created: 1A (First Class), 25C (Economy), 10B (Business)" << endl;

    // ─── STEP 6: Create Bookings ──────────────────────────
    printDivider("CREATING BOOKINGS");
    BookingManager &bm = BookingManager::getInstance();

    bm.createBooking(p1, f1, s1);
    bm.createBooking(p2, f1, s2);

    // Get actual bookings from map — not copies!
    Booking *b1 = bm.getBooking("BK001");
    Booking *b2 = bm.getBooking("BK002");

    b1->printSummary();
    b2->printSummary();

    // ─── STEP 7: Attach Notifications ────────────────────
    printDivider("ATTACHING NOTIFICATIONS");
    EmailNotification email1("akshath@gmail.com");
    SMSNotification sms1("9999999999");
    b1->addObserver(&email1);
    b1->addObserver(&sms1);

    EmailNotification email2("rahul@gmail.com");
    SMSNotification sms2("8888888888");
    b2->addObserver(&email2);
    b2->addObserver(&sms2);
    cout << "Notifications attached for both passengers!" << endl;

    // ─── STEP 8: Process Payments ─────────────────────────
    printDivider("PROCESSING PAYMENTS");

    PaymentStrategy *pay1 = new UPIPayment("akshath@upi");
    pay1->pay(b1->getTotalAmount());
    delete pay1;

    PaymentStrategy *pay2 = new CreditCardPayment("1234-5678-9012", "Rahul");
    pay2->pay(b2->getTotalAmount());
    delete pay2;

    // ─── STEP 9: State Machine Demo ───────────────────────
    printDivider("BOOKING STATE MACHINE");

    BookingContext stateDemo;
    cout << "State: " << stateDemo.getStateName() << endl;

    stateDemo.confirm();
    cout << "State: " << stateDemo.getStateName() << endl;

    stateDemo.cancel();
    cout << "State: " << stateDemo.getStateName() << endl;

    stateDemo.cancel(); // should fail gracefully

    // ─── STEP 10: Cancel a Real Booking ───────────────────
    printDivider("CANCELLING BOOKING BK001");
    bm.cancelBooking("BK001"); // observers will fire!

    // ─── STEP 11: Final Booking List ──────────────────────
    printDivider("FINAL BOOKING STATUS");
    bm.listAllBookings();

    return 0;
}