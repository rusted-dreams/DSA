#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> stations(n);
        for(int i=0; i<n; i++) {
            cin >> stations[i];
        }
        int res = stations[0];
        for(int i=1; i<n; i++) {
            res = max(res, stations[i]-stations[i-1]);
        }
        res = max(res, (x-stations[n-1])*2);
        cout << res << endl;
    }    
}