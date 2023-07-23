#include <iostream>
using namespace std;


int main() {
    int n;

    cout << "Enter the no.: ";
    cin >> n;
    int bn = 0;
    while(n) {
        bn = bn*10 + (n&1);
        n = n >> 1;
    }
    cout << n << " in binary is " << bn;
}