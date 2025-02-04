// problem - 503. Next Greater Element II
// link - https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> res(nums.size());
    int n = nums.size();
    stack<int> st; // Stack to maintain elements in a decreasing order

    // Traverse the array twice (simulate circular array)
    for(int i = 2 * n - 1; i >= 0; i--) {
        // Modulo operation `i % n` helps in wrapping around the array
        while(!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        // Store the result only for the first pass (0 to n-1)
        if(i < n) {
            res[i] = st.empty() ? -1 : st.top();
        }

        // Push the current element (handling circular nature using modulo)
        st.push(nums[i % n]);
    }

    return res;
}


int main() {
    
}