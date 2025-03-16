// problem - 162. Find Peak Element
// link - https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        else if (nums[0] > nums[1]) return 0;
        else if (nums[n - 1] > nums[n - 2]) return n - 1;

        int start = 1;
        int end = n - 2;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid]>nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1]) {
                start = mid + 1;
            }
            else if (nums[mid] < nums[mid - 1]) {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

}