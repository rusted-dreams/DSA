// problem - Undirected Graph Cycle
// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// Approach: DFS with parent tracking to detect cycle in an undirected graph

class Solution {
    // DFS function to detect cycle from a given source node
    bool dfs(int src, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        for (int adjNode : adj[src]) {
            if (!vis[adjNode]) {
                int cycle = dfs(adjNode, src, adj, vis);
                if (cycle) return true;
            }
            else if (parent != adjNode) return true; // visited & not parent → cycle
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0); // visited array
        vector<vector<int>> adj(V); // adjacency list

        // build the undirected graph
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool ans = dfs(i, -1, adj, vis); // DFS from unvisited node
                if (ans) return true; // cycle found
            }
        }
        return false; // no cycle in any component
    }
};


int main() {
    Solution sol;

}