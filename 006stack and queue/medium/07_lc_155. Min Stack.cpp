// problem - 155. Min Stack
// link - https://leetcode.com/problems/min-stack/

#include <bits/stdc++.h>
using namespace std;


// Approach 1: Optimized Space using a Single Stack and Encoding Trick
// Notes:
// - This approach is **space-optimized**, as it does not store an extra min value for each element.
// - It uses an **encoding trick** to track the previous minimum when a new minimum is pushed.
// - The encoding formula is: `stored_value = 2 * new_min - old_min`
// - The decoding formula is: `old_min = 2 * new_min - encoded_value`
// - However, this approach is **less intuitive** and requires understanding the encoding logic.
// - Works efficiently with **O(1) push, pop, top, and getMin** operations.
class MinStack {
public:
    stack<long> st; // Stack to store elements, potentially encoded
    long mini; // Variable to track the minimum element

    MinStack() {}

    void push(long val) {
        if (st.empty()) {
            // First element, directly store it and set mini
            mini = val;
            st.push(val);
        }
        else if (val >= mini) {
            // Normal push if val is greater than or equal to mini
            st.push(val);
        }
        else {
            /**
             * Encoding Trick:
             * - Instead of pushing val directly, push a special encoded value.
             * - The encoded value is calculated as: `2 * val - mini`
             * - Why?
             *   - This ensures the stored value is always less than the new mini.
             *   - The previous mini can be recovered during pop.
             */
            st.push(2 * val - mini);
            mini = val; // Update mini to new minimum
        }
    }

    void pop() {
        if (st.top() >= mini) {
            // Normal pop if top is not an encoded value
            st.pop();
        }
        else {
            /**
             * Decoding Trick:
             * - The current mini is removed, and we need to restore the previous mini.
             * - Previous mini can be retrieved using:
             *   `previous_mini = 2 * current_mini - encoded_value`
             * - This works because during push we stored: `encoded_value = 2 * val - mini`
             * - Rearranging gives: `mini = 2 * mini - st.top()`
             */
            mini = 2 * mini - st.top();
            st.pop();
        }
    }

    int top() {
        // If top is an encoded value, return mini; otherwise, return normal top
        return st.top() >= mini ? st.top() : mini;
    }

    int getMin() {
        return mini; // Directly return the minimum element
    }
};



// // Approach 2: More Intuitive, but Uses Extra Space
// // Notes:
// // - This approach is **more intuitive** because it explicitly tracks the minimum with each push.
// // - Uses **O(N) space** because each element is stored along with its min value.
// // - **O(1) push, pop, top, and getMin** operations.
// // - Easier to understand compared to the encoding trick in Approach 1.
// class MinStack {
// public:
//     stack<pair<int, int>> st; // Stack stores (element, min_so_far) pairs

//     MinStack() {}

//     void push(int val) {
//         // Store the value along with the minimum value at this point
//         int mini = st.empty() ? val : st.top().second;
//         st.push({val, min(mini, val)});
//     }

//     void pop() {
//         st.pop(); // Normal stack pop
//     }

//     int top() {
//         return st.top().first; // Retrieve the top element
//     }

//     int getMin() {
//         return st.top().second; // Retrieve the current minimum
//     }
// };





int main() {
    
}