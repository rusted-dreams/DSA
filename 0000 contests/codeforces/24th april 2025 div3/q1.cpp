// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones = 0;
        for (char ch : s) {
            if (ch == '1') ones++;
        }
        if (!ones) {
            cout << 0 << endl;
            continue;
        }
        cout << (ones * n) - n << endl;
    }
}