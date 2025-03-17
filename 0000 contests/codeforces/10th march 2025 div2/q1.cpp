// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        long long n, x; 
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        long long total = 0; 
        for(int i:arr) total += i;
        if(total == (long long)x*n) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}