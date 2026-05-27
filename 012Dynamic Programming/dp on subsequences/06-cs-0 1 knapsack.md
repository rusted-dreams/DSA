# 0 1 Knapsack
problem link: https://www.naukri.com/code360/problems/0-1-knapsack_1072980

### Recursive:
```cpp
int solve(int idx, int cap, vector<int> &values, vector<int> &weights){
	if(idx == 0) {
		if(weights[0] <= cap) return values[0];
		return 0;
	}
	int pick = 0;
	if(weights[idx] <= cap) pick = values[idx] + solve(idx-1, cap-weights[idx], values, weights);
	int notPick = solve(idx-1, cap, values, weights);
	return max(pick, notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return solve(n-1, w, values, weights);
}
```

---
### recursive + memoization:
```cpp
int solve(int idx, int cap, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp){
	if(idx == 0) {
		if(weights[0] <= cap) return dp[idx][cap] = values[0];
		return 0;
	}
	if(dp[idx][cap] != -1) return dp[idx][cap];
	int pick = 0;
	if(weights[idx] <= cap) pick = values[idx] + solve(idx-1, cap-weights[idx], values, weights, dp);
	int notPick = solve(idx-1, cap, values, weights, dp);
	return dp[idx][cap] = max(pick, notPick);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return solve(n-1, w, values, weights, dp);
}
```
---

### Tabulation:
```cpp
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n, vector<int>(w+1, 0));

	// base cases:	
	for(int wt = weights[0]; wt <= w; wt++) dp[0][wt] = values[0];

	for(int idx = 1; idx < n; idx++) {
		for(int wt = 0; wt <= w; wt++) {
			int pick = 0;
			if(weights[idx] <= wt) 
				pick = values[idx] + dp[idx-1][wt-weights[idx]];
			int notpick = dp[idx-1][wt];
			dp[idx][wt] = max(pick, notpick);
		}
	}
	return dp[n-1][w];
}
```
---

### Tabulation with space optimization:
```cpp

```