#include <iostream>
#include <vector>
#include <string>
using namespace std;


class ShowSeat {
private:
    int showId;
    vector<Seat> seats;

public:

    ShowSeat() {
        showId = 0;
    }

    ShowSeat(int id) {
        showId = id;
    }

    void addSeat(Seat seat) {
        seats.push_back(seat);
    }

    int getShowId() {
        return showId;
    }

    void displaySeats() {

        cout << "=============SEAT LAYOUT==============" << endl;

        for (int i = 0; i < seats.size(); i++) {

            cout << seats[i].getSeatNumber()
                 << " - "
                 << seats[i].getSeatTypeName()
                 << " - "
                 << seats[i].getStatusName()
                 << endl;
        }
    }

    Seat* findSeat(string seatNumber) {

        for (int i = 0; i < seats.size(); i++) {

            if (seats[i].getSeatNumber() == seatNumber) {
                return &seats[i];
            }
        }

        return nullptr;
    }

    bool bookSeat(string seatNumber) {

        Seat* seat = findSeat(seatNumber);

        if (seat == nullptr) {
            cout << "Seat not found." << endl;
            return false;
        }

        if (seat->getStatus() == booked) {
            cout << "Seat " << seatNumber
                 << " is already booked." << endl;
            return false;
        }

        seat->setStatus(booked);

        cout << "Seat " << seatNumber
             << " booked successfully." << endl;

        return true;
    }

    bool cancelSeat(string seatNumber) {

        Seat* seat = findSeat(seatNumber);

        if (seat == nullptr) {
            cout << "Seat not found." << endl;
            return false;
        }

        if (seat->getStatus() == available) {
            cout << "Seat " << seatNumber
                 << " is already available." << endl;
            return false;
        }

        seat->setStatus(available);

        cout << "Seat " << seatNumber
             << " is available again." << endl;

        return true;
    }
};


// int main() {

//     ShowSeat showSeats(101);

//     Seat s1("A1", silver);
//     Seat s2("A2", silver);
//     Seat s3("B1", gold);
//     Seat s4("B2", gold);
//     Seat s5("C1", platinum);

//     showSeats.addSeat(s1);
//     showSeats.addSeat(s2);
//     showSeats.addSeat(s3);
//     showSeats.addSeat(s4);
//     showSeats.addSeat(s5);

//     cout << "Initial Seat Layout:" << endl;
//     showSeats.displaySeats();

//     cout << endl;

//     showSeats.bookSeat("A1");

//     cout << endl;

//     showSeats.bookSeat("A1");

//     cout << endl;

//     cout << "After Booking:" << endl;
//     showSeats.displaySeats();

//     cout << endl;

//     showSeats.cancelSeat("A1");

//     cout << endl;

//     cout << "After Cancellation:" << endl;
//     showSeats.displaySeats();

//     return 0;
// }