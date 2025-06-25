// problem - khans algorithm (Topological sort using BFS)
// link - https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

/*
    Topological Sort using Kahn's Algorithm (BFS-based)
    ---------------------------------------------------
    Intuition:
    - In a Directed Acyclic Graph (DAG), topological ordering is a linear ordering
      of vertices such that for every directed edge u → v, u comes before v.

    Approach:
    1. Build the adjacency list and compute indegree (number of incoming edges) for each node.
    2. Push all nodes with indegree 0 into a queue (they have no dependencies).
    3. While the queue is not empty:
        - Pop a node from the queue and add it to the result.
        - Decrease the indegree of its neighbors by 1.
        - If any neighbor’s indegree becomes 0, push it to the queue.
    4. The result list will contain the topological order if the graph is a DAG.
    */

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int> indegree(V, 0);        // track incoming edges for each node
    vector<vector<int>> adj(V);        // adjacency list

    // build adjacency list and compute indegree
    for (auto& edge : edges) {
        indegree[edge[1]]++;           // edge[0] → edge[1], so edge[1] gets an incoming edge
        adj[edge[0]].push_back(edge[1]);
    }

    queue<int> q;
    // add all nodes with 0 indegree to the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);           // node added to topological order

        // reduce indegree of neighbors
        for (int it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it); // if indegree becomes 0, add to queue
        }
    }

    return ans; // if graph has a cycle, this won't include all nodes
}

int main() {

}