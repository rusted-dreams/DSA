// problem - 1091. Shortest Path in Binary Matrix
// link - https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Since we are dealing with unit weights, a simple bfs will do the job.
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 1;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row == n - 1 && col == m - 1)return dist[row][col];
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nrow = row + i;
                    int ncol = col + j;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 0 && dist[nrow][ncol] == -1) {
                        q.push({nrow, ncol});
                        dist[nrow][ncol] = dist[row][col] + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
}