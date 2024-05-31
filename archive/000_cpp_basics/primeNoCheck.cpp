#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a no. to check for prime: ";
    cin >> x;
    int i = 2;
    bool flag = true;

    while (i < x) {
        if (x % i == 0) {
        flag = false;
        break;
        }
        i++;
    }
    if (flag) {cout << x << " is a prime no.";}
    else {cout << x << " is not a prime no.";}

}