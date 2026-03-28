#include <iostream>
#include <vector>
#include <string>
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

// ── helpers ──────────────────────────────────────────────
void printLine()
{
    cout << "----------------------------------------" << endl;
}

void printMenu()
{
    printLine();
    cout << "   AIRLINE RESERVATION SYSTEM" << endl;
    printLine();
    cout << "  1. View all flights" << endl;
    cout << "  2. Search flights" << endl;
    cout << "  3. Book a seat" << endl;
    cout << "  4. View all bookings" << endl;
    cout << "  5. Cancel a booking" << endl;
    cout << "  6. Exit" << endl;
    printLine();
    cout << "  Enter choice: ";
}

// ── setup sample data ─────────────────────────────────────
void setupData(FlightManager &fm)
{
    Airport bom("BOM", "Chhatrapati Shivaji", "Mumbai");
    Airport del("DEL", "Indira Gandhi", "Delhi");
    Airport blr("BLR", "Kempegowda", "Bangalore");
    Airport hyd("HYD", "Rajiv Gandhi", "Hyderabad");

    fm.addFlight(Flight("AI101", bom, del, 5));
    fm.addFlight(Flight("6E202", bom, del, 3));
    fm.addFlight(Flight("SG303", bom, blr, 4));
    fm.addFlight(Flight("AI404", del, hyd, 6));
    fm.addFlight(Flight("6E505", blr, hyd, 2));
}

// ── option handlers ───────────────────────────────────────
void viewAllFlights(FlightManager &fm)
{
    printLine();
    fm.listAllFlights();
}

void searchFlights(FlightManager &fm)
{
    string origin, dest;
    cout << "  Enter origin code (e.g. BOM): ";
    cin >> origin;
    cout << "  Enter destination code (e.g. DEL): ";
    cin >> dest;
    printLine();

    vector<Flight> results = fm.searchFlights(origin, dest);
    if (results.empty())
    {
        cout << "  No flights found for " << origin << " -> " << dest << endl;
    }
    else
    {
        cout << "  Flights found:" << endl;
        for (Flight &f : results)
        {
            cout << "  " << f.getFlightNumber()
                 << " | " << f.getOrigin().getCity()
                 << " -> " << f.getDestination().getCity()
                 << " | Available seats: " << f.getAvailableSeats()
                 << endl;
        }
    }
}

void bookSeat(BookingManager &bm, FlightManager &fm)
{
    // Passenger details
    string name, email, phone;
    cout << "  Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "  Enter email: ";
    cin >> email;
    cout << "  Enter phone: ";
    cin >> phone;

    // Flight selection
    string flightNum;
    cout << "  Enter flight number to book (e.g. AI101): ";
    cin >> flightNum;

    vector<Flight> all = fm.searchFlights("", "");
    Flight *chosen = nullptr;
    vector<Flight> &flights = fm.getFlights();
    for (Flight &f : flights)
    {
        if (f.getFlightNumber() == flightNum)
        {
            chosen = &f;
            break;
        }
    }

    if (chosen == nullptr)
    {
        cout << "  Flight not found!" << endl;
        return;
    }

    if (chosen->getAvailableSeats() == 0)
    {
        cout << "  Sorry, no seats available on this flight!" << endl;
        return;
    }

    // Seat type
    int seatChoice;
    cout << "  Select seat type:" << endl;
    cout << "    1. Economy    - Rs.3000" << endl;
    cout << "    2. Business   - Rs.8000" << endl;
    cout << "    3. First Class- Rs.15000" << endl;
    cout << "  Choice: ";
    cin >> seatChoice;

    SeatType type;
    double price;
    string seatNum;
    if (seatChoice == 1)
    {
        type = SeatType::ECONOMY;
        price = 3000;
        seatNum = "E" + to_string(rand() % 50 + 1);
    }
    else if (seatChoice == 2)
    {
        type = SeatType::BUSINESS;
        price = 8000;
        seatNum = "B" + to_string(rand() % 20 + 1);
    }
    else
    {
        type = SeatType::FIRST_CLASS;
        price = 15000;
        seatNum = "F" + to_string(rand() % 10 + 1);
    }

    // Payment
    int payChoice;
    cout << "  Select payment method:" << endl;
    cout << "    1. UPI" << endl;
    cout << "    2. Credit Card" << endl;
    cout << "    3. Net Banking" << endl;
    cout << "  Choice: ";
    cin >> payChoice;

    PaymentStrategy *payment = nullptr;
    if (payChoice == 1)
    {
        string upiId;
        cout << "  Enter UPI ID: ";
        cin >> upiId;
        payment = new UPIPayment(upiId);
    }
    else if (payChoice == 2)
    {
        string card, holder;
        cout << "  Enter card number: ";
        cin >> card;
        cout << "  Enter card holder name: ";
        cin.ignore();
        getline(cin, holder);
        payment = new CreditCardPayment(card, holder);
    }
    else
    {
        string bank, acc;
        cout << "  Enter bank name: ";
        cin >> bank;
        cout << "  Enter account number: ";
        cin >> acc;
        payment = new NetBankingPayment(bank, acc);
    }

    // Create passenger, seat, booking
    static int passengerCount = 1;
    string pid = "P" + to_string(passengerCount++);
    Passenger p(pid, name, email, phone);
    Seat s(seatNum, type, price);

    printLine();
    payment->pay(price);
    delete payment;

    Booking b = bm.createBooking(p, *chosen, s);

    // Attach notifications
    EmailNotification *emailNotif = new EmailNotification(email);
    SMSNotification *smsNotif = new SMSNotification(phone);
    Booking *storedBooking = bm.getBooking(b.getBookingId());
    if (storedBooking)
    {
        storedBooking->addObserver(emailNotif);
        storedBooking->addObserver(smsNotif);
    }

    chosen->bookSeat();

    printLine();
    b.printSummary();
}

void viewBookings(BookingManager &bm)
{
    printLine();
    bm.listAllBookings();
}

void cancelBooking(BookingManager &bm)
{
    string bookingId;
    cout << "  Enter Booking ID to cancel (e.g. BK001): ";
    cin >> bookingId;
    printLine();

    if (bm.cancelBooking(bookingId))
    {
        cout << "  Booking " << bookingId << " cancelled successfully!" << endl;
    }
    else
    {
        cout << "  Could not cancel. Booking not found or already cancelled." << endl;
    }
}

// ── main ──────────────────────────────────────────────────
int main()
{
    FlightManager &fm = FlightManager::getInstance();
    BookingManager &bm = BookingManager::getInstance();
    setupData(fm);

    int choice;
    do
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewAllFlights(fm);
            break;
        case 2:
            searchFlights(fm);
            break;
        case 3:
            bookSeat(bm, fm);
            break;
        case 4:
            viewBookings(bm);
            break;
        case 5:
            cancelBooking(bm);
            break;
        case 6:
            cout << "  Goodbye!" << endl;
            break;
        default:
            cout << "  Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}