#include<iostream>
#include<string>
using namespace std;

class Show{
    private:
        int showId;
        string movieTitle;
        string screenName;
        string startTime;

    public:
        Show(){
            showId = 0;
            movieTitle = "";
            screenName = "";
            startTime = "";
        }

        Show(int id, string title, string sc_name, string time){
            showId = id;
            movieTitle = title;
            screenName = sc_name;
            startTime = time;
        }

        int getShowId(){
            return showId;
        }

        string getMovieTitle(){
            return movieTitle;
        }

        string getScreenName(){
            return screenName;
        }

        string getStartTime(){
            return startTime;
        }

        void displayShow(){
            cout<<"Show ID: "<<showId<<endl;
            cout<<"Movie: "<<movieTitle<<endl;
            cout<<"Screen: "<<screenName<<endl;
            cout<<"Start Time: "<<startTime<<endl;
        }
};


// int main() {

//     Show s1(101, "Avengers", "Screen 1", "3:00 PM");
//     Show s2(102, "Avengers", "Screen 2", "6:30 PM");
//     Show s3(103, "Avengers", "Screen 3", "9:30 PM");

//     cout << "SHOW DETAILS" << endl;
//     cout << "============" << endl;

//     s1.displayShow();

//     cout << endl;

//     s2.displayShow();

//     cout << endl;

//     s3.displayShow();

//     return 0;
// }