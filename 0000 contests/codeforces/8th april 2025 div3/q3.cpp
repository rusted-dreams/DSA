#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x == 1 || 2) return true;
    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (n == 1 && (k == 1 || k == 2)) cout << "yes" << endl;
        else if (isPrime(n) && k == 1) cout << "yes" << endl;
        else cout << "NO" << endl;
    }
}