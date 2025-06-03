#include <bits/stdc++.h>
using namespace std;

// using adjacency matrix:
void matrix(int n, int m) {
    // graph: S.C. O(n^2)
    int matrix[n + 1][n + 1]; // for 1 based indexed nodes.
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
}

// using list/vectors:
vector<vector<int>> graph(int n, int m) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}


int main() {

    int n, m;
    cin >> n >> m;

}