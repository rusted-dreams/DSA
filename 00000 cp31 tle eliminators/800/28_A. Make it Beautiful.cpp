// problem - A. Make it Beautiful
// link - https://codeforces.com/problemset/problem/1783/A

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
        bool good = true;
        long long suum = arr[0];
        for (int i = 1; i < n; i++) {
            if (suum == arr[i]) {
                good = false;
                break;
            }
            else {
                suum += arr[i];
            }
        }
        if (good) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            sort(arr.rbegin(), arr.rend());
            if (arr[0] == arr[n - 1]) {
                cout << "NO" << endl;
                continue;
            }
            if (arr[0] == arr[1]) swap(arr[0], arr[n - 1]);
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}