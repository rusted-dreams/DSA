// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while(t--){;
        int n;
        cin >> n;
        string s;
        cin >> s;
        int empty = 0;
        int res = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '.'){
                empty++;
                if(empty == 3){
                    res = 2;
                    break;
                }
            }
            if(s[i] == '#' || i == n-1){
                if(empty <=2) res += empty;
                empty = 0;
            }
        }
        cout << res << endl;
    }
}