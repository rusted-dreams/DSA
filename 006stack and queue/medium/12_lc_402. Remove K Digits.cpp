// problem - 402. Remove K Digits
// link - https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;  // Monotonic stack to maintain increasing order

        // Iterate through the digits of the number
        for (int i = 0; i < num.size(); i++) {
            // Remove larger digits from stack if a smaller digit appears (greedy approach)
            while (!st.empty() && num[i] < st.top() && k) {
                k--;
                st.pop();
            }
            st.push(num[i]);  // Push current digit into the stack
        }

        // If k digits are still left to be removed, remove from the top of the stack
        while (k) {
            st.pop();
            k--;
        }

        string res = "";
        // Construct the final number from the stack
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        if (res == "") return "0";  // Edge case: If no digits left, return "0"

        cout << res;
        // Remove leading zeros by popping from the back
        while (res.size() > 1 && res.back() == '0') res.pop_back();

        // Reverse to get the correct order
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;

}