#include<iostream>
#include<string>
using namespace std;

class Screen{
    private:
        int screenId;
        int totalSeats;
        string screenName;

    public:
        Screen(){
            screenId = 0;
            totalSeats = 0;
            screenName ="";
        }

        Screen(int id, string name, int seats){
            screenId= id;
            totalSeats = seats;
            screenName = name;
        }

        int getScreenId(){
            return screenId;
        }

        int getTotalSeats(){
            return totalSeats;
        }

        string getScreenName(){
            return screenName;
        }

        void displayScreen(){
            cout<<"Screen Id: "<<screenId<<endl;
            cout<<"Total Seats: "<<totalSeats<<endl;
            cout<<"Screen Name: "<<screenName<<endl;
        }
};


// int main() {

//     Screen s1(1, "Screen 1", 50);
//     Screen s2(2, "Screen 2", 80);

//     cout << "SCREEN DETAILS" << endl;
//     cout << "---------------" << endl;

//     s1.displayScreen();

//     cout << endl;

//     s2.displayScreen();

//     return 0;
// }
