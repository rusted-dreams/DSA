// problem - 542. 01 Matrix
// link - https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0)); // stores final distances
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into the queue (they're the BFS sources)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (mat[row][col] == 0) q.push({ row, col });
            }
        }

        int dist = 0;

        // Step 2: Multi-source BFS to compute minimum distances to 0
        while (!q.empty()) {
            int level = q.size();
            dist++; // each level in BFS represents distance increment
            for (int i = 0; i < level; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // 4-directional movement
                int delRow[4] = { 0, 0, -1, 1 };
                int delCol[4] = { 1, -1, 0, 0 };

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    // Valid cell, unvisited, and originally 1 in input
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && mat[nrow][ncol] == 1
                        && res[nrow][ncol] == 0) {

                        res[nrow][ncol] = dist; // update distance
                        q.push({ nrow, ncol });   // continue BFS from here
                    }
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

}