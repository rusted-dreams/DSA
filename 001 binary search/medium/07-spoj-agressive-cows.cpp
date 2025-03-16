// problem -
// link - 

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& stalls, int dist, int k) {
    int n = stalls.size();
    int cowsPlaced = 1;
    int lastCow = stalls[0];
    for(int i=1; i<n; i++) {
        if(stalls[i] - lastCow >= dist) {
            cowsPlaced++;
            lastCow = i;
        }
        if(cowsPlaced == k) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for(int i=0; i<n; i++) {
            cin >> stalls[i];
        }
        sort(stalls.begin(), stalls.end());
        
        int start = 1;
        int end = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
        int mid;
        while(start <= end) {
            mid = start + (end-start)/2;
            if(check(stalls, mid, c)) {
                start = mid+1;
            }
            else end = mid-1;
        }
        cout << end << endl;
    }
}