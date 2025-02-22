#include <bits/stdc++.h>
using namespace std;
 
bool isSorted(vector<int> &arr) {
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}
 
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        if(k == 1 && !isSorted(arr)) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}