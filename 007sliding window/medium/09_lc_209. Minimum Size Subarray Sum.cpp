// problem - 209. Minimum Size Subarray Sum
// link - https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int len = INT_MAX;
    long sum = 0;
    int l = 0, r = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (sum >= target) {
            len = min(len, r - l + 1);
            sum -= nums[l];
            l++;
        }
        r++;
    }
    if (len == INT_MAX) return 0;
    return len;
}

int main() {

}