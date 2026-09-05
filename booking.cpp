#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Booking{
    private:
        int bookingId;
        string customerName;
        string movieTitle;
        string screenName;
        string showTime;
        vector<string> seatNumbers;
        double totalBalance;
        string status;

    public:
        Booking()
        {
            bookingId = 0;
            customerName = "";
            movieTitle = "";
            screenName = "";
            showTime = "";
            totalBalance = 0;
            status = "PENDING"; //pending until payment is not successfull.
        }

        Booking(int id, string Cus_name, string title, string sc_name, string time, double amt){
            bookingId = id;
            customerName = Cus_name;
            movieTitle = title;
            screenName = sc_name;
            showTime = time;
            totalBalance = amt;
            status = "PENDING";
        }

        void addSeats(string seatNum){
            seatNumbers.push_back(seatNum);
        }

        int getBookingId(){
            return bookingId;
        }

        string getCustomerName(){
            return customerName;
        }

        string getMovieTitle()
        {
            return movieTitle;
        }

        string getScreenName(){
            return screenName;
        }

        string getShowTime(){
            return showTime;
        }

        double getAmount(){
            return totalBalance;
        }

        vector<string> getSeatNumbers(){
            return seatNumbers;
        }

        string getStatus(){
            return status;
        }

        void setTotalAmt(double amt){
            totalBalance = amt;
        }

        void setStatus(string newStatus){
            status = newStatus;
        }

        void displayBooking(){
            cout<<"----------BOOKING DETAILS----------"<<endl;
            cout<<endl;
            cout<<"Booking ID: "<<bookingId<<endl;
            cout<<"Customer Name :"<<customerName<<endl;
            cout<<"Movie: "<< movieTitle<<endl;
            cout<<"Screen: "<<screenName<<endl;
            cout<<"Time: "<<showTime<<endl;
            cout<<"Seats: ";
            for(string s : seatNumbers){
                cout<<s<<" ";
            }

            cout<<endl;
            cout<<"Total Amount: Rs. "<<totalBalance<<endl;
            cout<<"Status: "<<status<<endl;
            cout<<"-------------------------------------"<<endl;
        }
};


// int main()
// {
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

//     booking.displayBooking();

//     cout << endl;

//     cout << "Booking ID: "
//          << booking.getBookingId() << endl;

//     cout << "Movie: "
//          << booking.getMovieTitle() << endl;

//     cout << "Total Amount: Rs. "
//          << booking.getAmount() << endl;

//     return 0;
// }