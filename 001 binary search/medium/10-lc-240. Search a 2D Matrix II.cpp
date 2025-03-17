// problem - 240. Search a 2D Matrix II
// link - https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int row = 0;
            int col = m-1;
            while(row < n && col >=0) {
                if(matrix[row][col] == target) return true;
                else if(target < matrix[row][col])col--;
                else row++;
            }
            return false;
        }
    };

int main() {
    Solution sol;
    
}