// problem - Minimum Multiplications to reach End
// link - https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1000;

public:
    /*
    Intuition:
    From a number x, we can move to:
        (x * arr[i]) % 1000

    Every multiplication is one step.
    Since all moves have equal weight,
    the shortest path can be found using BFS.

    Think of each number from 0 -> 99999 as a node.
    We try all possible multiplications from the current node.

    Approach:
    - Start BFS from 'start'
    - For every number, generate next states using multiplication
    - Use visited array to avoid revisiting states
    - First time we reach 'end', that level is the minimum steps
    */

    int minSteps(vector<int>& arr, int start, int end) {
        vector<bool> visited(MOD, false);
        // {currentNumber, steps}
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;
        while(!q.empty()) {
            int currentNum = q.front().first;
            int steps = q.front().second;
            q.pop();
            // Reached target
            if(currentNum == end) return steps;

            for(int multiplier : arr) {
                int nextNum = (currentNum * multiplier) % MOD;
                
                // Already processed
                if(visited[nextNum]) continue;

                visited[nextNum] = true;
                q.push({nextNum, steps + 1});
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
}