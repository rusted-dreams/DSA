// problem - Postfix to Infix Conversion
// link - https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

#include <bits/stdc++.h>
using namespace std;

string postToInfix(string exp) {
    // Create a stack to store intermediate results during conversion
    stack<string> st;

    // Iterate through each character in the postfix expression
    for (char i : exp) {
        // Check if the character is an operand (a-z, A-Z, 0-9)
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
            // If it's an operand, push it as a string onto the stack
            st.push(string(1, i));
        } else {
            // If it's an operator, pop the top two elements from the stack
            // These two elements represent the operands of the current operator
            string top1 = st.top(); // Right operand
            st.pop();
            string top2 = st.top(); // Left operand
            st.pop();
            
            // Combine the operands and operator into an infix expression
            // Enclose the result in parentheses to preserve operator precedence
            string temp = "(" + top2 + i + top1 + ")";
            
            // Push the resulting infix expression back onto the stack
            st.push(temp);
        }
    }

    // After processing all characters, the stack will contain the final infix expression
    return st.top();
}


int main() {

}