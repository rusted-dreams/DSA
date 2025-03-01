#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        const int mod = 998244353;
        int ans = 0;
        vector<int> arr(n);
        vector<int> count2;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            if(i == 0) {
                count2.push_back(arr[i] == 2? 1:0);
            }
            else{
                count2.push_back(count2[i-1] + arr[i] == 2? 1:0);
            }
        }

        int i =0;
        int j = n;
        while(i<j) {
            
        }

    }
}