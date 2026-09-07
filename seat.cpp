#include<iostream>
#include<string>
using namespace std;

enum SeatTypes{
    silver,
    gold,
    platinum
};

enum SeatStatus
{
    available,
    booked
};

class Seat
{
    private:
        string seatNumber;
        SeatTypes seat_type;
        SeatStatus status;
        
    public:
        Seat(){
            seatNumber = "";
            seat_type = silver;
            status = available;
        }

        Seat(string num, SeatTypes type){
            seatNumber = num;
            seat_type = type;
            status = available;
        }

        string getSeatNumber()
        {
            return seatNumber;
        }

        SeatTypes getSeatType()
        {
            return seat_type;
        }

        SeatStatus getStatus()
        {
            return status;
        }

        void setStatus(SeatStatus newStatus)
        {
            status = newStatus;
        }

        string getSeatTypeName()
        {
            if (seat_type == silver)
                return "SILVER";

            if (seat_type == gold)
                return "GOLD";

            return "PLATINUM";
        }

        string getStatusName(){
            if(status == available)  return "available";
            else return "booked";
        }

        void displaySeats(){
            cout<<"Seat Number: "<<seatNumber<<endl;
            cout<<"Seat Type: "<<getSeatTypeName()<<endl;
            cout<<"Status: "<<getStatusName()<<endl;
        }
};

// int main()
// {
//             Seat s1("A1", silver);
//             Seat s2("B1", gold);
//             Seat s3("C1", platinum);

//             s1.displaySeats();

//             cout << endl;

//             s2.displaySeats();

//             cout << endl;

//             s3.displaySeats();

//             cout << endl;

//             cout << "Booking A1..." << endl;

//             s1.setStatus(booked);

//             s1.displaySeats();

//             cout << endl;

//             cout << "Cancelling A1..." << endl;

//             s1.setStatus(available);

//             s1.displaySeats();

//             return 0;
//         }


