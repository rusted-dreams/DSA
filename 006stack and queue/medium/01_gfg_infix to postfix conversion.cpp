// problem - 
// link - 

#include <bits/stdc++.h>
using namespace std;


/*
### Rules for Infix to Postfix Conversion:
1. **Operands (letters/numbers):** Add directly to the result.
2. **Opening Parentheses `(`:** Push onto the stack.
3. **Closing Parentheses `)`:** Pop from the stack to the result until an opening parenthesis `(` is found. Discard the `(`.
4. **Operators (+, -, *, /, ^):**
   - If the stack is empty or the current operator has higher precedence than the operator on top of the stack, push it.
   - Otherwise, pop operators from the stack (and append them to the result) until the stack is empty or the current operator has higher precedence.
5. **End of Expression:** Pop any remaining operators from the stack and append them to the result (ignore parentheses).

### Precedence:
- `^` (highest precedence)
- `*` and `/`
- `+` and `-` (lowest precedence)
- Parentheses `()` are used to override precedence.

### Associativity:
- Operators like `^` are **right-to-left associative**.
- Operators like `+`, `-`, `*`, `/` are **left-to-right associative**.

### Example:
Input: `a+b*(c^d-e)^(f+g*h)-i`
Output: `abcd^e-fgh*+^*+i-`
*/

// Function to determine the precedence of operators.
int priority(char ch) {
    // Higher numbers indicate higher precedence.
    if (ch == '^') return 3;                // Exponent operator has the highest precedence.
    else if (ch == '*' || ch == '/') return 2; // Multiplication and division have the next highest precedence.
    else if (ch == '+' || ch == '-') return 1; // Addition and subtraction have the lowest precedence among operators.
    else return -1;                           // Return -1 for non-operators like parentheses.
}

// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string& s) {
    stack<char> st;  // Stack to store operators and parentheses.
    string ans = ""; // String to store the resultant postfix expression.

    for (char i : s) {
        // 1. If the character is an operand (alphabet or digit), add it directly to the result.
        if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
            ans += i;

        // 2. If the character is an opening parenthesis, push it onto the stack.
        else if (i == '(')
            st.push(i);

        // 3. If the character is a closing parenthesis:
        //    - Pop and append all operators from the stack until an opening parenthesis is found.
        //    - Remove the opening parenthesis from the stack.
        else if (i == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the '(' from the stack.
        }

        // 4. If the character is an operator:
        else {
            // a. If the stack is not empty and the precedence of the current operator
            //    is higher than the precedence of the operator at the top of the stack, push it.
            if (!st.empty() && priority(i) > priority(st.top()))
                st.push(i);

            // b. Otherwise, pop operators from the stack (and append them to the result)
            //    until the stack is empty or the precedence of the current operator
            //    is greater than the precedence of the operator at the top of the stack.
            else {
                while (!st.empty() && priority(i) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(i); // Push the current operator onto the stack.
            }
        }
    }

    // 5. After traversing the expression, pop all remaining operators from the stack
    //    and append them to the result.
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans; // Return the resultant postfix expression.
}


int main() {

}