// problem - Dijkstra Algorithm
// link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({ v, w });
        }

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({ 0, src });
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int v = it.first;
                int w = it.second;

                if (dis + w < dist[v]) {
                    pq.push({ dis + w, v });
                    dist[v] = dis + w;
                }
            }
        }
        return dist;
    }
};


int main() {
    Solution sol;

}