// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k%2 == 0) {
            for(int i=1; i<n-1; i++) {
                cout << n-1 << " ";
            }
            cout << n << " " << n-1 << endl;
            continue;
        }
        else {
            for(int i=1; i<n; i++) {
                cout << n << " ";
            }
            cout << n-1 << endl;
            continue;
        }
    }
}