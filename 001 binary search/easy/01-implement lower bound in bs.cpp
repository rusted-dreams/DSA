// problem - Implement Lower Bound
// link - https://www.geeksforgeeks.org/problems/implement-lower-bound/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};


int main() {
    Solution sol;

}