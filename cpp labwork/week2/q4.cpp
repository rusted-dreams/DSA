#include <iostream>
using namespace std;


int main() {
    int p1, p2, p3;
    cout << "Enter the price of Smartphone 1: $";
    cin >> p1;
    cout << "Enter the price of Smartphone 1: $";
    cin >> p2;
    cout << "Enter the price of Smartphone 1: $";
    cin >> p3;

    if (p1<p2 && p2<p3) {
        cout << "The best deal in Smartphone is $" << p1 << endl;
    }
    else if (p2<p3 && p3<p1) {
        cout << "The best deal in Smartphone is $" << p2 << endl;
    }
    else if (p3<p2 && p2<p1) {
        cout << "The best deal in Smartphone is $" << p3 << endl;
    }
}