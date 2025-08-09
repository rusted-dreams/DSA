// problem - 78. Subsets
// link - https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, vector<int> subset, vector<int>& nums, vector<vector<int>>& res) {
        int n = nums.size();
        if (i >= n) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(i + 1, subset, nums, res);
        subset.pop_back();
        helper(i + 1, subset, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(0, subset, nums, res);
        return res;
    }
};

int main() {
    Solution sol;

}