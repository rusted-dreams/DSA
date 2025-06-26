// problem - Shortest Path in Undirected Graph
// link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dist(adj.size(), -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int it : adj[node]) {
                if (dist[it] == -1) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;

}