// problem - Introduction to DP
// link - https://www.geeksforgeeks.org/problems/introduction-to-dp/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
    const int MOD = 1e9 + 7;
    long long int fibonacci(int n, vector<long long int>& dp) {
        if (n <= 1) return dp[n] = n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp) % MOD;
    }
public:
    long long int topDown(int n) {
        vector<long long int> dp(n + 1, -1);
        return fibonacci(n, dp) % MOD;
    }

    long long int bottomUp(int n) {
        long long int prev2 = 0;
        long long int prev = 1;

        for (int i = 2; i <= n; i++) {
            long long int curr = (prev + prev2) % MOD;
            prev2 = prev;
            prev = curr;
        }
        return prev % MOD;
    }
};

int main() {
    Solution sol;

}