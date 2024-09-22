#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    while(t--) {
        int n;
        int x = -1;
        if(n<=2) x = -1;
        int input;
        vector<int> wealth;
        for(int i=0; i<n; i++){
            cin >> input;
            wealth.push_back(input);
        }
        sort(wealth.begin(), wealth.end());
        int mid = n/2 + 1;
        int totalWealth = accumulate(wealth.begin(), wealth.end(),0);
        int avgWealth = totalWealth/n;
        if(wealth[mid] < avgWealth) x = 0;
        else {
             x = 2*n* wealth[mid] - totalWealth +1;
        }
        cout << x << endl;

    }
}