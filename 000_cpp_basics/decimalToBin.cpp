#include <iostream>
using namespace std;


int main() {
    int n;

    cout << "Enter the no.: ";
    cin >> n;
    int bn = 0;
    int multiplier = 1;
    while(n) {
        bn = bn + (n&1)*multiplier;
        n = n >> 1;
        multiplier *= 10;
    }
    cout << n << " in binary is " << bn;
}