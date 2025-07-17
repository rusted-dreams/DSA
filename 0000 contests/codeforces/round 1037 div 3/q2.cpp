// problem - B. No Casino in the Mountains
// link - https://codeforces.com/contest/2126/problem/B

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
        int res = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) count++;
            else if (arr[i] == 1) count = 0;
            if (count == k) {
                res++;
                count = -1;
            }
        }
        cout << res << endl;
    }
}