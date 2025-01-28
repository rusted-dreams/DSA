// problem - 
// link - 

#include <bits/stdc++.h>
using namespace std;

// Approach 2: Optimized for frequent `push` operations
// - `push()`: O(1)
// - `pop()` and `peek()`: Amortized O(1), O(n) occasionally
class MyQueue {
public:
    // Two stacks: 
    // st1 is used for input (to push new elements), 
    // st2 is used for output (to pop/peek elements in FIFO order)
    stack<int> st1;
    stack<int> st2;

    // Constructor: Initializes the queue
    MyQueue() {}

    // Push an element into the queue
    // Simply push the element onto st1
    void push(int x) {
        st1.push(x);
    }

    // Pop the front element of the queue
    int pop() {
        // If st2 is not empty, pop the top of st2 (front of the queue)
        if (!st2.empty()) {
            int ans = st2.top();
            st2.pop();
            return ans;
        } 
        // If st2 is empty, transfer all elements from st1 to st2
        // This reverses the order of elements to mimic a queue
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        // Pop the front element (top of st2)
        int ans = st2.top();
        st2.pop();
        return ans;
    }

    // Get the front element of the queue without removing it
    int peek() {
        // If st2 has elements, the top of st2 is the front of the queue
        if (!st2.empty()) {
            return st2.top();
        } 
        // Otherwise, transfer elements from st1 to st2 to access the front element
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }

    // Check if the queue is empty
    bool empty() {
        // The queue is empty if both stacks are empty
        return st1.empty() && st2.empty();
    }
};

// //Approach 1: Optimized for frequent `pop` and `peek` operations
// //- `push()`: O(2n) (inefficient due to element reordering)
// //- `pop()` and `peek()`: O(1)
// class MyQueue {
// public:
//     stack<int> st1; // Single stack for all operations
//     stack<int> st2;

//     MyQueue() {}

//     // Push an element into the queue
//     // Transfer all elements to st2, push the new element onto st1,
//     // and then move elements back from st2 to st1 to maintain order
//     void push(int x) {
//         while (!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push(x);
//         while (!st2.empty()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }

//     // Pop the front element of the queue
//     int pop() {
//         int ans = st1.top(); // Top of st1 is the front of the queue
//         st1.pop();
//         return ans;
//     }

//     // Get the front element of the queue without removing it
//     int peek() {
//         return st1.top(); // Top of st1 is the front of the queue
//     }

//     // Check if the queue is empty
//     bool empty() {
//         return st1.empty();
//     }
// };

// // Original Approach: Unoptimized and redundant transfers between stacks
// class MyQueue {
// public:
//     stack<int> st1; // Input stack
//     stack<int> st2; // Auxiliary stack

//     MyQueue() {}

//     // Push an element into the queue
//     void push(int x) {
//         st1.push(x);
//     }

//     // Pop the front element of the queue
//     int pop() {
//         // Transfer all elements from st1 to st2 to reverse the order
//         while (!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         // Get the top element of st2 (front of the queue)
//         int temp = st2.top();
//         st2.pop();
//         // Transfer elements back to st1
//         while (!st2.empty()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//         return temp;
//     }

//     // Get the front element of the queue without removing it
//     int peek() {
//         // Transfer elements from st1 to st2 to reverse the order
//         while (!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         // Get the top element of st2 (front of the queue)
//         int temp = st2.top();
//         // Transfer elements back to st1
//         while (!st2.empty()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//         return temp;
//     }

//     // Check if the queue is empty
//     bool empty() {
//         return st1.empty();
//     }
// };


int main() {

}