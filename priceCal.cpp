#include <iostream>
#include <vector>

// #include "seat.cpp"
using namespace std;

class PriceCal {
public:
    double getSeatPrice(SeatTypes type) {

        if (type == silver) {
            return 150;
        }

        if (type == gold) {
            return 250;
        }

        if (type == platinum) {
            return 400;
        }

        return 0;
    }

    double calculateTotal(vector<Seat> seats) {
        double total = 0;
        for (int i = 0; i < seats.size(); i++) {
            total = total + getSeatPrice(seats[i].getSeatType());
        }
        return total;
    }
};

// int main() {
//     PriceCal calculator;

//     Seat s1("A1", silver);
//     Seat s2("B1", gold);
//     Seat s3("C1", platinum);

//     cout << "SILVER PRICE   : Rs. "
//          << calculator.getSeatPrice(s1.getSeatType()) << endl;

//     cout << "GOLD PRICE     : Rs. "
//          << calculator.getSeatPrice(s2.getSeatType()) << endl;

//     cout << "PLATINUM PRICE : Rs. "
//          << calculator.getSeatPrice(s3.getSeatType()) << endl;

//     vector<Seat> selectedSeats;

//     selectedSeats.push_back(s1);
//     selectedSeats.push_back(s2);
//     selectedSeats.push_back(s3);

//     double total = calculator.calculateTotal(selectedSeats);

//     cout << endl;
//     cout << "Total Amount   : Rs. " << total << endl;

//     return 0;
// }