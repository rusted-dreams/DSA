// problem - BFS of graph
// link - https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> res;
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (!vis[node]) res.push_back(node);
            vis[node] = 1;
            for (int it : adj[node]) {
                if (!vis[it]) {
                    res.push_back(it);
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

}