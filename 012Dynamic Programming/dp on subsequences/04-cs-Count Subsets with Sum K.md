# Count Subsets with Sum K
problem link: https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532

## recursive(TLE)
```cpp
int solve(int idx, int sum, vector<int>& arr) {
	int mod = 1e9+7;
	if(idx == 0) {
		if(sum == 0 && arr[0] == 0) return 2;
		if(sum == 0 || arr[0] == sum) return 1;
		return 0;
	}

	int pick = 0;
	if(arr[idx] <= sum) 
		pick = solve(idx-1, sum-arr[idx], arr);
	int notPick = solve(idx-1, sum, arr);

	return (pick + notPick)%mod;
}
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	return solve(n-1, k, arr);
}
```
---

## Recursive + memoization:
```cpp
int solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
	int mod = 1e9+7;
	if(idx == 0) {
		if(sum == 0 && arr[0] == 0) return 2;
		if(sum == 0 || sum == arr[0]) return 1;
		return 0;
	}
	
	if(dp[idx][sum] != -1) return dp[idx][sum];
	int pick = 0;
	if(arr[idx] <= sum) 
		pick = solve(idx-1, sum-arr[idx], arr, dp);
	int notPick = solve(idx-1, sum, arr, dp);

	return dp[idx][sum] = (pick + notPick)%mod;
}
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return solve(n-1, k, arr, dp);
}

```
## tabulation:
```cpp
int findWays(vector<int>& arr, int k){
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));

    // base cases
    if(arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if(arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;

    for(int idx = 1; idx < n; idx++) {
        for(int target = 0; target <= k; target++) {
            long long pick = 0;
            if(arr[idx] <= target)
                pick = dp[idx - 1][target - arr[idx]];
            long long notPick = dp[idx - 1][target];
            dp[idx][target] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][k];
}
```
---
## Tabulation + space optimization:
```cpp
int findWays(vector<int>& arr, int k){
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<long long> prev(k+1, 0) , curr(k+1, 0);

    // base cases
    if(arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= k)
        prev[arr[0]] = 1;

    for(int idx = 1; idx < n; idx++) {
        for(int target = 0; target <= k; target++) {
            long long pick = 0;
            if(arr[idx] <= target)
                pick = prev[target - arr[idx]];
            long long notPick = prev[target];
           curr[target] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    return prev[k];
}
```