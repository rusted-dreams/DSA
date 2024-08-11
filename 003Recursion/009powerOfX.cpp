#include <iostream>
using namespace std;


double power(double x, int n) {
    // base case:
    if (n == 0) return 1;

    if(n<0) {
        return 1/power(x, -n);
    }
    if (n%2 == 0) {
        double half = power(x, n/2);
        return half*half;
    }else {
        return x*power(x, n-1);
    }
}

int main() {
    double x = 4;
    int n = 3;

    int ans = power(x, n);
    cout << x << " power " << n << " = " << ans << endl;
}