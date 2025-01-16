#include <bits/stdc++.h>
using namespace std;

class Movie{
    public:
        string name;
        string date;
        string time;
        int runtime;
        string genre;
        string venue;

        Movie(string name, string date, string time, int runtime, string genre, string venue){
            this->name = name;
            this->date = date;
            this->time = time;
            this->runtime = runtime;
            this->genre = genre;
            this->venue = venue;
        }
        void display(){
            cout << "Movie: " << this->name << endl;
            cout << "date: " << this->date << endl;
            cout << "time: " << this->time << endl;
            cout << "runtime: " << this->runtime << "minutes" << endl;
            cout << "genre: " << this->genre << endl;
            cout << "venue: " << this->venue << endl;
        }
        void update(string date, string time, string venue){
            this->date = date;
            this->time = time;
            this->venue = venue;
        }
};

class Theatre{
public:
    vector<Movie> movies;
    string name;
    string type;
    int totalSeats;
    int bookedSeats;
    Theatre(vector<Movie> movies){
        this->movies = movies;
    }
    Theatre(string name, string type, int totalSeats, int bookedSeats = 0) {
        this->name = name;
        this->type = type;
        this->totalSeats = totalSeats;
        this->bookedSeats = bookedSeats;
    }

    bool availableSeats() {
        if(totalSeats-bookedSeats);
    }
};

class Customer{
    vector<Theatre> theatres;
    string name;
    string email;
    int phone;
    int age;

    Customer(vector<Theatre> theatres, string name, string email, int phone, int age){
        this->theatres = theatres;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->age = age;
    }

    string bookTicket(int qty, Theatre theatre) {
        for(auto i : theatres){
            if(i == theatre){
                
            }
        }
    }

};

int main() {
    
}