// problem - Nearest Smaller Element
// link - https://www.interviewbit.com/problems/nearest-smaller-element/

#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> res(A.size());
    int n = A.size();
    stack<int> st; // Stack to maintain elements in increasing order

    // Traverse the array from left to right
    for(int i = 0; i < n; i++) {
        // Remove elements from the stack that are greater than or equal to the current element
        // Because they cannot be the previous smaller element
        while(!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        // If stack is empty, no smaller element exists; otherwise, top of stack is the previous smaller
        res[i] = st.empty() ? -1 : st.top();

        // Push the current element onto the stack for future comparisons
        st.push(A[i]);
    }

    return res;
}

int main() {
    
}