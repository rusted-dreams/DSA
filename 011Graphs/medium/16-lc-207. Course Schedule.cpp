// problem - 207. Course Schedule
// link - https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using BFS for toplogical sorting(KHANS ALGORITHM);
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            count++;
            q.pop();
            for (int it : adj[course]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        return count == numCourses ? true : false;
    }
};

int main() {
    Solution sol;

}