// problem - 907. Sum of Subarray Minimums
// link - https://leetcode.com/problems/sum-of-subarray-minimums/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the Previous Smaller Element (PSE) for each element in the array.
    // PSE[i] gives the index of the closest smaller element to the left of arr[i].
    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1); // Default to -1 (no smaller element to the left)
        stack<int> st; // Stack stores indices of elements

        for(int i = 0; i < n; i++) {
            // Remove elements from the stack that are greater than arr[i]
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            // If stack is empty, no smaller element exists; otherwise, get top index
            res[i] = st.empty() ? -1 : st.top();
            st.push(i); // Push current index to stack
        }
        return res;
    }

    // Function to find the Next Smaller Element (NSE) for each element in the array.
    // NSE[i] gives the index of the closest smaller element to the right of arr[i].
    vector<int> nge(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, n); // Default to n (no smaller element to the right)
        stack<int> st; // Stack stores indices of elements

        for(int i = n - 1; i >= 0; i--) { // Traverse from right to left
            // Remove elements from the stack that are >= arr[i]
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            // If stack is empty, no smaller element exists; otherwise, get top index
            res[i] = st.empty() ? n : st.top();
            st.push(i); // Push current index to stack
        }
        return res;
    }

    // Function to calculate the sum of the minimum values in all subarrays.
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int mod = (int) 1e9 + 7;

        // Get previous smaller element and next smaller element indices
        vector<int> psee = pse(arr);
        vector<int> ngee = nge(arr);

        for(int i = 0; i < n; i++) {
            // Contribution of arr[i] as the minimum of subarrays
            // Number of subarrays where arr[i] is the minimum:
            // (i - psee[i]) -> Left Contribution
            // (ngee[i] - i) -> Right Contribution
            // Total contribution = Left count * Right count * arr[i]
            int val = ((i - psee[i]) * (ngee[i] - i) * 1LL * arr[i]) % mod;
            res = (res + val) % mod; // Add contribution to result
        }

        return res;
    }

    // Brute force approach (TLE - O(N^2))
    // Calculates sum of minimum values in all subarrays using nested loops.
    // int sumSubarrayMins(vector<int>& arr) {
    //     int ans = 0; 
    //     int mod = (int) 1e9+7;
    //     for(int i = 0; i < arr.size(); i++) {
    //         int mini = arr[i];
    //         for(int j = i; j < arr.size(); j++) {
    //             mini = min(mini, arr[j]); // Update minimum in current subarray
    //             ans = (ans + mini) % mod; // Add min to result
    //         }
    //     }
    //     return ans;
    // }
};

int main() {
    
}