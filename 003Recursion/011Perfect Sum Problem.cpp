// problem - Perfect Sum Problem (count the no. of subsequences with sum = k)
// link - https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count(vector<int>& arr, int target, int idx, int suum, int n) {
        if (idx == n) {
            if (target == suum) return 1;
            else return 0;
        }
        suum += arr[idx];
        int res = count(arr, target, idx + 1, suum, n);
        suum -= arr[idx];
        res += count(arr, target, idx + 1, suum, n);
        return res;
    }
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int suum = 0;
        int res = count(arr, target, 0, suum, n);
        return res;
    }
};

int main() {
    Solution sol;

}