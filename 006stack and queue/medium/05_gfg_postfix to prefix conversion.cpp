// problem - Postfix to Prefix Conversion
// link - https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

#include <bits/stdc++.h>
using namespace std;

string postToPre(string exp) {
    stack<string> st;

    // Iterate through each character in the postfix expression
    for (char i : exp) {
        // If the character is an operand (alphanumeric), push it onto the stack
        if (isalnum(i))  
            st.push(string(1, i));
        else {
            // If the character is an operator, pop the top two operands from the stack
            string top1 = st.top(); 
            st.pop();
            
            string top2 = st.top(); 
            st.pop();
            
            // Rule: In postfix notation, an operator follows its operands
            // In prefix notation, the operator is placed before the operands
            // So, the conversion follows the rule: (Operand1 Operand2 Operator) → (Operator Operand1 Operand2)
            
            string temp = i + top2 + top1; // Form the prefix expression
            st.push(temp); // Push the new expression back onto the stack
        }
    }

    // The final element left in the stack is the prefix expression
    return st.top();
}


int main() {
    
}