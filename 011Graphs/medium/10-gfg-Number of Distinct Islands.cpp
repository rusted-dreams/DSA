// problem - Number of Distinct Islands
// link - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // DFS to explore the island and record its shape using relative coordinates
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int brow, int bcol, vector<pair<int, int>>& island) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        // Store relative position from base cell
        island.push_back({ brow - row, bcol - col });

        // 4-directional movement
        int delRow[4] = { 1, 0, -1, 0 };
        int delCol[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Continue DFS if within bounds and unvisited land
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis, brow, bcol, island);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited matrix
        set<vector<pair<int, int>>> st;  // Stores unique island shapes

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // Start DFS if unvisited land cell
                if (grid[row][col] == 1 && !vis[row][col]) {
                    vector<pair<int, int>> island;  // Stores shape of current island
                    dfs(row, col, grid, vis, row, col, island);
                    st.insert(island);  // Add shape to set
                }
            }
        }
        return st.size();  // Count of distinct island shapes
    }
};


int main() {
    Solution sol;

}