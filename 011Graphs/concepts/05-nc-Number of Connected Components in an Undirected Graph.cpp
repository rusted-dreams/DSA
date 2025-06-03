// problem - Number of Connected Components in an Undirected Graph
// link - https://neetcode.io/problems/count-connected-components

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node]) return;
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) dfs(it, adj, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res++;
                dfs(i, adj, vis);
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

}