// problem - Geek's Training
// link - https://www.geeksforgeeks.org/problems/geeks-training/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        // dp[day][lastTask] = max points till 'day' if lastTask was done on the previous day (0..2) or none (3)
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Base case: Day 0, choose max possible if lastTask was not that task
        dp[0][0] = max(arr[0][1], arr[0][2]); // Last task 0, so pick best of task 1 or 2
        dp[0][1] = max(arr[0][0], arr[0][2]); // Last task 1, so pick best of task 0 or 2
        dp[0][2] = max(arr[0][0], arr[0][1]); // Last task 2, so pick best of task 0 or 1
        dp[0][3] = max({ arr[0][0], arr[0][1], arr[0][2] }); // No last task, pick best of all

        // Fill DP table for each day
        for (int day = 1; day < n; day++) {
            for (int last = 0; last <= 3; last++) {
                // Try all tasks except the one done last
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = dp[day - 1][task] + arr[day][task]; // Points if choosing this task today
                        dp[day][last] = max(point, dp[day][last]); // Take maximum
                    }
                }
            }
        }

        return dp[n - 1][3]; // Max points at last day with no restriction
    }
};


// // Using Memoization:
// class Solution {
//     // Recursive helper to find max points till day 'idx'
//     // given that the last task done was 'last'
//     int helper(vector<vector<int>>& arr, int idx, int last, vector<vector<int>>& dp) {
//         int point = 0;

//         // Base case: on the first day, choose the best task 
//         // that is not the same as 'last'
//         if(idx == 0) {
//             for(int i = 0; i < 3; i++) {
//                 if(i != last) {
//                     point = max(point, arr[0][i]);
//                 }
//             }
//             return point;
//         }

//         // Return precomputed result if available (memoization)
//         if (dp[idx][last] != -1) return dp[idx][last];

//         // Try all tasks except the one done last
//         for(int i = 0; i < 3; i++) {
//             if(i != lwwwwast) {
//                 dp[idx][last] = max(dp[idx][last],
//                                     arr[idx][i] + helper(arr, idx-1, i, dp));
//             }
//         }
//         return dp[idx][last];
//     }

// public:
//     int maximumPoints(vector<vector<int>>& arr) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(4, -1)); // dp[day][lastTask]

//         // Try each possible task as the last day's task
//         return helper(arr, n-1, 3, dp);

//     }
// };


int main() {
    Solution sol;

}