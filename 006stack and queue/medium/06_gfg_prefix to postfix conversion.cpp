// problem - Prefix to Postfix Conversion
// link - https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

#include <bits/stdc++.h>
using namespace std;

string preToPost(string exp) {
    stack<string> st;

    // Iterate through the prefix expression from right to left
    for (int i = exp.size() - 1; i >= 0; i--) {
        // If the character is an operand (alphanumeric), push it onto the stack
        if (isalnum(exp[i])) st.push(string(1, exp[i]));
        
        else {
            // If the character is an operator, pop the top two operands from the stack
            string top1 = st.top();
            st.pop();

            string top2 = st.top();
            st.pop();

            // Rule: In prefix notation, the operator precedes its operands
            // In postfix notation, the operator follows its operands
            // So, the conversion follows the rule: (Operator Operand1 Operand2) → (Operand1 Operand2 Operator)

            string temp = top1 + top2 + exp[i]; // Form the postfix expression
            st.push(temp); // Push the new expression back onto the stack
        }
    }

    // The final element left in the stack is the postfix expression
    return st.top();
}


int main() {

}