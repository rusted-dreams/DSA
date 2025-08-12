// problem - 198. House Robber
// link - https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = 0;
        if (n > 1) {
            prev1 = max(prev2, nums[1]);
        }
        for (int i = 2; i < n; i++) {
            int curr = prev2 + nums[i];
            curr = max(curr, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

// // Bottom up approach (tabulation):
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         dp[0] = nums[0];
//         if(n > 1) dp[1] = max(dp[0], nums[1]);
//         for(int i=2; i<n; i++) {
//             dp[i] = dp[i-2] + nums[i];
//             dp[i] = max(dp[i], dp[i-1]);
//         }
//         return dp[n-1];
//     }
// };

// // Memoization (top-down) approach
// class Solution {
//     int helper(int idx, vector<int>& nums, vector<int>& dp) {
//         if(idx < 0) return 0;
//         if(dp[idx] != -1) return dp[idx];
//         int take = nums[idx] + helper(idx - 2, nums, dp);
//         int notTake = helper(idx-1, nums, dp);
//         return dp[idx] = max(take, notTake);

//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size() - 1;
//         vector<int> dp(n+1, -1);
//         return helper(n, nums, dp);
//     }
// };

int main() {
    Solution sol;

}