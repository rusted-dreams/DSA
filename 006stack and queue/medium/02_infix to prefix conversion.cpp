#include <bits/stdc++.h>
using namespace std;

/*
Rules for infix-to-prefix conversion:
1. Reverse the infix expression:
   - This converts the expression into a form that can be treated like postfix during processing.

2. Process each character:
   - If it's an operand (letters, numbers), append it directly to the result.
   - If it's a closing parenthesis ')', push it onto the stack.
   - If it's an opening parenthesis '(', pop from the stack until a closing parenthesis ')' is found.
   - If it's an operator, pop from the stack while the precedence of the operator on top of the stack is higher or equal.
     (Special rule: '^' has right-to-left associativity.)

3. After processing all characters, pop all remaining operators from the stack and append them to the result.

4. Reverse the final result to obtain the prefix expression.
*/


// Function to determine the precedence of operators
int priority(char ch){
    if(ch == '^') return 3; // Highest precedence for the exponent operator
    else if(ch == '*' || ch == '/') return 2; // Higher precedence for multiplication and division
    else if(ch == '+' || ch == '-') return 1; // Lowest precedence for addition and subtraction
    else return -1; // Return -1 for non-operator characters (e.g., parentheses)
}

// Function to convert an infix expression to a prefix expression
string infixToPrefix(string s) {
    // Step 1: Reverse the given infix expression
    reverse(s.begin(), s.end());

    // Stack to store operators
    stack<char> st;

    // String to store the resulting prefix expression
    string ans = "";

    // Loop through each character in the reversed string
    for(char i : s) {
        // Case 1: Operand (letters, numbers) -> directly add to the result
        if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) 
            ans += i;
        
        // Case 2: Closing parenthesis ')' -> push it onto the stack
        else if(i == ')') 
            st.push(i);
        
        // Case 3: Opening parenthesis '(' -> pop and add all operators until ')' is encountered
        else if(i == '(') {
            while(!st.empty() && st.top() != ')'){
                ans += st.top(); // Add operators to the result
                st.pop(); // Remove the operator from the stack
            }
            st.pop(); // Remove the closing parenthesis ')'
        }
        
        // Case 4: Operator -> process based on precedence
        else {
            // Pop operators from the stack if they have higher or equal precedence
            // Special condition for '^' (right-to-left associativity): process only if the precedence is equal
            while (!st.empty() && 
                   (priority(i) < priority(st.top()) || 
                   (i == '^' && priority(i) == priority(st.top())))) {
                ans += st.top(); // Add the operator to the result
                st.pop(); // Remove the operator from the stack
            }
            st.push(i); // Push the current operator onto the stack
        }
    }

    // Step 5: Pop and add all remaining operators in the stack to the result
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Step 6: Reverse the result to get the final prefix expression
    reverse(ans.begin(), ans.end());

    return ans;
}



int main() {
    
}