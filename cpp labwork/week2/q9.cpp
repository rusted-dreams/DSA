#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b, temp;
    cout << "Enter two positive integers : ";
    cin >> a >> b;
    temp = b;
    if (a <= 0 || b <=0) {
        cout << "Please enter positive integers!";
    }
    int result = gcd(a, b);
    cout << "GCD of " <<  a << " and " << temp << " is: " << result << endl;
}