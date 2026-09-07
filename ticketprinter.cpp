#include <iostream>
#include <string>
#include <vector>

// #include "booking.cpp"
using namespace std;

class TicketPrinter {
public:

    void printTicket(Booking booking) {

        cout << endl;
        cout << "====================================" << endl;
        cout << "            MOVIE TICKET            " << endl;
        cout << "====================================" << endl;

        cout << "Booking ID : " << booking.getBookingId() << endl;
        cout << "Movie      : " << booking.getMovieTitle() << endl;
        cout << "Screen     : " << booking.getScreenName() << endl;
        cout << "Time       : " << booking.getShowTime() << endl;

        cout << "Seats      : ";

        vector<string> seats = booking.getSeatNumbers();

        for (int i = 0; i < seats.size(); i++) {
            cout << seats[i];

            if (i < seats.size() - 1) {
                cout << ", ";
            }
        }

        cout << endl;

        cout << "Total      : Rs. "
             << booking.getAmount() << endl;

        cout << "Status     : "
             << booking.getStatus() << endl;

        cout << "====================================" << endl;
        cout << "          ENJOY YOUR MOVIE!         " << endl;
        cout << "====================================" << endl;
    }
};


// int main() {

//     Booking booking(
//         1001,
//         "Sabila",
//         "Avengers",
//         "Screen 2",
//         "6:30 PM",
//         800
//     );

//     booking.addSeats("A1");
//     booking.addSeats("A2");
//     booking.addSeats("B3");

//     booking.setStatus("CONFIRMED");

//     TicketPrinter printer;

//     printer.printTicket(booking);

//     return 0;
// }