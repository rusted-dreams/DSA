// problem - A. Two Permutations
// link - https://codeforces.com/problemset/problem/1761/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n - a - b >= 2 || a + b == 2 * n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}