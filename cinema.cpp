#include <iostream>
#include <string>
#include <vector>

// #include "movie.cpp"
// #include "screen.cpp"
using namespace std;


class Cinema {
private:
    string cinemaName;
    vector<Movie> movies;
    vector<Screen> screens;

public:
    Cinema() {
        cinemaName = "";
    }

    Cinema(string name) {
        cinemaName = name;
    }

    void addMovie(Movie movie) {
        movies.push_back(movie);
    }

    void addScreen(Screen screen) {
        screens.push_back(screen);
    }

    void displayMovies() {

        cout << "========== MOVIES ==========" << endl;

        if (movies.empty()) {
            cout << "No movies available." << endl;
            return;
        }

        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". "
                 << movies[i].getTitle() << endl;
        }
    }

    void displayScreens() {

        cout << "========== SCREENS ==========" << endl;

        if (screens.empty()) {
            cout << "No screens available." << endl;
            return;
        }

        for (int i = 0; i < screens.size(); i++) {
            screens[i].displayScreen();
            cout << endl;
        }
    }

    Movie* getMovie(int index) {

        if (index < 0 || index >= movies.size()) {
            return nullptr;
        }

        return &movies[index];
    }

    Screen* getScreen(int index) {

        if (index < 0 || index >= screens.size()) {
            return nullptr;
        }

        return &screens[index];
    }

    string getCinemaName() {
        return cinemaName;
    }
};


// int main() {

//     Cinema cinema("PVR Cinema");

   
//     Movie m1(101, "Avengers", "Action", 180, true);
//     Movie m2(102, "Inception", "Sci-Fi", 148, true);
//     Movie m3(103, "Frozen", "Animation", 102, false);

//     cinema.addMovie(m1);
//     cinema.addMovie(m2);
//     cinema.addMovie(m3);

//     // Screens
//     Screen s1(1, "Screen 1", 50);
//     Screen s2(2, "Screen 2", 80);

//     cinema.addScreen(s1);
//     cinema.addScreen(s2);

//     cout << "Cinema: "
//          << cinema.getCinemaName() << endl;

//     cout << endl;

//     cinema.displayMovies();

//     cout << endl;

//     cinema.displayScreens();

//     return 0;
// }