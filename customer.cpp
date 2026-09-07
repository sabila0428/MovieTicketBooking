#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    int customerId;
    string customerName;
    string phoneNumber;
    string email;

public:
    Customer() {
        customerId = 0;
        customerName = "";
        phoneNumber = "";
        email = "";
    }

    Customer(int id, string name, string phone, string mail) {
        customerId = id;
        customerName = name;
        phoneNumber = phone;
        email = mail;
    }

    int getCustomerId() {
        return customerId;
    }

    string getCustomerName() {
        return customerName;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    string getEmail() {
        return email;
    }

    void displayCustomer() {
        cout << "=============CUSTOMER DETAILS==============" << endl;
        cout << "Customer ID : " << customerId << endl;
        cout << "Name        : " << customerName << endl;
        cout << "Phone       : " << phoneNumber << endl;
        cout << "Email       : " << email << endl;
    }
};


// int main() {

//     Customer c1(
//         1,
//         "Sabila",
//         "9876543210",
//         "sabila@gmail.com"
//     );

//     c1.displayCustomer();

//     return 0;
// }