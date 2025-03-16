// problem - 1011. Capacity To Ship Packages Within D Days
// link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& weights, int days, int cap) {
        int currWeight = 0;
        int d = 0;
        for (int i : weights) {
            if (currWeight + i > cap) {
                d++;
                currWeight = 0;
            }
            if (d > days) {
                return false;
            }
            currWeight += i;
        }
        if (currWeight) d++;
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int end = 0;
        int start = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            end += weights[i];
            start = max(start, weights[i]);
        }
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (helper(weights, days, mid)) {
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return start;
    }
};

int main() {
    Solution sol;

}