// problem - A. United We Stand
// link - https://codeforces.com/problemset/problem/1859/A

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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int num = arr[0];
        bool same = true;
        for (int i : arr) {
            if (i != num) {
                same = false;
                break;
            }
        }
        if (same) cout << -1 << endl;
        else {
            int idx = 0;
            num = arr[0];
            while (arr[idx] == num) idx++;

            vector<int> a(idx, num);
            vector<int> b(arr.begin() + idx, arr.end());

            int x = a.size();
            int y = b.size();
            cout << x << " " << y << endl;
            for (int i = 0; i < x; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < y; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        }

    }
}