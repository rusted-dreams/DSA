// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n<3) {
            cout << n+1 << endl;
            continue;
        }
        else {
            if(n%15 > 2) {
                cout << (n/15)*3 + 3 << endl;
                continue;
            }
            else {
                cout << (n/15)*3 + (n%15) + 1 << endl; 
                continue;
            }
        }
    }
}