// problem - 1248. Count Number of Nice Subarrays
// link - https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

// almost same as problem 05:
int helper(vector<int>& nums, int k) {
    if (k < 0) return 0;
    int l = 0, r = 0, oddCount = 0, cnt = 0;
    while (r < nums.size()) {
        if (nums[r] % 2 != 0) oddCount++;
        while (oddCount > k) {
            if (nums[l] % 2 != 0) oddCount--;
            l++;
        }
        if (oddCount <= k) cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    int count1 = helper(nums, k);
    int count2 = helper(nums, k - 1);
    return count1 - count2;
}

int main() {

}