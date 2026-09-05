#include<iostream>
#include<string>
#include<vector>

#include"booking.cpp"
using namespace std;

class BookingService{
    private:
        vector<Booking> bookings;
        int nextBookingId;

    public:
        BookingService(){
            nextBookingId = 100;
        }

        Booking createBooking(
            string customerName, string movieTitle, string screenName, string showTime, double amount
        ){
            Booking newBooking(nextBookingId, customerName, movieTitle, screenName, showTime, amount );

            nextBookingId++;
            bookings.push_back(newBooking);
            return newBooking;
        }
        //finding existing bookingid
        Booking *findBooking(int bookingId){
            for(int i=0; i<bookings.size(); i++){
                if(bookings[i].getBookingId() == bookingId)
                    return &bookings[i];
            }
            return nullptr;
        }

        void displayBooking(int bookingId){
            Booking *booking = findBooking(bookingId);
            if(booking == nullptr){
                cout<<"Booking does not exist!"<<endl;
                return;
            }

            booking->displayBooking();
        }

        bool addSeatToBooking(int bookingId, string seatNumber){
            Booking *booking = findBooking(bookingId);

            if(booking == nullptr){
                cout<<"Booking does not exist!"<<endl;
                return false;
            }

            booking->addSeats(seatNumber);
            return true;
        }

        bool confirmBooking(int bookingId){
            Booking *booking = findBooking(bookingId);
            if(booking == nullptr){
                cout<<"Booking does not exist!"<<endl;
                return false;
            }

            booking->setStatus("Confirmed");
            return true;
        }

        bool cancelBooking(int bookingId){
            Booking *booking = findBooking(bookingId);
            if(booking == nullptr){
                cout<<"Booking does not exist!"<<endl;
                return false;
            }
            
            if(booking->getStatus() == "Cancelled"){
                cout<<"Booking is already cancelled."<<endl;
                return false;
            }

            booking->setStatus("Cancelled");
            cout<<"Booking Cancelled!"<<endl;
            return true;
        }

        void displayAllBooking(){
            if(bookings.empty()){
                cout<<"No bookings found!"<<endl;
                return;
            }

            for(int i=0; i<bookings.size();i++){
                bookings[i].displayBooking();
                cout<<endl;
            }
        }
};


int main()
{
    BookingService service;

    Booking b1 = service.createBooking(
        "Sabila",
        "Avengers",
        "Screen 2",
        "6:30 PM",
        800
    );

    service.addSeatToBooking(b1.getBookingId(), "A1");
    service.addSeatToBooking(b1.getBookingId(), "A2");
    service.addSeatToBooking(b1.getBookingId(), "B3");

    cout << "Booking created successfully!" << endl;

    cout << endl;

    service.displayBooking(b1.getBookingId());

    cout << endl;

    service.confirmBooking(b1.getBookingId());

    cout << "After confirmation:" << endl;

    service.displayBooking(b1.getBookingId());

    cout << endl;

    service.cancelBooking(b1.getBookingId());

    cout << endl;

    cout << "After cancellation:" << endl;

    service.displayBooking(b1.getBookingId());

    return 0;
}