// problem - Frog Jump

// link - https://www.geeksforgeeks.org/problems/geek-jump/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int cost(vector<int>& height, int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return abs(height[1] - height[0]);

        if (dp[n] != -1) return dp[n];

        int left = cost(height, n - 1, dp) + abs(height[n] - height[n - 1]);
        int right = cost(height, n - 2, dp) + abs(height[n] - height[n - 2]);

        return dp[n] = min(left, right);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size() - 1;
        vector<int> dp(n + 1, -1);
        return cost(height, n, dp);
    }
};


int main() {
    Solution sol;

}