// problem - Undirected Graph Cycle
// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// Approach: BFS with parent tracking to detect cycle in an undirected graph

class Solution {
    // BFS function to detect cycle from a given source node
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q; // {node, parent}
        q.push({ src, -1 });

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            for (int adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({ adjNode, node });
                }
                else if (parent != adjNode) return true; // visited & not parent → cycle
            }
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
                vis[i] = 1;
                bool ans = detect(i, adj, vis); // BFS from unvisited node
                if (ans) return true; // cycle found
            }
        }
        return false; // no cycle in any component
    }
};


int main() {
    Solution sol;

}