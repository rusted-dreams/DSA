// problem - 875. Koko Eating Bananas
// link - https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canEat(vector<int>& piles, int k, int h){
            long long totalHrs = 0;
            for(int i : piles) {
                if(i%k !=0) totalHrs += i/k + 1;
                else totalHrs += i/k;
                if(totalHrs > h) return false;
            }
            return true;
        }
        
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxi = 0;
            for(int i:piles) {
                maxi = max(i, maxi);
            }
            int start = 1;
            int end = maxi;
            int mid;
            // int res = INT_MAX;
            while(start <= end) {
                mid = start + (end-start)/2;
                if(canEat(piles, mid, h)){
                    // res = min(mid, res);
                    end = mid-1;
                }
                else start = mid+1;
            }
    
            // return res;
            return start;
        }
    };

int main() {
    Solution sol;
    
}