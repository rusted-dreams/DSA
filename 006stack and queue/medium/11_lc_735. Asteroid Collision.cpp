// problem - 735. Asteroid Collision
// link - https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized O(N) time & O(N) space using vector (no need to reverse).
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Acts as a stack.
        for(int i = 0; i < asteroids.size(); i++) {
            if(st.empty() || asteroids[i] > 0) 
                st.push_back(asteroids[i]); // Push if moving right.
            else { // Collision case: moving left.
                while(!st.empty() && st.back() > 0 && st.back() < -asteroids[i]) 
                    st.pop_back(); // Destroy smaller right-moving asteroids.

                if(!st.empty() && st.back() == -asteroids[i]) 
                    st.pop_back(); // Both asteroids destroy each other.
                else if(st.empty() || st.back() < 0) 
                    st.push_back(asteroids[i]); // Push if no collision.
            }
        }
        return st;
    }

    // // Stack-based O(2N) time & O(N) space approach.
    // vector<int> asteroidCollision(vector<int>& asteroids) {
    //     stack<int> st; // Stack to track asteroids.
    //     vector<int> res; // Store final state.

    //     for(int i = 0; i < asteroids.size(); i++) {
    //         if(st.empty() || asteroids[i] > 0) 
    //             st.push(asteroids[i]); // Push if moving right.
    //         else { // Collision case: moving left.
    //             while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) 
    //                 st.pop(); // Destroy smaller right-moving asteroids.

    //             if(!st.empty() && st.top() == abs(asteroids[i])) 
    //                 st.pop(); // Both asteroids destroy each other.
    //             else if(st.empty() || st.top() < 0) 
    //                 st.push(asteroids[i]); // Push if no collision.
    //         }
    //     }

    //     while(!st.empty()) { 
    //         res.push_back(st.top());
    //         st.pop();
    //     }
    //     reverse(res.begin(), res.end()); // Reverse since stack stores in reverse order.
    //     return res;
    // }
};

int main() {
    Solution sol;
     
}