// link https://leetcode.com/problems/two-sum/description/
// lc 1. Two Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int second = target-nums[i];
            if(mp.find(second) != mp.end()){
                return {mp[second], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    
}
