// problem - Shortest path in Directed Acyclic Graph
// link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
private:
    // Helper function to perform DFS and store nodes in topological order
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<int>& vis, stack<int>& st) {
        vis[node] = 1; // mark the node as visited
        for (auto& it : graph[node]) {
            if (!vis[it.first])
                dfs(it.first, graph, vis, st); // visit unvisited neighbors
        }
        st.push(node); // push node to stack after all its neighbors are processed
    }

public:
    // Function to find shortest paths in a DAG from node 0
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list with weights
        vector<vector<pair<int, int>>> graph(V);
        for (auto& edge : edges) {
            // edge = {u, v, wt} means u -> v with weight wt
            graph[edge[0]].push_back({ edge[1], edge[2] });
        }

        // Step 2: Topological Sort using DFS
        stack<int> st;         // stack to store topological order
        vector<int> vis(V, 0); // visited array
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, graph, vis, st);
        }

        // Step 3: Initialize distances; distance to source (0) is 0, rest is infinity
        vector<int> dist(V, 1e9);
        dist[0] = 0;

        // Step 4: Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // Relax all adjacent edges
            for (auto& it : graph[node]) {
                int adjNode = it.first;
                int weight = it.second;
                if (dist[node] != 1e9 && dist[node] + weight < dist[adjNode]) {
                    dist[adjNode] = dist[node] + weight;
                }
            }
        }

        // Step 5: Replace all unreachable nodes' distances (still 1e9) with -1
        replace(dist.begin(), dist.end(), (int)1e9, -1);
        return dist;
    }
};


int main() {
    Solution sol;

}