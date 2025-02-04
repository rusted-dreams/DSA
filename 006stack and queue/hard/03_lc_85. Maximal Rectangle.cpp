// problem - 85. Maximal Rectangle
// link - https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    🔹 **Prerequisites:**
    - **Stack-based Monotonic Decreasing Approach** (Next/Previous Smaller Element).
    - **Largest Rectangle in Histogram** (LRH) problem.
    - **Binary Matrix to Histogram Conversion** (Height accumulation for '1's).

    🔹 **Approach:**
    1️⃣ Convert the **binary matrix** into a **height histogram**.
    2️⃣ For each row, treat it as a **histogram** and find the **max rectangular area**.
    3️⃣ Use **Previous Smaller Element (PSE)** & **Next Smaller Element (NSE)** to compute widths efficiently.
    4️⃣ Compute **max rectangle area** using the LRH formula:  
        **Area = height * (NSE - PSE - 1)**
    */

    // **Previous Smaller Element (PSE)**: Finds index of closest smaller element on the left.
    vector<int> getPse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), -1); // Default: No smaller element (-1).
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop(); // Remove elements >= current.
            res[i] = st.empty() ? -1 : st.top(); // Store index of smaller element.
            st.push(i);
        }
        return res;
    }

    // **Next Smaller Element (NSE)**: Finds index of closest smaller element on the right.
    vector<int> getNse(vector<int>& arr) {
        stack<int> st;
        vector<int> res(arr.size(), arr.size()); // Default: No smaller element (size of array).
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
                st.pop(); // Remove elements >= current.
            res[i] = st.empty() ? arr.size() : st.top(); // Store index of smaller element.
            st.push(i);
        }
        return res;
    }

    // **Largest Rectangle in Histogram (LRH)**: Uses PSE & NSE to calculate max area.
    int getArea(vector<int>& heights) {
        vector<int> pse = getPse(heights); // Get left boundary.
        vector<int> nse = getNse(heights); // Get right boundary.
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            int width = nse[i] - pse[i] - 1; // Width = right - left - 1.
            int area = width * heights[i]; // Area = height * width.
            maxArea = max(maxArea, area); // Update max area.
        }
        return maxArea;
    }

    // **Maximal Rectangle in a Binary Matrix**: Uses histogram approach.
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefixMatrix(m, vector<int>(n, 0));

        // **Step 1: Convert Binary Matrix to Histogram**
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == '1') prefixMatrix[0][j] = 1; // First row initialization.
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') 
                    prefixMatrix[i][j] = prefixMatrix[i-1][j] + 1; // Build heights.
            }
        }

        // **Step 2: Find Largest Rectangle for each Histogram Row**
        for(auto& row : prefixMatrix) {
            int area = getArea(row);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};


int main() {
    Solution sol;
    
}