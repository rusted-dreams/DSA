#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter a number: ";
    cin >> n;
    int x = n;
    int sum = 0;
    while (n>0) {
        sum += n;
        --n;
    }
    cout << "sum of first "<< x << " nos. is " << sum;

}