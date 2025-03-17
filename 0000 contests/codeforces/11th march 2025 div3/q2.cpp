// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        if(n == 1) {
            cout << arr[0] << endl;\
            continue;
        }
        sort(arr.begin(), arr.end());
        int res = arr[0] + arr[1] - 1;
        for(int i=2; i<n; i++) {
            res = res + arr[i] - 1;
        }
        cout << res << endl;
    }
}