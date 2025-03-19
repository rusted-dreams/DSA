// problem - Fractional Knapsack
// link - https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Returns the maximum total value achievable in the knapsack.
        double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
            double totalVal = 0;
            int n = val.size();
            vector<pair<int, int>> items;
            
            // Combine values and weights into a pair for each item.
            for (int i = 0; i < n; i++) {
                items.push_back({val[i], wt[i]});
            }
            
            // Sort items by descending value-to-weight ratio.
            sort(items.begin(), items.end(), [](pair<int, int> a, pair<int, int> b) {
                return (double)a.first / a.second >= (double)b.first / b.second;
            });
            
            // Iterate through sorted items and add as much as possible.
            for (auto& it : items) {
                int price = it.first;
                int kg = it.second;
                
                // If no capacity is left, return the rounded total value.
                if (capacity == 0)
                    return round(totalVal * 1e6) / 1e6;
                
                // If the whole item can be added, update capacity and total value.
                if (kg <= capacity) {
                    capacity -= kg;
                    totalVal += price;
                } else {
                    // Otherwise, add the fractional value of the remaining capacity.
                    totalVal += ((double)price / kg) * capacity;
                    capacity = 0; // Knapsack is full.
                }
            }
            
            // Return the rounded total value (to 6 decimal places).
            return round(totalVal * 1e6) / 1e6;
        }
    };
    

int main() {
    Solution sol;
    
}