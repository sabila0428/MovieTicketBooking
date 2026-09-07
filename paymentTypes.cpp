#include <iostream>
#include <string>
using namespace std;

class PaymentType {         //base class
public:
    virtual string getName() {   //virtual func
        return "Unknown";
    }

    virtual bool pay(double amount) {
        return false;
    }
};

class UPI : public PaymentType {    //inheritance
public:
    string getName() override {
        return "UPI";
    }

    bool pay(double amount) override {
        cout << "Paying Rs. " << amount << " using UPI..." << endl;
        cout << "UPI payment successful!" << endl;

        return true;
    }
};

class Card : public PaymentType {    //inheritance
public:
    string getName() override {
        return "CARD";
    }

    bool pay(double amount) override {
        cout << "Paying Rs. " << amount << " using Card..." << endl;
        cout << "Card payment successful!" << endl;
        return true;
    }
};

class Cash : public PaymentType {    //inheritance
public:
    string getName() override {
        return "CASH";
    }

    bool pay(double amount) override {
        cout << "Paying Rs. " << amount << " using Cash..." << endl;
        cout << "Cash payment successful!" << endl;
        return true;
    }
};


// int main() {

//     UPI upi;
//     Card card;
//     Cash cash;

//     cout << "----- UPI -----" << endl;
//     upi.pay(800);

//     cout << endl;

//     cout << "----- CARD -----" << endl;
//     card.pay(800);

//     cout << endl;

//     cout << "----- CASH -----" << endl;
//     cash.pay(800);

//     return 0;
// }