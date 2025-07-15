// problem - C. Prepend and Append
// link - https://codeforces.com/problemset/problem/1791/C

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
        string s;
        cin >> s;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            if (s[start] != s[end]) {
                start++;
                end--;
            }
            else break;
        }
        int res;
        if (start > end) {
            res = 0;
        }
        else res = end - start + 1;
        cout << res << endl;
    }
}