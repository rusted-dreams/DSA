// problem - 410. Split Array Largest Sum
// link - https://leetcode.com/problems/split-array-largest-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& nums, int maxi, int k) {
        int n = nums.size();
        int currSum = 0;
        int splitCount = 1;
        for(int i=0; i<n; i++) {
            if(currSum + nums[i] > maxi) {
                splitCount++;
                currSum = nums[i];
                if(splitCount > k) return false;
            }
            else currSum += nums[i];
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int end = accumulate(nums.begin(), nums.end(), 0);
        int mid;
        while(start <= end) {
            mid = start + (end - start)/2;
            if(check(nums, mid, k)) {
                end = mid - 1;
            }
            else start = mid+1;
        }
        return start;
    }
};

int main() {
    Solution sol;
}