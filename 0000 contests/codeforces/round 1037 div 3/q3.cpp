// problem - C. I Will Definitely Make It
// link - https://codeforces.com/contest/2126/problem/C

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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        k = arr[k - 1];
        sort(arr.begin(), arr.end());
        int w = 0;
        int maxH = arr.back();
        if (maxH - k < k) {
            cout << "YES" << endl;
            continue;
        }
        int i = 0;
        bool possible = true;
        for (i; i < n; i++) {
            if (arr[i] < k) continue;
            if (arr[i] - k <= k - w) {
                w += arr[i] - k;
                k = arr[i];
            }
            else {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;

    }
}