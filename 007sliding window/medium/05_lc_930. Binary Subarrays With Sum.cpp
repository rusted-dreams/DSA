// problem - 930. Binary Subarrays With Sum
// link - https://leetcode.com/problems/binary-subarrays-with-sum/

#include <bits/stdc++.h>
using namespace std;

// the total no. of subarrays with sum == goal is:
// (# subarrays with sum <= goal) - (# subarr with sum <= goal-1)

// helper func. to calculate no. of subarrays with sum <= goal
int helper(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (sum > goal) {
            sum -= nums[l];
            l++;
        }
        if (sum <= goal) {
            count += r - l + 1;
        }
        r++;
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt1 = helper(nums, goal);
    int cnt2 = helper(nums, goal - 1);
    return cnt1 - cnt2;
}
int main() {

}