// problem - 496. Next Greater Element I
//  link - https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size());
    unordered_map<int, int> mpp; // Hash map to store the next greater element for each number in nums2
    stack<int> st; // Stack to keep track of elements in a decreasing order

    // Traverse nums2 from right to left to determine the next greater element for each number
    for(int i = nums2.size() - 1; i >= 0; i--) {
        // Pop elements from the stack that are smaller or equal to the current element
        // Since they cannot be the next greater element for any previous numbers
        while(!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        
        // If the stack is empty, there is no greater element; otherwise, top of the stack is the next greater
        mpp[nums2[i]] = st.empty() ? -1 : st.top();
        
        // Push the current element onto the stack for future comparisons
        st.push(nums2[i]);
    }

    // Traverse nums1 to get the next greater element from the precomputed hash map
    for(int i = 0; i < nums1.size(); i++) {
        result[i] = mpp[nums1[i]];
    }

    return result;
}

int main() {
    
}