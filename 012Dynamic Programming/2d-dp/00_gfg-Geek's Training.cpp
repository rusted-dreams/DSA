// problem - Geek's Training
// link - https://www.geeksforgeeks.org/problems/geeks-training/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Recursive helper to find max points till day 'idx'
    // given that the last task done was 'last'
    int helper(vector<vector<int>>& arr, int idx, int last, vector<vector<int>>& dp) {
        int point = 0;

        // Base case: on the first day, choose the best task 
        // that is not the same as 'last'
        if (idx == 0) {
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    point = max(point, arr[0][i]);
                }
            }
            return point;
        }

        // Return precomputed result if available (memoization)
        if (dp[idx][last] != -1) return dp[idx][last];

        // Try all tasks except the one done last
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                dp[idx][last] = max(dp[idx][last],
                    arr[idx][i] + helper(arr, idx - 1, i, dp));
            }
        }
        return dp[idx][last];
    }

public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, -1)); // dp[day][lastTask]

        // Try each possible task as the last day's task
        int score = helper(arr, n - 1, 0, dp);
        score = max(score, helper(arr, n - 1, 1, dp));
        score = max(score, helper(arr, n - 1, 2, dp));

        return score;
    }
};


int main() {
    Solution sol;

}