// problem - A. Unit Array
// link - https://codeforces.com/problemset/problem/1834/A

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
        int neg = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) pos++;
            else neg++;
        }

        int res = -1;
        if (pos >= neg) {
            if (neg & 1) res = 1;
            else res = 0;
        }
        else {
            int diff = neg - pos;
            if (diff & 1) res = diff / 2 + 1;
            else res = diff / 2;
            neg = neg - res;
            if (neg & 1) res += 1;
        }
        cout << res << endl;
    }
}