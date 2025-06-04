// problem - 994. Rotting Oranges
// link - https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0; // count of fresh oranges

        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited grid to track processed cells
        queue<pair<int, int>> q; // BFS queue to store rotten oranges

        // Step 1: Initialize the queue with all initially rotten oranges
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    q.push({ row, col });
                    vis[row][col] = 1; // mark as visited
                }
                else if (grid[row][col] == 1) fresh++; // count fresh oranges
            }
        }

        if (!fresh) return 0; // all rotten already

        int count = 0; // time counter

        // Step 2: BFS to rot adjacent fresh oranges level-by-level
        while (!q.empty()) {
            int num = q.size(); // number of rotten oranges to process this minute
            count++; // increment time (minute passed)

            for (int i = 0; i < num; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // CHECK IN NEIGHBOURS
                int delRow[4] = { 0, 1, 0, -1 }; // direction vectors for 4 directions
                int delCol[4] = { 1, 0, -1, 0 };

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    // check bounds, if fresh orange, and unvisited
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && grid[nrow][ncol] == 1
                        && !vis[nrow][ncol]) {

                        vis[nrow][ncol] = 1; // mark as visited
                        fresh--;
                        q.push({ nrow, ncol }); // add to queue for next round
                    }
                }

                // if all fresh oranges are rotten, return time taken
                if (fresh == 0) return count;
            }
        }

        // if fresh oranges remain unrotted
        return fresh ? -1 : count;
    }
};


int main() {
    Solution sol;

}