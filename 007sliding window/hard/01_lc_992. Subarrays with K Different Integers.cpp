// problem - 992. Subarrays with K Different Integers
// link - https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <bits/stdc++.h>
using namespace std;


// problem can be reduced to find the no. of subarrays with k distinct chars
// find no. of sub arr with distinct chars = k or less
// find no. of sub arr with distinct chars = k-1 or less
// the ans is the diff of the two nos.
int helper(vector<int>& nums, int k) {
    if (k < 0) return 0;
    int l = 0, r = 0, count = 0;
    unordered_map<int, int> freq;
    while (r < nums.size()) {
        freq[nums[r]]++;
        while (freq.size() > k) {
            freq[nums[l]]--;
            if (freq[nums[l]] == 0) freq.erase(nums[l]);
            l++;
        }
        if (freq.size() <= k) {
            count += r - l + 1;
        }
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int cnt1 = helper(nums, k);
    int cnt2 = helper(nums, k - 1);
    return cnt1 - cnt2;
}
int main() {

}