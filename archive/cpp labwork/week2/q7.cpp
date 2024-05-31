#include <iostream>
using namespace std;


int main() {
    cout << "Enter a decimal number: ";
    int n;
    cin >> n;
    int x = n;
    int binaryN=0;
    int multiplier = 1;
    while(x!=0) {
        
        binaryN = binaryN + (x&1)*multiplier;
        x = x >> 1;
        multiplier *= 10;
    }
    cout <<"Binary representation: " << binaryN << endl;
}