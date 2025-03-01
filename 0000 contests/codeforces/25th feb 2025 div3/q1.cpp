// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;
        if(k == 0) cout << 0 << endl;
        else if(k >= -p && k <= p) cout << 1 << endl;
        else{
            int ans = abs(k)%p == 0? abs(k)/p : (abs(k)/p) + 1;
            if(ans > n) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
}