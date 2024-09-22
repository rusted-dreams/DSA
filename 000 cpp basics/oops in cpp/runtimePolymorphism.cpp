#include <iostream>
using namespace std;

class Animal
{
public:
    void speak()
    {
        cout << "speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "barking" << endl;
    }
};

class Batakh : public Animal
{
public:
    void speak()
    {
        cout << "quack quack" << endl;
    }
};

int main()
{
    Dog piyush;
    Batakh mridul;

    mridul.speak();
    piyush.speak();

    Animal cat;
    cat.speak();
}