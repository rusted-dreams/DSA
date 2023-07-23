#include <iostream>
#include <math.h>
using namespace std;


bool isPowerOfTwo(int n) {
        for(int i =0; i<31; i++) {
            if (pow(2,i) == n) {
                return true;
            }
        }
        return false;
    }


int main() {
    int n;
    cout << "Enter a no.: ";
    cin >> n;
    cout << boolalpha << isPowerOfTwo(n) << endl;
}