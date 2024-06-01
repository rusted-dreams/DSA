#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter a no. : ";
    cin >> n;
    bool flag = 1;

    if (n==1 || n==0) {
        cout << "neither prime nor composite";
        return 0;
    }
    else if (n < 0) {
        cout << "invalid input" << endl;
        return 0;
    }


    for (int i =2; i<(n/2)+1; i++) {
        if (n%i == 0) {
            flag = 0;
            break;
        }
    }
    if (flag) cout << "prime" << endl;
    else cout << "composite" << endl;
}