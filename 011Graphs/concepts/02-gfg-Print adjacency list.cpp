// problem - Print adjacency list
// link - https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto it : edges) {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        return adj;
    }
};

int main() {
    Solution sol;

}