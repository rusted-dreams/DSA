// problem - 210. Course Schedule II
// link - https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
    // using BFS (KHANS ALGORITHM);
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> res;
        while (!q.empty()) {
            int course = q.front();
            res.push_back(course);
            q.pop();
            for (int it : adj[course]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        return res.size() == numCourses ? res : vector<int>(0);

    }
};

int main() {
    Solution sol;

}