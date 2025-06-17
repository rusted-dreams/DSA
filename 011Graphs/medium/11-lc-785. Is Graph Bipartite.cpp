// problem - 785. Is Graph Bipartite?
// link - https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Helper DFS function to try coloring the graph
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = color; // Assign color to the current node
        for (int it : graph[node]) {
            if (vis[it] == -1) {
                // If the neighbor is unvisited, recursively assign alternate color
                bool chk = dfs(it, !color, graph, vis);
                if (chk == false) return false; // Conflict found
            }
            else if (vis[it] == color) return false; // Adjacent node has same color
        }
        return true; // No conflict found
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1); // -1 means unvisited

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                // Start DFS from unvisited node
                bool check = dfs(i, 0, graph, vis);
                if (check == false) return false; // Graph is not bipartite
            }
        }
        return true; // All components are bipartite
    }
};


int main() {
    Solution sol;

}