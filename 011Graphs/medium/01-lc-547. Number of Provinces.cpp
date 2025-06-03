// problem - 547. Number of Provinces
// link - https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node]) return;
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) dfs(it, adj, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] && i != j) adj[i].push_back(j);
            }
        }
        vector<int> vis(n, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res++;
                dfs(i, adj, vis);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

}