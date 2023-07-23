#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int n;
    cout << "Enter a no.: ";
    cin >> n;
    bool flag = false;

    for(int i = 0; i<31; i++) {
        if (pow(2,i) == n) {
            flag = true;
            break;
        }
    }
    cout << boolalpha << flag;
}