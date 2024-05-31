#include <iostream>
#include <cmath>
using namespace std;

void getReturn(double a, double r, int n) {
    for(int i=0; i<n; i++) {
        double amt = a * pow(r, i);
        cout << "Year " << i+1 << " $" << amt << endl;
    }
}

int main() {
    cout << "Enter the starting investment (a): ";
    double a;
    cin >> a;

    cout << "Enter the common ratio (r): ";
    double r;
    cin >> r;

    cout << "Enter the number of years (n): ";
    int n;
    cin >> n;

    getReturn(a, r, n);
}