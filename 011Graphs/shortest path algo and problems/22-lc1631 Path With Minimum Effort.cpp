// problem - 1631. Path With Minimum Effort
// link - https://leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Intuition:
    We want a path where the maximum height difference between consecutive cells
    is as small as possible.

    Instead of storing "distance so far" like normal Dijkstra,
    we store:
        effort = maximum edge weight seen in the path till now

    For every move:
        newEffort = max(current effort, current height difference)

    If we can reach a cell with a smaller maximum effort,
    we update it.

    Approach:
    - Use Dijkstra because we need the minimum possible effort first.
    - Min heap stores: {effort, {row, col}}
    - dist[r][c] = minimum effort needed to reach that cell.
    - First time we pop destination from heap, that's the answer.
    */

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, -1, 0, 1};

        while(!pq.empty()) {
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            // Destination reached with minimum possible effort
            if(row == n - 1 && col == m - 1)
                return effort;

            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {

                    // Path effort = maximum edge cost in the path
                    int newEffort = max(
                        effort,
                        abs(heights[row][col] - heights[nrow][ncol])
                    );

                    // Found a better path
                    if(newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};

int main() {
    Solution sol;
    
}