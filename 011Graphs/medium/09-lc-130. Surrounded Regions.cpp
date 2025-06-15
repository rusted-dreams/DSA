// problem - 130. Surrounded Regions
// link - https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to mark all 'O's connected to border as "safe" (visited)
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;  // Mark current cell as safe

        // 4-directional movement: down, right, up, left
        int delRow[4] = { 1, 0, -1, 0 };
        int delCol[4] = { 0, 1, 0, -1 };

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Recursively mark connected 'O's as safe
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: DFS from all border 'O's to mark "safe" regions
        // Left and right borders
        for (int row = 0; row < n; row++) {
            if (board[row][0] == 'O') dfs(row, 0, board, vis);
            if (board[row][m - 1] == 'O') dfs(row, m - 1, board, vis);
        }

        // Top and bottom borders
        for (int col = 0; col < m; col++) {
            if (board[0][col] == 'O') dfs(0, col, board, vis);
            if (board[n - 1][col] == 'O') dfs(n - 1, col, board, vis);
        }

        // Step 2: Flip all unvisited 'O's (truly surrounded ones)
        for (int row = 1; row < n - 1; row++) {
            for (int col = 1; col < m - 1; col++) {
                if (board[row][col] == 'O' && !vis[row][col]) board[row][col] = 'X';
            }
        }
    }
};

// using bfs:
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int n = board.size();
//         int m = board[0].size();

//         // Track visited cells to identify 'O's connected to borders
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         queue<pair<int, int>> q;

//         // Step 1: Find all 'O's on borders and mark them as "safe" (visited)

//         // Check left and right borders
//         for (int row = 0; row < n; row++) {
//             if (board[row][0] == 'O') {
//                 q.push({ row, 0 });
//                 vis[row][0] = 1;
//             }
//             if (board[row][m - 1] == 'O') {
//                 q.push({ row, m - 1 });
//                 vis[row][m - 1] = 1;
//             }
//         }

//         // Check top and bottom borders
//         for (int col = 0; col < m; col++) {
//             if (board[0][col] == 'O') {
//                 q.push({ 0, col });
//                 vis[0][col] = 1;
//             }
//             if (board[n - 1][col] == 'O') {
//                 q.push({ n - 1, col });
//                 vis[n - 1][col] = 1;
//             }
//         }

//         // Step 2: BFS to mark all 'O's connected to border 'O's as "safe"
//         while (!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             // 4-directional movement: down, right, up, left
//             int delRow[4] = { 1, 0, -1, 0 };
//             int delCol[4] = { 0, 1, 0, -1 };

//             for (int i = 0; i < 4; i++) {
//                 int nrow = row + delRow[i];
//                 int ncol = col + delCol[i];

//                 // If neighbor is valid, is 'O', and not visited, mark it safe
//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
//                     && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
//                     q.push({ nrow, ncol });
//                     vis[nrow][ncol] = 1;
//                 }
//             }
//         }

//         // Step 3: Flip all 'O's that are NOT marked as safe (surrounded by 'X')
//         for (int row = 1; row < n - 1; row++) {
//             for (int col = 1; col < m - 1; col++) {
//                 if (board[row][col] == 'O' && !vis[row][col]) board[row][col] = 'X';
//             }
//         }
//     }
// };

int main() {
    Solution sol;

}