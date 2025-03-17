// problem - Median in a row-wise sorted Matrix
// link - https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Counts elements less than or equal to 'num' in the matrix
    // Returns total count across all rows
    int helper(vector<vector<int>>& mat, int num, int n, int m) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            // Binary search in each row to find count of elements <= num
            int start = 0;
            int end = m - 1;
            int mid;
            while (start <= end) {
                mid = start + (end - start) / 2;
                if (mat[i][mid] <= num) start = mid + 1;  // Move right if current element <= num
                else end = mid - 1;  // Move left otherwise
            }
            res += start;  // 'start' represents count of elements <= num in this row
        }
        return res;
    }
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size();        // Number of rows
        int m = mat[0].size();     // Number of columns

        // Find range of possible median values
        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < n; i++) {
            start = min(start, mat[i][0]);       // Minimum possible value (smallest first element)
            end = max(end, mat[i][m - 1]);         // Maximum possible value (largest last element)
        }

        int median = n * m / 2;        // Position of median in flattened matrix (0-indexed)
        int mid;

        // Binary search on the range of values
        while (start <= end) {
            mid = start + (end - start) / 2;
            int numLessEqualToMid = helper(mat, mid, n, m);  // Count elements <= mid

            if (numLessEqualToMid > median) end = mid - 1;  // Too many elements, reduce upper bound
            else start = mid + 1;  // Too few elements, increase lower bound
        }

        return start;  // 'start' converges to median value
    }
};

int main() {
    Solution sol;

}