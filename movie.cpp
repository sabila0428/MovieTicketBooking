#include<iostream>
#include<string>
using namespace std;

class Movie{
    private:
        int movieId;
        string title;
        string genre;
        int duration;
        bool isPlaying;
    
    public:
        Movie(){ //default constructor, so that intitial obj has no garbage values.
            movieId = 0;
            title = "";
            genre = "";
            duration = 0;
            isPlaying = false;
        }

        Movie(int id, string t, string g, int dur, bool play){
            movieId = id;
            title = t;
            genre = g;
            duration = dur;
            isPlaying = play;
        }

        int getId(){
            return movieId;
        }

        string getTitle(){
            return title;
        }

        string getGenre(){
            return genre;
        }

        int getDuration(){
            return duration;
        }

        bool getPlayStatus(){
            return isPlaying;
        }

        void setCurrStatus(bool status){
            isPlaying = status;
        }

        void displayMovie(){
            cout<< "Movie ID: "<<movieId<<endl;
            cout<< "Movie Title: "<<title << endl;
            cout<<"Movie Genre: "<<genre<<endl;
            cout<<"Duration: "<< duration<<"minutes"<<endl;

            if(isPlaying)
                cout<<"Currently Playing: Yes"<<endl;
            else    
                cout<<"Currently Playing : No"<<endl;
        }
};

// int main()
// {
//     Movie m1(101, "Avengers", "Action", 180, true);
//     Movie m2(102, "Inception", "Sci-Fi", 148, true);
//     Movie m3(103, "Frozen", "Animation", 102, false);

//     m1.displayMovie();

//     cout << endl;

//     m2.displayMovie();

//     cout << endl;

//     m3.displayMovie();

//     return 0;
// }