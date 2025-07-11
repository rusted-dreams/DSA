// problem - A. Don't Try to Count
// link - https://codeforces.com/problemset/problem/1881/A

#include <bits/stdc++.h>
using namespace std;

bool check(string x, string s) {
    if (x.size() < s.size()) return false;
    for (int i = 0; i < x.size(); i++) {
        if (x.substr(i, s.size()) == s) return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        int ans = -1;
        for (int i = 0; i <= 5; i++) {
            if (check(x, s)) {
                ans = i;
                break;
            }
            x += x;
        }
        cout << ans << endl;
    }
}