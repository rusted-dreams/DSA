#include <iostream>
using namespace std;

class Hero{
    public:
    string name;
    private:
    int power;

    public:
    int getPower(){
        this -> power = power;
        return power;
    }
    void setPower(int pw) {
        this -> power = pw;
    }

    



};

int main() {
    Hero heman;
    heman.name = "heman";
    heman.setPower(76);

    cout << heman.name<< endl;
    cout << heman.getPower() << endl;

}