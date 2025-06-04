// problem - 200. Number of Islands
// link - https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({ row, col });

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delRow[4] = { 1, 0, -1, 0 };
            int delCol[4] = { 0, 1, 0, -1 };
            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol] == '1'
                    && !vis[nrow][ncol]) {

                    q.push({ nrow, ncol });
                    vis[nrow][ncol] = 1;
                }

            }
        }
    }


    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        //dfs call for neighbours:
        int delRow[4] = { 1, 0, -1, 0 };
        int delCol[4] = { 0, -1, 0, 1 };
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == '1'
                && !vis[nrow][ncol]) {

                dfs(nrow, ncol, grid, vis);
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    ans++;
                    dfs(row, col, grid, vis);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

}