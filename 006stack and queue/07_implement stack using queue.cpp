// problem - 225. Implement Stack using Queues
// link - https://leetcode.com/problems/implement-stack-using-queues/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q; // Single queue used to simulate stack operations

    MyStack() {
        // Constructor to initialize the stack (no additional setup needed)
    }

    void push(int x) {
        // Push an element onto the stack
        int cnt = q.size(); // Get the current size of the queue
        q.push(x); // Add the new element to the queue
        // Rotate the queue to ensure the new element is at the front
        while (cnt) {
            int temp = q.front(); // Get the front element
            q.pop(); // Remove the front element
            q.push(temp); // Push the removed element to the back
            cnt--;
        }
    }

    int pop() {
        // Remove and return the top element of the stack
        int temp = q.front(); // Get the front element (top of the stack)
        q.pop(); // Remove the front element
        return temp; // Return the top element
    }

    int top() {
        // Return the top element of the stack without removing it
        return q.front(); // The front of the queue is the top of the stack
    }

    bool empty() {
        // Check if the stack is empty
        return q.empty(); // A queue with no elements means the stack is empty
    }
};


int main() {

}