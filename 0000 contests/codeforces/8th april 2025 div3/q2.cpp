// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pre(n, -1);
        vector<int> post(n, -1);
        pre[0] = 0;
        post[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') pre[i] = pre[i - 1] + 1;
            else pre[i] = pre[i - 1];
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int remove = pre[i] + n - i - 1;
                res = min(res, remove);
            }
        }
        cout << res << endl;
    }
}