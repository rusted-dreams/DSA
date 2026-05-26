// problem - Shortest Path in Weighted Undirected Graph
// link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // dijkstra's algo will give the min dist.
    // we will keep a parent array to form the path later.
    // TC - O(E log V) + O(V) for forming the path.
    // hence can be solved using dijkstra's algo and parent tracking.
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(n+1, 1e9);
        vector<int>parent(n+1, -1);
        pq.push({0, 1});
        dist[1] = 0;
        parent[1] = 1;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            if(dis > dist[node]) continue;
            for(auto &edge : adj[node]){
                int v = edge.first;
                int wt = edge.second;
                if(dis + wt < dist[v]){
                    pq.push({dis+wt, v});
                    parent[v] = node;
                    dist[v] = dis+wt;
                }
            }
        }
        // lets form the path now.
        if(parent[n] == -1) return {-1};
        vector<int> ans;
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1); // start node
        ans.push_back(dist[n]); // total distance
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    
}