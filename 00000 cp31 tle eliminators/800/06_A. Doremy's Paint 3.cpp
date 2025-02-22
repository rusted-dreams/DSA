// problem - A. Doremy's Paint 3
// link - https://codeforces.com/problemset/problem/1890/A

#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int num1 = arr[0];
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        bool possible = true;
        for(int i:arr){
            if(i == num1) count1++;
            else if(num2 != -1 && i == num2) count2++;
            else if(num2 == -1) {
                num2 = i;
                count2++;
            }
            else{
                possible = false;
                break;
            }
        }
        if(possible && (count1 == arr.size() || count1 == count2 || abs(count1-count2) == 1)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}