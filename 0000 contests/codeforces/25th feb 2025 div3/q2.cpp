// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        long long count1 = 0;
        long long count2 = 0;
        for(char ch : s) {
            if (ch == '-') count1++;
            else count2++;
        }
        if(count1 < 2) cout << 0 << endl;
        else {
            long long ans = (count1/2) * count2 * (count1-(count1/2));
            cout << ans << endl;
        }
    }
}