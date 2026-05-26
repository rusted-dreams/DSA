// problem - 787. Cheapest Flights Within K Stops
// link - https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Intuition:
    We need the cheapest price from src -> dst with at most k stops.

    Normal Dijkstra does not work directly because a path with fewer cost
    may use more stops than allowed.

    So along with node and cost, we also track:
        number of stops used

    We do a BFS-like traversal level by level where each level
    represents one more stop.

    Approach:
    - Build adjacency list: {neighbor, price}
    - Queue stores: {stops, {node, cost}}
    - If a cheaper cost to a node is found within allowed stops,
        update and push it.
    - Ignore paths exceeding k stops.
    */

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // {node -> {adjNode, price}}
        vector<vector<pair<int, int>>> adj(n);
        for(auto &flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }

        // Min cost to reach each node
        vector<int> minCost(n, 1e9);
        minCost[src] = 0;

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            // Can't exceed allowed stops
            if(stops > k)
                continue;
            for(auto &neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int flightCost = neighbor.second;
                int newCost = cost + flightCost;
                // Better cost found within stop limit
                if(newCost < minCost[nextNode]) {
                    minCost[nextNode] = newCost;
                    q.push({stops + 1, {nextNode, newCost}});
                }
            }
        }
        return (minCost[dst] == 1e9) ? -1 : minCost[dst];
    }
};

int main() {
    Solution sol;
    
}