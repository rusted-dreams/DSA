#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> b(n-2);
        for(int i=0; i<n-2; i++) {
            cin >> b[i];
        }
        bool exist = true;
        
        int zCount = INT_MIN;
        for(int i=0; i<n-2; i++) {
            if(b[i] == 0) zCount++;
            if(b[i] == 1) {
                if (zCount == 1) exist = false;
                zCount = 0;
            }
        }
        if(exist) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}