// problem - Alien Dictionary
// link - https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        int n = words.size();

        // Directed graph
        vector<vector<int>> adj(26);

        // inDegree[i] = number of incoming edges to character 'a' + i
        // Initialized to -1 (unvisited), set to 0 for characters that appear in words
        vector<int> inDegree(26, -1);

        // Step 1: Mark all characters that are present in the words
        for (auto word : words) {
            for (char ch : word) {
                inDegree[ch - 'a'] = 0;
            }
        }

        // Step 2: Build graph by comparing adjacent words
        for (int i = 0; i < n - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            int j = 0;

            // Find the first position where the two words differ
            for (j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    // Add an edge from w1[j] to w2[j] (w1[j] comes before w2[j])
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    inDegree[w2[j] - 'a']++;
                    break;
                }
            }

            // Special case: invalid order (e.g., ["abc", "ab"])
            if (j == w2.size() && w1.size() > w2.size()) {
                return "";
            }
        }

        // Step 3: Perform topological sort using Kahn's algorithm (BFS)
        queue<int> q;
        int count = 0;  // Number of distinct characters involved

        // Push all nodes with in-degree 0 (no prerequisites)
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] > -1) count++;         // Only count characters that appear
            if (inDegree[i] == 0) q.push(i);       // Start with independent nodes
        }

        string topo;  // Result string to store character order

        while (!q.empty()) {
            int ch = q.front();
            q.pop();
            topo += char(ch + 'a');

            // Decrease in-degree of neighbors, add to queue if it becomes 0
            for (int neighbor : adj[ch]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all characters were used in topological order, return result
        // Otherwise, a cycle exists or invalid input
        return (topo.size() == count) ? topo : "";
    }
};


int main() {
    Solution sol;

}