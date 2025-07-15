// problem - A. Coins
// link - https://codeforces.com/problemset/problem/1814/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        bool res = false;
        if ((n & 1) == 0 || ((n - k) & 1) == 0) res = true;
        cout << (res == true ? "yes" : "no") << endl;
    }
}