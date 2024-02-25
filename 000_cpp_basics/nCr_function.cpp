#include <iostream>
using namespace std;


int factorial(int a) {
    if (a==0) {
        return (int) 1;
    }
    int ans = 1;
    for(int i=a; i>1; i--) {
        ans *= i;
    }
    return ans;
}

int nCr(int n, int r) {
    int ans = (factorial(n))/(factorial(r)*factorial(n-r));
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int r;
    cout << "Enter r: ";
    cin >> r;

    cout << n << "C" << r << " = " << nCr(n,r) << endl;
}