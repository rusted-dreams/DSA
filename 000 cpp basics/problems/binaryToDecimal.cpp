#include <iostream>
#include <math.h>
using namespace std;

int binaryToDecimal(int b) {
    int i = 0;
    int decimal = 0;
    while(b) {
        if (b&1)
        decimal += pow(2, i);
        i++;
        b = b/10;
    }
    return decimal;
}

int main() {
    int b; 
    cout << "enter binary : ";
    cin >> b;
    cout << "decimal of " << b << " is : " << binaryToDecimal(b) << endl;
}