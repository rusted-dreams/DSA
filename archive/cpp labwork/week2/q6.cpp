#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }
    
    cout << "Sum = " << sum << endl;

    cout << "Explaination\n" << "Sum of first " << n << " natural numbers is ";
    for(int j=1; j<=n; j++) {
        if (j == n) {
            cout << j;
            break;
        }
        cout << j << "+";
    }
    cout << endl;
}