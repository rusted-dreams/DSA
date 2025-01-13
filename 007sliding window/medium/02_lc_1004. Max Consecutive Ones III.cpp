// links - https://leetcode.com/problems/max-consecutive-ones-iii/ , 
// problem - 1004. Max Consecutive Ones III

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    int l = 0, r = 0, zeros = 0;
    int maxLength = 0;
    while (r < nums.size()) {
        if (nums[r] == 0) zeros++;
        if (zeros > k) {
            if (nums[l] == 0) zeros--;
            l++;
        }
        if (zeros <= k) maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}

int main() {

}