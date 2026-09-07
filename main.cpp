#include <iostream>
#include <string>
#include <vector>

#include "paymentTypes.cpp"
#include "movie.cpp"
#include "screen.cpp"
#include "seat.cpp"
#include "show.cpp"
#include "customer.cpp"
#include "booking.cpp"

#include "showseat.cpp"
#include "priceCal.cpp"
#include "cinema.cpp"
#include "payment.cpp"
#include "bookingservice.cpp"
#include "ticketprinter.cpp"

using namespace std;

int main() {

    //        CINEMA SETUP
    

    Cinema cinema("PVR Cinema");

    Movie m1(101, "Avengers", "Action", 180, true);
    Movie m2(102, "Inception", "Sci-Fi", 148, true);
    Movie m3(103, "Frozen", "Animation", 102, false);

    cinema.addMovie(m1);
    cinema.addMovie(m2);
    cinema.addMovie(m3);

    Screen s1(1, "Screen 1", 50);
    Screen s2(2, "Screen 2", 80);

    cinema.addScreen(s1);
    cinema.addScreen(s2);


    //           SHOWS

    Show show1(101, "Avengers", "Screen 1", "3:00 PM");
    Show show2(102, "Avengers", "Screen 2", "6:30 PM");
    Show show3(103, "Inception", "Screen 1", "9:30 PM");


    //        SEAT SETUP
 

    ShowSeat showSeat(102);

    showSeat.addSeat(Seat("A1", silver));
    showSeat.addSeat(Seat("A2", silver));
    showSeat.addSeat(Seat("A3", silver));

    showSeat.addSeat(Seat("B1", gold));
    showSeat.addSeat(Seat("B2", gold));
    showSeat.addSeat(Seat("B3", gold));

    showSeat.addSeat(Seat("C1", platinum));
    showSeat.addSeat(Seat("C2", platinum));


    //        BOOKING SERVICE

    BookingService bookingService;

    PriceCal priceCalculator;


    int choice;

    do {

        cout << endl;
        cout << "===================MOVIE TICKET BOOKING SYSTEM=====================" << endl;
        

        cout << "1. View Movies" << endl;
        cout << "2. View Screens" << endl;
        cout << "3. View Shows" << endl;
        cout << "4. View Seats" << endl;
        cout << "5. Book Ticket" << endl;
        cout << "6. View Booking" << endl;
        cout << "7. Cancel Booking" << endl;
        cout << "8. Exit" << endl;

        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        //        VIEW MOVIES
    
        if (choice == 1) {

            cout << endl;
            cinema.displayMovies();
        }

        //        VIEW SCREENS

        else if (choice == 2) {

            cout << endl;
            cinema.displayScreens();
        }

        //          VIEW SHOWS

        else if (choice == 3) {

            cout << endl;
            cout << "============= AVAILABLE SHOWS =============" << endl;

            show1.displayShow();

            cout << endl;

            show2.displayShow();

            cout << endl;

            show3.displayShow();
        }

        //          VIEW SEATS

        else if (choice == 4) {

            cout << endl;

            showSeat.displaySeats();
        }

        //          BOOK TICKET

        else if (choice == 5) {

            string customerName;
            string phone;
            string email;

            cout << endl;
            cout << "============= BOOK TICKET =============" << endl;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, customerName);

            cout << "Enter Phone Number: ";
            getline(cin, phone);

            cout << "Enter Email: ";
            getline(cin, email);


            // Customer object
            Customer customer(
                1,
                customerName,
                phone,
                email
            );


            cout << endl;

            cout << "Available Shows:" << endl;

            show1.displayShow();

            cout << endl;

            show2.displayShow();

            cout << endl;

            show3.displayShow();


            int showChoice;

            cout << endl;
            cout << "Select Show (1-3): ";
            cin >> showChoice;


            Show* selectedShow = nullptr;

            if (showChoice == 1) {
                selectedShow = &show1;
            }
            else if (showChoice == 2) {
                selectedShow = &show2;
            }
            else if (showChoice == 3) {
                selectedShow = &show3;
            }
            else {
                cout << "Invalid show selection!" << endl;
                continue;
            }

            // Display seats

            cout << endl;
            showSeat.displaySeats();


            int numberOfSeats;

            cout << endl;
            cout << "How many seats do you want to book? ";
            cin >> numberOfSeats;


            vector<Seat> selectedSeats;
            vector<string> selectedSeatNumbers;

            bool bookingFailed = false;


            for (int i = 0; i < numberOfSeats; i++) {

                string seatNumber;

                cout << "Enter seat " << i + 1 << ": ";
                cin >> seatNumber;


                Seat* seat = showSeat.findSeat(seatNumber);


                if (seat == nullptr) {

                    cout << "Seat does not exist!" << endl;

                    bookingFailed = true;
                    break;
                }


                if (seat->getStatus() == booked) {

                    cout << "Seat already booked!" << endl;

                    bookingFailed = true;
                    break;
                }


                selectedSeats.push_back(*seat);
                selectedSeatNumbers.push_back(seatNumber);
            }


            if (bookingFailed) {

                cout << "Booking cancelled." << endl;
                continue;
            }


            // Calculate price

            double totalAmount =
                priceCalculator.calculateTotal(selectedSeats);


            cout << endl;
            cout << "================================" << endl;
            cout << "Total Amount: Rs. "
                 << totalAmount << endl;
            cout << "================================" << endl;


            // Create booking
            Booking booking =
                bookingService.createBooking(
                    customer.getCustomerName(),
                    selectedShow->getMovieTitle(),
                    selectedShow->getScreenName(),
                    selectedShow->getStartTime(),
                    totalAmount
                );


            // Book seats
            for (string seatNumber : selectedSeatNumbers) {

                showSeat.bookSeat(seatNumber);

                bookingService.addSeatToBooking(
                    booking.getBookingId(),
                    seatNumber
                );
            }

            //          PAYMENT

            cout << endl;
            cout << "Select Payment Method:" << endl;
            cout << "1. UPI" << endl;
            cout << "2. Card" << endl;
            cout << "3. Cash" << endl;

            int paymentChoice;

            cout << "Enter choice: ";
            cin >> paymentChoice;

            bool paymentSuccessful = false;

            if (paymentChoice == 1) {
                PaymentType* payment = nullptr;
                paymentSuccessful = payment->pay(totalAmount);
                delete payment;
            }
            else if (paymentChoice == 2) {
                PaymentType* payment = new Card();
                paymentSuccessful = payment->pay(totalAmount);
                delete payment;
            }
            else if (paymentChoice == 3) {
                PaymentType* payment = new Cash();
                paymentSuccessful = payment->pay(totalAmount);
                delete payment;
            }
            else {
                cout << "Invalid payment method!" << endl;
                continue;
}
            //       CONFIRM BOOKING
            if (paymentSuccessful) {

                bookingService.confirmBooking(
                    booking.getBookingId()
                );


                cout << endl;
                cout << "Booking Confirmed!" << endl;


                // Get updated booking
                Booking* finalBooking =
                    bookingService.findBooking(
                        booking.getBookingId()
                    );

                //          PRINT TICKET

                if (finalBooking != nullptr) {

                    TicketPrinter printer;

                    printer.printTicket(*finalBooking);
                }
            }
            else {

                cout << "Payment failed!" << endl;
            }
        }


        //        VIEW BOOKING

        else if (choice == 6) {

            int bookingId;

            cout << endl;
            cout << "Enter Booking ID: ";
            cin >> bookingId;

            bookingService.displayBooking(bookingId);
        }


        //       CANCEL BOOKING

        else if (choice == 7) {

            int bookingId;

            cout << endl;
            cout << "Enter Booking ID: ";
            cin >> bookingId;

            bookingService.cancelBooking(bookingId);
        }


        //            EXIT

        else if (choice == 8) {

            cout << endl;
            cout << "Thank you for using Movie Ticket Booking System!"<< endl;
        }


        else {

            cout << endl;
            cout << "Invalid choice! Please try again."<< endl;
        }


    } while (choice != 8);

    return 0;
}