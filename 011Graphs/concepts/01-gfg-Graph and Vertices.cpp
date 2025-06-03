// problem - Graph and Vertices
// link - https://www.geeksforgeeks.org/problems/graph-and-vertices/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long count(int n) {
        int maxEdges = n * (n - 1) / 2; // nC2;
        long long  ans = pow(2, maxEdges);
        return ans;
    }
};

int main() {
    Solution sol;

}