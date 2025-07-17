// problem - D. This Is the Last Time
// link - https://codeforces.com/contest/2126/problem/D

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<vector<int>> cs(n);
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            cs[i] = { a, c, b };
        }

        sort(cs.begin(), cs.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
            });
        int coins = x;
        for (int i = 0; i < n; i++) {
            int a = cs[i][0];
            int b = cs[i][1];
            int c = cs[i][2];

            if (b > coins && a <= coins && c >= coins) {
                coins = b;
            }
        }
        cout << coins << endl;
    }
}