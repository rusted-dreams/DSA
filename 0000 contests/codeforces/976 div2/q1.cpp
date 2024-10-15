#include <iostream>
#include<math.h>
#include<vector>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int ans = -1;
        int n, k;
        cin >> n >> k;
        int count = 0;
        if(k>n) ans = n;
        else if(k == n){
            cout << 1 << endl;
            continue;
        }
        else if(k == 1) {
            cout << n << endl;
            continue;
        }
        else {
           int i = 0;
           vector<int> powerK;
           int power = pow(k, i);
           while(power<=n && k>1) {
                powerK.push_back(power);
                i++;
                power = pow(k, i);
            }
            i = powerK.size()-1;
            while(n!=0){
                if(n> powerK[i]){
                    count++;
                    n = n-powerK[i];
                }
                else if(n == powerK[i]){
                    count++;
                    ans = count;
                    break;
                }
                if(n < powerK[i]){
                    i--;
                }
            } 
        }
        cout << ans << endl;
    }
}