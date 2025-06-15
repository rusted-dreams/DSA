// problem - 1020. Number of Enclaves
// link - https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 0;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = { 1, 0, -1, 0 };
        int delCol[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int col = 0; col < m; col++) {
            if (grid[0][col] == 1) {
                dfs(0, col, grid);
            }
            if (grid[n - 1][col] == 1) dfs(n - 1, col, grid);
        }
        for (int row = 0; row < n; row++) {
            if (grid[row][0] == 1) dfs(row, 0, grid);
            if (grid[row][m - 1] == 1) dfs(row, m - 1, grid);
        }

        for (int row = 1; row < n - 1; row++) {
            for (int col = 1; col < m - 1; col++) {
                if (grid[row][col] == 1) res++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

}