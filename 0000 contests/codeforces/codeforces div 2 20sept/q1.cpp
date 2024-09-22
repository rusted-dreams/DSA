#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x, y;
        cin >> x >> y;
        int time = 0;
        if (x>=y) {
            if(n%y == 0){
                time = n/y;
            }
            else{
                time = n/y + 1;
            }
        }
        else if(y>x) {
            if(n%x==0){
                time = n/x;
            }
            else{
                time = n/x + 1;
            }
        }
        cout << time << endl;

    }
}