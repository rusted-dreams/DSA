// problem - A. Array Coloring
// link - https://codeforces.com/problemset/problem/1857/A

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
        vector<int> arr(n);
        int oddCount = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] & 1) oddCount++;
        }
        if (oddCount & 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}