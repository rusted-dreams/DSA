# Array partition with minimum difference
problem link: https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

## Recursive with memoization:
```cpp
bool solve(int idx, int sum, vector<int>& nums, vector<vector<int>> &dp){
	if(sum == 0) return dp[idx][sum] = 1;
	if(idx == 0) return dp[idx][sum] = nums[0] == sum;

	if(dp[idx][sum] != -1) return dp[idx][sum];
	bool pick = false;
	if(nums[idx] <= sum) 
		pick = solve(idx-1, sum-nums[idx], nums, dp);
	bool notPick = solve(idx-1, sum, nums, dp);
	return dp[idx][sum] = pick || notPick; 
}

int minSubsetSumDifference(vector<int>& nums, int n){
	int total = accumulate(nums.begin(), nums.end(), 0);
	vector<vector<int>> dp(n, vector<int>(total+1, -1));
	for(int target = 0; target <= total/2; target++) {
		solve(n-1, target, nums, dp);
	}
	int res = INT_MAX;
	for(int i = 0; i<=total/2; i++) {
		if(dp[n-1][i] == 1) {
			int s1 = i;
			int s2 = total - s1;
			res = min(res, abs(s1-s2));
		}
	}
	return res;
}

```
---
## Tabulation:
```cpp
int minSubsetSumDifference(vector<int>& nums, int n){
	int total = accumulate(nums.begin(), nums.end(), 0);
	vector<vector<bool>> dp(n, vector<bool>(total+1, false));
	
	// basee case:
	for(int i=0; i<n; i++) {
		dp[i][0] = true;
	}
	dp[0][nums[0]] = true;

	for(int idx = 1; idx < n; idx++) {
		for(int target = 1; target <= total; target++) {
			bool pick = false;
			if(nums[idx] <= target) 
				pick = dp[idx-1][target-nums[idx]];
			bool notPick = dp[idx-1][target];
			dp[idx][target] = pick || notPick;
		}
	}

	int res = INT_MAX;
	for(int i = 0; i<=total/2; i++) {
		if(dp[n-1][i] == 1) {
			int s1 = i;
			int s2 = total - s1;
			res = min(res, abs(s1-s2));
		}
	}
	return res;
}
```

---

## Tabulation with space optimization:
```cpp
int minSubsetSumDifference(vector<int>& nums, int n)
{
	int total = accumulate(nums.begin(), nums.end(), 0);
	vector<bool> prev(total+1, false);
	vector<bool> curr(total+1, false);


	// basee case:
	prev[0]=curr[0] = true;
	prev[nums[0]] = true;

	for(int idx = 1; idx < n; idx++) {
		for(int target = 1; target <= total; target++) {
			bool pick = false;
			if(nums[idx] <= target) 
				pick = prev[target-nums[idx]];
			bool notPick = prev[target];
			curr[target] = pick || notPick;
		}
		prev = curr;
	}

	int res = INT_MAX;
	for(int i = 0; i<=total/2; i++) {
		if(prev[i] == 1) {
			int s1 = i;
			int s2 = total - s1;
			res = min(res, abs(s1-s2));
		}
	}
	return res;
}
```