#include<bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/aggressive-cows_1082559



bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-lastPos >= mid){
            cowCount ++;
            if(cowCount == k) return true;
            lastPos = stalls[i];
        }
    }
    return false;

}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 1;
    int end = *max_element(stalls.begin(), stalls.end());
    int ans = -1;
    int mid = start + (end-start)/2;

    while (start<=end) {
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}