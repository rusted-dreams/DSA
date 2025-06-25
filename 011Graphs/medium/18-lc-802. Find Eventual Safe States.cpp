// problem - 802. Find Eventual Safe States
// link - https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

// using dfs cycle detection in directed graph:
class Solution {
private:
    // DFS to detect cycles and mark unsafe nodes
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;        // mark as visited
        path[node] = 1;       // mark as part of current path (recursion stack)

        for (int i : graph[node]) {
            if (!vis[i]) {
                if (dfs(i, graph, vis, path) == false) return false; // cycle found
            }
            else if (vis[i] && path[i]) return false; // back edge = cycle
        }

        path[node] = 0;       // backtrack: remove from current path
        return true;          // no cycle from this node
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);     // visited marker
        vector<int> path(n, 0);    // current path marker (unsafe if still marked after DFS)

        // DFS on all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, graph, vis, path);
        }

        vector<int> safeStates;
        // Nodes not part of a cycle (path[i] == 0) are safe
        for (int i = 0; i < n; i++) {
            if (!path[i]) safeStates.push_back(i);
        }
        return safeStates;
    }
};


// // Using BFS (Kahn's Algorithm) to find eventual safe nodes
// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> adjRev(n);  // reversed graph: store incoming edges
//         vector<int> inDegree(n, 0);     // indegree = original outdegree of node

//         // Reverse the graph and calculate original outdegree for each node
//         for (int i = 0; i < n; i++) {
//             inDegree[i] = graph[i].size();  // outdegree in original graph
//             for (int j : graph[i]) {
//                 adjRev[j].push_back(i);     // reverse the edge
//             }
//         }

//         queue<int> q;
//         // Nodes with 0 outdegree are terminal → push them into queue
//         for (int i = 0; i < n; i++) {
//             if (inDegree[i] == 0) q.push(i);
//         }

//         vector<int> safeStates;
//         // Standard Kahn's algorithm on reversed graph
//         while (!q.empty()) {
//             int node = q.front();
//             safeStates.push_back(node);  // node is safe
//             q.pop();
//             for (int it : adjRev[node]) {
//                 inDegree[it]--;          // remove edge to current node
//                 if (inDegree[it] == 0) q.push(it);  // becomes terminal, hence safe
//             }
//         }
//         sort(safeStates.begin(), safeStates.end());  // sort as required

//         return safeStates;
//     }
// };





int main() {
    Solution sol;

}