// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        long long n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        long long res = 0;
        long long sec0 = 0;
        bool zero = false;
        long long count = 0;
        for(char ch:s) {
            if(ch == 'L') x--;
            else x++;
            count++;
            if(x == 0) {
                sec0 = count;
                zero = true;
                break;
            }
        }
        if (!zero || sec0>k){
            cout << 0 << endl;
            continue;
        }
        res = 1;
        k = k-sec0;
        long long sec1 = 0;
        bool fromZero = false;
        long long a = 0;
        count = 0;
        for(char ch: s) {
            if(ch == 'L') a--;
            else a++;
            count++;
            if(a == 0) {
                fromZero = true;
                sec1 = count;
                break;
            }
        }
        if(fromZero){
            res += k/sec1;
        }
        cout << res << endl;
    }
}