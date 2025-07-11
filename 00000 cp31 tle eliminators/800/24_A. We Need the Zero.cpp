// problem - A. We Need the Zero
// link - https://codeforces.com/problemset/problem/1805/A

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
        int mask = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mask ^= x;
        }
        if (mask && (n & 1) == 0) cout << -1 << endl;
        else cout << mask << endl;
    }
}