// problem - 
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        string st = to_string(x);
        char ch = '9';
        for (char i : st) {
            ch = min(ch, i);
        }
        int res = ch - '0';
        cout << res << endl;
    }
}