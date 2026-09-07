#include <iostream>
#include <string>
using namespace std;

enum PaymentMethod {
    UPI,
    CARD,
    CASH
};

class Payment {
private:
    double amount;
    PaymentMethod method;
    bool paymentSuccessful;

public:
    Payment() {
        amount = 0;
        method = CASH;
        paymentSuccessful = false;
    }

    Payment(double amt, PaymentMethod m) {
        amount = amt;
        method = m;
        paymentSuccessful = false;
    }

    string getPaymentMethodName() {
        if (method == UPI)
            return "UPI";

        if (method == CARD)
            return "CARD";

        return "CASH";
    }

    double getAmount() {
        return amount;
    }

    bool isPaymentSuccessful() {
        return paymentSuccessful;
    }

    bool processPayment() {
        cout << "Payment Method : "
             << getPaymentMethodName() << endl;
        cout << "Amount         : Rs. "
             << amount << endl;
        paymentSuccessful = true;

        cout << "Payment successful!" << endl;

        return true;
    }
};


// int main() {

//     Payment p1(800, UPI);

//     p1.processPayment();

//     cout << endl;

//     cout << "Payment Status: ";

//     if (p1.isPaymentSuccessful())
//         cout << "SUCCESS";
//     else
//         cout << "FAILED";

//     return 0;
// }