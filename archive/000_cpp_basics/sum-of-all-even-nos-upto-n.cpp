#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;
    int sum = 0;
    int i = 2;
    while (i<=n) {
        sum += i;
        i += 2;
    }
    
    cout << "sum of all even nos. upto " << n << " is " << sum << endl;
    
}