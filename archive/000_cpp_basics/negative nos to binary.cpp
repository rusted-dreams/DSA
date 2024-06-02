#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "enter a negative no.: ";
    cin >> n;
    string binary = "";
    for (int i = 0; i<=31; i++) {
        if (n&1) {
            binary = "1" + binary;
        } else {
            binary = "0" + binary;
        }
        n = n>>1;
    }
    cout << binary << endl;
    
}