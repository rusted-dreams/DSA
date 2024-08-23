#include<bits/stdc++.h>
using namespace std;



bool isPossible(vector<int> &boards, int k, int mid) {
    int count =1;
    int partialSum = 0;
    for(int i =0; i<boards.size(); i++) {
        if(partialSum + boards[i] <= mid) {
            partialSum += boards[i];
        }
        else{
            count ++;
            if (count > k || boards[i] > mid) {
              return false;
            }
            partialSum = boards[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k){
    int start = *max_element(boards.begin(), boards.end());
    int ans = -1;
    int end = 0;
    for (int i=0; i<boards.size(); i++) {
        end += boards[i];
    }
    if(k==1) return end;

    int mid = start + (end-start)/2;
    while(start<=end) {
        if(isPossible(boards, k, mid)){
            ans = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}


int main() {
    vector<int> boards;
}