// problem - B. Blank Space
// link - https://codeforces.com/problemset/problem/1829/B

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
        int res = 0;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                temp++;
            }
            else if (temp) {
                res = max(res, temp);
                temp = 0;
            }
        }
        res = max(res, temp);
        cout << res << endl;
    }
}