//problem -84. Largest Rectangle in Histogram
// link - https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Previous Smaller Element (PSE): Finds index of the closest smaller element on the left.
    vector<int> getPse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), -1); // Default to -1 (no smaller element).
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop(); // Remove elements >= current.
            res[i] = st.empty() ? -1 : st.top(); // Store index of smaller element.
            st.push(i);
        }
        return res;
    }

    // Next Smaller Element (NSE): Finds index of the closest smaller element on the right.
    vector<int> getNse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), arr.size()); // Default to size (no smaller element).
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop(); // Remove elements >= current.
            res[i] = st.empty() ? arr.size() : st.top(); // Store index of smaller element.
            st.push(i);
        }
        return res;
    }

    // Largest Rectangle in Histogram: Uses PSE & NSE to calculate max area.
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = getPse(heights); // Get left boundary.
        vector<int> nse = getNse(heights); // Get right boundary.
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            int area = (nse[i] - pse[i] - 1) * heights[i]; // Width = right - left - 1.
            maxArea = max(maxArea, area); // Update max area.
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
     
}