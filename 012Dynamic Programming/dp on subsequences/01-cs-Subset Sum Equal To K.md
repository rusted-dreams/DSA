# Subset Sum Equal To K
problem link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954


### Recursive Solution
```cpp
#include <bits/stdc++.h> 
bool solve(int idx, int target, vector<int> &arr) {
    // base case:
    if(target == 0) return true;
    if(idx == 0) return (arr[0] == target);

    bool notPick = solve(idx-1, target, arr);
    bool pick = false;
    if(target >= arr[idx]) 
        pick = solve(idx-1, target - arr[idx], arr);
    
    return pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr);
}
```
---
### Memoization:
```cpp
#include <bits/stdc++.h> 
bool solve(int idx, int target, vector<int> &arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(idx == 0) return (arr[0] == target);

    if(dp[idx][target] != -1) return dp[idx][target];
    bool notPick = solve(idx-1, target, arr, dp);
    bool pick = false;
    if(target >= arr[idx]) 
        pick = solve(idx-1, target - arr[idx], arr, dp);
    
    return dp[idx][target] = pick | notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}
```
--- 
### Tabulation
```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    // base case1:
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }

    // base case 2:
    dp[0][arr[0]] = true;

    for(int i = 1; i<n; i++) {
        for(int target = 1; target <= k; target++) {
            bool pick = false;
            if(arr[i] <= target)
                pick = dp[i-1][target-arr[i]];
            bool notPick = dp[i-1][target];
            dp[i][target] = pick | notPick;
        }
    }

    return dp[n-1][k];
}
```

---
### tabulation with space optimization:

```cpp
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0);
    vector<bool> curr(k+1, 0);

    // base case:
    prev[0] = curr[0] = true;

    // base case 2:
    prev[arr[0]] = true;

    for(int i = 1; i<n; i++) {
        for(int target = 1; target <= k; target++) {
            bool pick = false;
            if(arr[i] <= target)
                pick = prev[target-arr[i]];
            bool notPick = prev[target];
            curr[target] = pick | notPick;
        }
        prev = curr;
    }

    return prev[k];
}
```