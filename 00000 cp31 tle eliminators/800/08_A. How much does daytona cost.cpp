// problem - A. How Much Does Daytona Cost?
// link - https://codeforces.com/problemset/problem/1878/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool check = false;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a == k) check = true;
        }
        if (check) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}