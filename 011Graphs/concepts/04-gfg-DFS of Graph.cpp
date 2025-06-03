// problem - DFS of Graph
// link - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // vector<int> res(n);
    void doDfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& res, int node) {
        if (vis[node]) return;
        res.push_back(node);
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                doDfs(adj, vis, res, it);
            }
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        vector<int> res;
        doDfs(adj, vis, res, 0);
        return res;

    }
};

int main() {
    Solution sol;

}