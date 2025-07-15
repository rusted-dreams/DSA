// problem - A. One and Two
// link - https://codeforces.com/problemset/problem/1788/A

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
        vector<int> twoIdx;
        int two = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 2) {
                two++;
                twoIdx.push_back(i);
            }
        }
        int res = -1;
        if (two == 0) {
            res = 1;
        }
        else if (two % 2 == 0) {
            int k = two / 2;
            res = twoIdx[k - 1] + 1;
        }
        cout << res << endl;
    }
}