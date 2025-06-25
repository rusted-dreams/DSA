// problem - A. Goals of Victory
// link - https://codeforces.com/problemset/problem/1877/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            int ef = 0;
            cin >> ef;
            total += ef;
        }
        cout << 0 - total << endl;
    }
}