// problem - 15-gfg-cycle detection in directed graph using BFS(KHANS ALOGRITHM)
// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<vector<int>>& edges) {
    vector<int> inDegree(V, 0);
    vector<vector<int>> adj(V);
    for (auto& it : edges) {
        inDegree[it[1]]++;
        adj[it[0]].push_back(it[1]);
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0)q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        count++;
        q.pop();
        for (int it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) q.push(it);
        }
    }
    return count == V ? false : true;
}

int main() {

}