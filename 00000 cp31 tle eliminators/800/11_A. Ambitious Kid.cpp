// problem - A. Ambitious Kid
// link - https://codeforces.com/problemset/problem/1866/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res = min(res, abs(x));
    }
    cout << res << endl;
}