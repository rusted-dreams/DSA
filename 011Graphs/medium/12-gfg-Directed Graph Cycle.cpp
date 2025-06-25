// problem - Directed Graph Cycle

// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to detect cycle in directed graph
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;       // mark node as visited
        path[node] = 1;      // mark node in current DFS path

        for (int it : adj[node]) {
            if (!vis[it]) {   // if neighbor not visited, recurse
                if (dfs(it, adj, vis, path)) return true;
            }
            else if (path[it]) return true; // back edge found, cycle exists
        }

        path[node] = 0;      // backtrack: remove node from current path
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(V, 0);   // visited array
        vector<int> path(V, 0);  // recursion path tracker

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, path)) return true;
            }
        }
        return false;  // no cycle found
    }
};


int main() {
    Solution sol;

}