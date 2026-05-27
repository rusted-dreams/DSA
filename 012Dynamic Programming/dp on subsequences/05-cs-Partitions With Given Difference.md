#  Partitions With Given Difference
problem link: https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628

Approach: 
- given : s1 + s2 = totalSum;
  - s1 - s2 = d;
- -> d + s2 + s2 = totalSum
- -> 2*s2 = totalSum-d
- -> s2 = (totalSum - d) / 2
hence the problem is now reduced to the previous problem of find total subsets with sum k (i.e. s2) in this case.

### Recursive:
```cpp
#include <bits/stdc++.h> 
int MOD = 1e9+7;

int solve(int idx, int sum, vector<int>& arr) {
    if(idx == 0) {
        if(arr[0] == 0 && sum == 0) return 2;
        if(sum == 0 || arr[0] == sum) return 1;
        return 0; 
    }

    int pick = 0;
    if(arr[idx] <= sum) 
        pick = solve(idx-1, sum-arr[idx], arr);
    int notPick = solve(idx-1, sum, arr);

    return (pick + notPick)%MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(d>total || (total-d)%2) return 0;
    int target = (total - d)/2;
    return solve(n-1, target, arr);
}
```
---

### recursive + memo.
```cpp
#include <bits/stdc++.h> 
int MOD = 1e9+7;

int solve(int idx, int sum, vector<int>& arr, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(arr[0] == 0 && sum == 0) return 2;
        if(sum == 0 || arr[0] == sum) return 1;
        return 0; 
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];

    int pick = 0;
    if(arr[idx] <= sum) 
        pick = solve(idx-1, sum-arr[idx], arr, dp);
    int notPick = solve(idx-1, sum, arr, dp);

    return dp[idx][sum] = (pick + notPick)%MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(d>total || (total-d)%2) return 0;
    int target = (total - d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return solve(n-1, target, arr, dp);
}
```

---

### tabulation:

```cpp
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(d>total || (total-d)%2) return 0;
    int target = (total - d)/2;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    
    // base cases:
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1; 

    for(int idx = 1; idx < n; idx++) {
        for(int sum = 0; sum <= target; sum++) {
            int pick = 0;
            if(arr[idx] <= sum) pick = dp[idx-1][sum - arr[idx]];
            int notpick = dp[idx-1][sum];
            dp[idx][sum] = (pick + notpick)%MOD;
        }
    }
    return dp[n-1][target];
}
```

--- 

### tabulation with space optimization:
```cpp
int countPartitions(int n, int d, vector<int> &arr) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    if(d>total || (total-d)%2) return 0;
    int target = (total - d)/2;
    // vector<vector<int>> dp(n, vector<int>(target+1, 0));
    vector<int> prev(target+1, 0), curr(target+1, 0);

    
    // base cases:
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1; 

    for(int idx = 1; idx < n; idx++) {
        for(int sum = 0; sum <= target; sum++) {
            int pick = 0;
            if(arr[idx] <= sum) pick = prev[sum - arr[idx]];
            int notpick = prev[sum];
            curr[sum] = (pick + notpick)%MOD;
        }
        prev = curr;
    }
    return prev[target];
}
```