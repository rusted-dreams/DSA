#  Rod cutting problem
problem link: https://www.naukri.com/code360/problems/rod-cutting-problem_800284

- same as unbounded knapsack problem.
### recursive:
```cpp
int solve(int idx, int sum, vector<int>& price) {
	// base case:
	if(idx == 0) {
		return sum * price[0];
	}
	int pick = 0;
	if(idx+1 <= sum) pick = price[idx] + solve(idx, sum-idx-1, price);
	int notPick = solve(idx-1, sum, price);

	return max(pick, notPick); 
}
int cutRod(vector<int> &price, int n){
	return solve(n-1, n, price);
}
```
---
### recursive + memoization:
```cpp
int solve(int idx, int sum, vector<int>& price, vector<vector<int>>& dp) {
	// base case:
	if(idx == 0) {
		return sum * price[0];
	}
	if(dp[idx][sum] != -1) return dp[idx][sum];
	int pick = 0;
	if(idx+1 <= sum) pick = price[idx] + solve(idx, sum-idx-1, price, dp);
	int notPick = solve(idx-1, sum, price, dp);

	return dp[idx][sum] = max(pick, notPick); 
}
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return solve(n-1, n, price, dp);
}
```
---
### tabulation:
```cpp
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n, vector<int>(n+1, 0));
	// base case:
	for(int len = 0; len <= n; len++) {
		dp[0][len] = len*price[0];
	}
	for(int idx = 1; idx < n; idx++) {
		for(int len = 0; len <= n; len++) {
			int pick = 0;
			if(idx+1 <= len) pick = price[idx] + dp[idx][len-idx-1];
			int notPick = dp[idx-1][len];
			dp[idx][len] = max(pick, notPick);
		}
	}
	return dp[n-1][n];
}
```
---
### tabulation + space optimization:
```cpp
int cutRod(vector<int> &price, int n){
	// vector<vector<int>> dp(n, vector<int>(n+1, 0));
	vector<int> prev(n+1, 0), curr(n+1, 0);
	// base case:
	for(int len = 0; len <= n; len++) {
		prev[len] = len*price[0];
	}
	for(int idx = 1; idx < n; idx++) {
		for(int len = 0; len <= n; len++) {
			int pick = 0;
			if(idx+1 <= len) pick = price[idx] + curr[len-idx-1];
			int notPick = prev[len];
			curr[len] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[n];
}
```