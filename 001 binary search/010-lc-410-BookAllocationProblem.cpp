#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/split-array-largest-sum/description/


/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)
*/

bool isPossible(vector<int>& nums, int k, int mid){
    int count = 1;
    int partialSum = 0;
    for (int i=0;i<nums.size(); i++) {
        if(partialSum + nums[i] <= mid) {
            partialSum += nums[i];
        }
        else {
            count++;
            if(count > k || nums[i]>mid) {
                return false;
            }
            partialSum = nums[i];
        }

    }
    return true;
}

int allocateBooks(vector<int>& nums, int k) {
    int start = *max_element(nums.begin(), nums.end()); 
    int end =0;
    int ans = -1;
    for (int i =0; i< nums.size(); i++) {
        end += nums[i];
    }
    if(k==1) {
        return end;
    }
    int mid = start + (end-start)/2;

    while (start<= end){
        if(isPossible(nums, k, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    cout << allocateBooks(arr, 2) <<  endl;
}