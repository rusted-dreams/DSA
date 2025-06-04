// problem - 733. Flood Fill
// link - https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;

// using DFS:
class Solution {
    void dfs(int row, int col, vector<vector<int>>& image, int color, int org) {
        if (image[row][col] == color) return;

        image[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        int delRow[4] = { 1, 0, -1, 0 };
        int delCol[4] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == org) {
                dfs(nrow, ncol, image, color, org);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int org = image[sr][sc];
        dfs(sr, sc, image, color, org);

        return image;
    }
};


// using BFS:
// class Solution {
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int n = image.size();
//         int m = image[0].size();
//         int org = image[sr][sc];
//         if (org == color) return image;

//         queue<pair<int, int>> q;
//         q.push({ sr, sc });
//         image[sr][sc] = color;

//         while (!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             int delRow[4] = { 1, 0, -1, 0 };
//             int delCol[4] = { 0, 1, 0, -1 };
//             for (int i = 0; i < 4; i++) {
//                 int nrow = row + delRow[i];
//                 int ncol = col + delCol[i];

//                 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == org) {
//                     image[nrow][ncol] = color;
//                     q.push({ nrow, ncol });
//                 }
//             }
//         }
//         return image;
//     }
// };

int main() {
    Solution sol;

}