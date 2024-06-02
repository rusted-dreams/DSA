#include <iostream>
using namespace std;

// print the binary form of a decimal no using the right shift operator.
int decimalToBinary(int n) {
    int binary = 0;
    int multiplier = 1;
    while (n) {
        binary += multiplier*(n&1);
        n = n >> 1;
        multiplier *= 10;
    }
    return binary;
}

// print binary form of -ve decimal nos.

string negativeToBinary(int n) {
    string binary = "";
    for (int i=0; i<32; i++){
        if (n&1) {
            binary = "1" + binary;
        }
        else {
            binary = "0" + binary;
        }
        n= n>>1;
    }
    return binary;
}

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << "binary of " << n << " is : " << decimalToBinary(n) << endl;
    int n2;
    cout << "enter n2: ";
    cin >> n2;
    cout << "binary of " << n2 << " is : "<< negativeToBinary(n2) << endl;
   
}