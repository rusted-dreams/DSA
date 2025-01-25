#include<bits/stdc++.h>
using namespace std;

// Base class: Movie
class Movie {
protected:
    string title;
    string genre;
    string release_date;
    int runtime; // in minutes
    float rating; // e.g., out of 10
    string age_group; // e.g., "PG-13", "R"

public:
    Movie(string t, string g, string r_date, int rt, float rtng, string age)
        : title(t), genre(g), release_date(r_date), runtime(rt), rating(rtng), age_group(age) {}

    void display() {
        cout << "Title: " << title << "\n"
             << "Genre: " << genre << "\n"
             << "Release Date: " << release_date << "\n"
             << "Runtime: " << runtime << " minutes\n"
             << "Rating: " << rating << "/10\n"
             << "Age Group: " << age_group << "\n";
    }

    void update(string t, string g, string r_date, int rt, float rtng, string age) {
        title = t;
        genre = g;
        release_date = r_date;
        runtime = rt;
        rating = rtng;
        age_group = age;
    }

    string getTitle() { return title; }
};

// Derived class: Theatre
class Theatre {
private:
    string venue;
    vector<Movie> movies;
    int total_seats;
    int booked_seats;
    map<string, pair<string, int>> schedule; // time - (movie title, price)

public:
    Theatre(string v, int seats)
        : venue(v), total_seats(seats), booked_seats(0) {}

    void addMovie(Movie movie, string time, int price) {
        movies.push_back(movie);
        schedule[time] = make_pair(movie.getTitle(), price);
    }

    void displayMovies() {
        cout << "Movies at " << venue << ":\n";
        for (auto &movie : movies) {
            movie.display();
            cout << "---\n";
        }
    }

    void displaySchedule() {
        cout << "Schedule at " << venue << ":\n";
        for (auto &entry : schedule) {
            cout << "Time: " << entry.first << ", Movie: " << entry.second.first << ", Price: Rs." << entry.second.second << "\n";
        }
    }

    bool bookTicket(string time) {
        if (schedule.find(time) == schedule.end()) {
            cout << "No movie scheduled at this time.\n";
            return false;
        }
        if (booked_seats >= total_seats) {
            cout << "Sorry, the theatre is fully booked.\n";
            return false;
        }
        booked_seats++;
        cout << "Ticket booked for " << schedule[time].first << " at " << time << ".\n";
        return true;
    }

    bool cancelTicket(string time) {
        if (booked_seats == 0) {
            cout << "No tickets have been booked.\n";
            return false;
        }
        booked_seats--;
        cout << "Ticket for " << schedule[time].first << " at " << time << " has been canceled.\n";
        return true;
    }

    int checkPrice(string time) {
        if (schedule.find(time) != schedule.end()) {
            return schedule[time].second;
        } else {
            cout << "No movie scheduled at this time.\n";
            return -1;
        }
    }

    string getVenue() { return venue; }
};

// Derived class: User
class User {
private:
    string name;
    int age;
    string email;
    string phone;
    vector<Theatre> theatres;

public:
    User(string n, int a, string e, string p)
        : name(n), age(a), email(e), phone(p) {}

    void addTheatre(Theatre theatre) {
        theatres.push_back(theatre);
    }

    void viewMovies() {
        for (auto &theatre : theatres) {
            theatre.displayMovies();
        }
    }

    void viewSchedule() {
        for (auto &theatre : theatres) {
            cout << "Venue: " << theatre.getVenue() << "\n";
            theatre.displaySchedule();
            cout << "---\n";
        }
    }

    void bookTicket(string venue, string time) {
        for (auto &theatre : theatres) {
            if (theatre.getVenue() == venue) {
                theatre.bookTicket(time);
                return;
            }
        }
        cout << "Theatre not found.\n";
    }

    void cancelTicket(string venue, string time) {
        for (auto &theatre : theatres) {
            if (theatre.getVenue() == venue) {
                theatre.cancelTicket(time);
                return;
            }
        }
        cout << "Theatre not found.\n";
    }
};

int main() {
    // Create movies
    Movie movie1("Inception", "Sci-Fi", "2010-07-16", 148, 8.8, "PG-13");
    Movie movie2("Titanic", "Romance", "1997-12-19", 195, 7.8, "PG-13");

    // Create theatres
    Theatre theatre1("Grand Venice", 100);
    theatre1.addMovie(movie1, "18:00", 450);
    theatre1.addMovie(movie2, "21:00", 310);

    // Create user
    User user("sm", 25, "sm@email.com", "8319681297");
    user.addTheatre(theatre1);


    cout << "\n--- Available Movies ---\n";
    user.viewMovies();

    cout << "\n--- Schedule ---\n";
    user.viewSchedule();

    cout << "\n--- Booking Ticket ---\n";
    user.bookTicket("Grand Venice", "18:00");

    cout << "\n--- Canceling Ticket ---\n";
    user.cancelTicket("Grand Venice", "18:00");

    return 0;
}
