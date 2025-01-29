// problem - Prefix to Infix Conversion
// link - https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

#include <bits/stdc++.h>
using namespace std;

string preToInfix(string exp) {
    // Initialize an empty stack to store intermediate results
    stack<string> st;

    // Iterate through the prefix expression from right to left
    for (int i = exp.size() - 1; i >= 0; i--) {
        // If the current character is an operand (a-z, A-Z, or 0-9),
        // push it onto the stack as a string.
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9')) st.push(string(1, exp[i]));
        
        
        // If the current character is an operator (+, -, *, /, etc.),
        // pop the top two elements from the stack.
        else {
            // Pop the first operand (top of the stack).
            string top1 = st.top();
            st.pop();

            // Pop the second operand (next top of the stack).
            string top2 = st.top();
            st.pop();

            // Form a new infix expression by placing the operator
            // between the two operands, and enclosing them in parentheses.
            string temp = "(" + top1 + exp[i] + top2 + ")";

            // Push the newly formed infix expression back onto the stack.
            st.push(temp);
        }
    }

    // The final infix expression will be the only element left in the stack.
    return st.top();
}


int main() {

}