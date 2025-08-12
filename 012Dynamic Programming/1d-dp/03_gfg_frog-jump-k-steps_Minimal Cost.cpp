// problem - Minimal Cost

// link - https://www.geeksforgeeks.org/problems/minimal-cost/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int minCost(int k, vector<int>& arr, int idx, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int cost = INT_MAX;
        for (int i = 1; i <= k; i++) {
            if (idx - i >= 0) {
                int currCost = minCost(k, arr, idx - i, dp) + abs(arr[idx] - arr[idx - i]);
                cost = min(cost, currCost);
            }
        }
        return dp[idx] = cost;
    }
public:
    // Dp with memoization:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size() - 1;
        vector<int> dp(n + 1, -1);
        return minCost(k, arr, n, dp);
    }

    // // dp with tabulation (bottum up approach);
    // int minimizeCost(int k, vector<int>& arr) {
    //     int n = arr.size() - 1;
    //     vector<int> dp(n+1, 1e9);
    //     dp[0] = 0;
    //     for(int i=0; i<=n; i++) {
    //         for(int j=1; j<=k; j++) {
    //             if(i + j <= n)  {
    //                 int cost = dp[i] + abs(arr[i] - arr[i+j]);
    //                 dp[i+j] = min(dp[i+j], cost);
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
};

int main() {
    Solution sol;

}