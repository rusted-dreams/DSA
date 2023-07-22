#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the no.: ";
    cin >> n;
    bool flag = true;
    for (int i=2; i<n; i++) {
        if (n%i ==0) {
            cout << n << " is not a prime no." << endl;
            flag = false;
            break;
        }
        else {
            continue;
        }
    }
    if (flag) {
        cout << n << " is a prime no." << endl;
        
    }

}