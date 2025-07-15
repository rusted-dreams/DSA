// problem - B. Sequence Game
// link - https://codeforces.com/problemset/problem/1862/B

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
        vector<int> b;
        b.push_back(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) b.push_back(arr[i]);
            else {
                b.push_back(arr[i]);
                b.push_back(arr[i]);
            }
        }
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << (i == b.size() - 1 ? '\n' : ' ');
        }

    }
}