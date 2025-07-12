// problem - A. Buttons
// link - https://codeforces.com/problemset/problem/1858/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool anna = false;
        if (c & 1) {
            if (b <= a) anna = true;
        }
        else {
            if (a > b) anna = true;
        }
        cout << (anna ? "First" : "Second") << endl;
    }
}