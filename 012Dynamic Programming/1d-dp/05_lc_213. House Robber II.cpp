// problem - 213. House Robber II
// link - https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

// tabulation with space optimization (bottom-up) approach:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house → rob it

        // ---- Case 1: Rob houses from index 0 to n-2 (exclude last house) ----
        int prev2 = nums[0];                 // Max loot up to house i-2
        int prev1 = max(nums[0], nums[1]);   // Max loot up to house i-1
        for (int i = 2; i < n - 1; i++) {    // Loop until second-last house
            int curr = max(prev1, prev2 + nums[i]); // Either skip or rob current
            prev2 = prev1;                   // Shift window
            prev1 = curr;
        }
        int res = prev1; // Max loot for first case

        // ---- Case 2: Rob houses from index 1 to n-1 (exclude first house) ----
        prev2 = nums[1];                     // Max loot up to house i-2
        prev1 = (n > 2) ? max(nums[1], nums[2]) : nums[1]; // Up to house i-1
        for (int i = 3; i < n; i++) {         // Loop until last house
            int curr = max(prev1, prev2 + nums[i]); // Skip or rob current
            prev2 = prev1;                   // Shift window
            prev1 = curr;
        }
        // Return the best of both cases
        return max(res, prev1);
    }
};


// // Tabulation (bottum - up approach):
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
//         vector<int> dp(n, -1);
//         dp[0] = nums[0];
//         if (n > 1) {
//             dp[1] = max(dp[0], nums[1]);
//         }
//         vector<int> dp2(n, -1);
//         for (int i = 2; i < n - 1; i++) {
//             dp[i] = max(dp[i], dp[i - 2] + nums[i]);
//             dp[i] = max(dp[i], dp[i - 1]);
//         }
//         if (n > 1) {
//             dp2[1] = nums[1];
//         }
//         if (n > 2) dp2[2] = max(dp2[1], nums[2]);
//         for (int i = 3; i < n; i++) {
//             dp2[i] = max(dp2[i], dp2[i - 2] + nums[i]);
//             dp2[i] = max(dp2[i], dp2[i - 1]);
//         }
//         return max(dp[n - 2], dp2[n - 1]);
//     }
// };



// // Using Memoization (Top-Down) approach
// class Solution {
//     // Returns max sum of non-adjacent elements from 0..idx
//     int helper(int idx, vector<int>& nums, vector<int>& dp) {
//         if(idx < 0) return 0; // Base: no houses left
//         if(dp[idx] != -1) return dp[idx]; // Return if already computed

//         // Option 1: Rob current house → skip previous one
//         int pick = nums[idx] + helper(idx - 2, nums, dp);
//         // Option 2: Skip current house
//         int notPick = helper(idx - 1, nums, dp);

//         // Store and return max of both choices
//         return dp[idx] = max(pick, notPick);
//     }

// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return nums[0]; // Only one house

//         vector<int> dp(n, -1);

//         // Case 1: Exclude last house (rob from 0 to n-2)
//         int res1 = helper(n - 2, nums, dp);

//         // Case 2: Exclude first house (rob from 1 to n-1)
//         fill(dp.begin(), dp.end(), -1);
//         vector<int> temp(nums.begin() + 1, nums.end());
//         int res2 = helper(n - 2, temp, dp);

//         // Return best of two scenarios
//         return max(res1, res2);
//     }
// };

// my solution using 2d dp and flag:
// class Solution {
//     int helper(int idx, vector<int>& nums, vector<vector<int>>& dp, bool flag) {
//         if (idx == 0) {
//             if (flag) return 0;
//             return nums[0];
//         }
//         if (idx < 0) return 0;
//         if (dp[idx][flag] != -1) return dp[idx][flag];

//         int pick = nums[idx] + helper(idx - 2, nums, dp, flag || (idx == nums.size() - 1));
//         int notPick = helper(idx - 1, nums, dp, flag);

//         return dp[idx][flag] = max(pick, notPick);
//     }

// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return nums[0];
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return helper(n - 1, nums, dp, false);
//     }
// };


int main() {
    Solution sol;

}