// problem - Topological sort

// link - https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS helper to perform post-order traversal and fill stack
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;  // mark current node as visited
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);  // push after visiting all neighbors (post-order)
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);       // visited array
        stack<int> st;               // stack to store topological order
        vector<vector<int>> adj(V); // adjacency list

        // build adjacency list from edges
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // extract topological order from stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


int main() {
    Solution sol;

}