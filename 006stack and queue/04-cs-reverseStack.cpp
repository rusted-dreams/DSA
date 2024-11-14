//problem link - https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875
// reverse a stack

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }

    // store the top most element
    int temp = s.top();
    s.pop();

    // recursive call to reach the bottom of the stack
    insertAtBottom(s, element);
    s.push(temp); // insert the element stored at top while backtracking
}

void reverseStack(stack<int> &stack) {
    //base case:
    if(stack.empty()) return;

    // store the top most element.
    int num = stack.top();
    stack.pop();

    reverseStack(stack); // recursive call to reach the bottom of the stack
    insertAtBottom(stack, num); // finally insert the top most element at the bottom
}