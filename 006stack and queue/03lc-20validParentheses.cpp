// problem link - https://leetcode.com/problems/valid-parentheses/submissions/1444086617/
// 20. Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char i : s) {
        if (i == '(' || i == '[' || i == '{') st.push(i);
        else if (!st.empty()) {
            if ((i == ')' && st.top() == '(') || (i == '}' && st.top() == '{') || (i == ']' && st.top() == '[')) st.pop();
            else return false;
        } 
        else return false;
    }
    if (st.empty()) return true;
    return false;
}

int main() {

}