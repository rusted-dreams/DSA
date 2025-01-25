// problem - 78. Subsets
// link - https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int totalSubsets = 1 << n;
    for (int i = 0; i < (totalSubsets); i++) {
        vector<int> subset;
        int num = i;
        for (int j = 0; j < nums.size(); j++) {
            if (num >> j & 1) subset.push_back(nums[j]);
        }
        ans.push_back(subset);
    }
    return ans;
}

int main() {

}