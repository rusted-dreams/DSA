# Unbounded Knapsack
problem link: https://www.naukri.com/code360/problems/unbounded-knapsack_1215029

### Recursive:
```cpp
int solve(int idx, int cap, vector<int> &values, vector<int> &weights){
	if(idx == 0) {
		return (cap/weights[0])*values[0];
	}
	int pick = 0;
	if(weights[idx] <= cap) pick = values[idx] + solve(idx, cap-weights[idx], values, weights);
	int notPick = solve(idx-1, cap, values, weights);
	return max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
	return solve(n-1, w, profit, weight);    
}
```
---
### Recursive + memoization:
```cpp
int solve(int idx, int cap, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp){
	if(idx == 0) {
		return dp[idx][cap] = (cap/weights[0])*values[0];
	}
	if(dp[idx][cap] != -1) return dp[idx][cap];
	int pick = 0;
	if(weights[idx] <= cap) pick = values[idx] + solve(idx, cap-weights[idx], values, weights, dp);
	int notPick = solve(idx-1, cap, values, weights, dp);
	return dp[idx][cap] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return solve(n-1, w, profit, weight, dp);    
}
```
---
### Tabulation:
```cpp
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, 0));

	// base cases:
	for(int cap = 0; cap <= w; cap++) {
    	dp[0][cap] = (cap / weight[0]) * profit[0];
	}

	for(int idx = 1; idx < n; idx++) {
		for(int cap= 0; cap <= w; cap++) {
			int pick = 0;
			if(weight[idx] <= cap) pick = profit[idx] + dp[idx][cap-weight[idx]];
			int notPick = dp[idx-1][cap];
			dp[idx][cap] = max(pick, notPick);
		}
	}
	return dp[n-1][w];
}
```
---
### tabulation + space optimization:
```cpp
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1, 0), curr(w+1, 0);

	// base cases:
	for(int cap = 0; cap <= w; cap++) {
    	prev[cap] = (cap / weight[0]) * profit[0];
	}

	for(int idx = 1; idx < n; idx++) {
		for(int cap= 0; cap <= w; cap++) {
			int pick = 0;
			if(weight[idx] <= cap) pick = profit[idx] + curr[cap-weight[idx]];
			int notPick = prev[cap];
			curr[cap] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[w];
}

```