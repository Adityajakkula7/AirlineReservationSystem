## Architecture Overview

### Class Relationships
- **Booking** is the central class — it contains Flight, Seat, Passenger
- **FlightManager** and **BookingManager** are Singletons — one instance each
- **Booking** extends **ISubject** — notifies observers on state changes
- **PaymentStrategy** is abstract — UPI, CreditCard, NetBanking implement it
- **BookingState** is abstract — Pending, Confirmed, Cancelled implement it

### State Flow
```
Pending → confirm() → Confirmed → cancel() → Cancelled
```

### Design Patterns
- **Singleton**: FlightManager, BookingManager
- **Strategy**: PaymentStrategy → UPI / CreditCard / NetBanking  
- **Observer**: ISubject + IObserver → Email / SMS notifications
- **State**: BookingContext + BookingState → Pending / Confirmed / Cancelled