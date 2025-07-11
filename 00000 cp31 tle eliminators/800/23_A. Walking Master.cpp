// problem - A. Walking Master
// link - https://codeforces.com/problemset/problem/1806/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d < b || (c > a && (c - a > d - b))) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        if (a == c && b == d) ans = 0;
        else if (c > a) ans = (d - b) + (d - c);
        else if (c <= a) {
            ans = (d - b) + (d - b) + abs(c - a);
        }
        cout << ans << endl;
    }
}