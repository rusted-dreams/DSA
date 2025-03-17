// problem - 1901. Find a Peak Element II
// link - https://leetcode.com/problems/find-a-peak-element-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int start = 0;
        int end = m - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            int el = -1, ind = -1;
            // find the max element in that col:
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > el) {
                    el = mat[i][mid];
                    ind = i;
                }
            }

            // element to left of el:
            int left = mid > 0 ? mat[ind][mid - 1] : -1;
            // element to right of el:
            int right = mid < m - 1 ? mat[ind][mid + 1] : -1;

            // peak found:
            if (el > left && el > right) return { ind, mid };
            else if (left > el) {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return {};
    }
};

int main() {
    Solution sol;

}