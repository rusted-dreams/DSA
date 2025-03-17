// problem - K-th element of two Arrays
// link - https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();

        // Ensure a is the smaller array for efficiency
        if (m < n) return kthElement(b, a, k);

        // Handle edge cases
        if (n == 0) return b[k - 1];
        if (k == 1) return min(a[0], b[0]);
        if (k == n + m) return max(a[n - 1], b[m - 1]);

        // Binary search bounds
        int left = max(0, k - m);  // We need at least k-m elements from a
        int right = min(k, n);   // We can take at most min(k,n) elements from a

        while (left <= right) {
            int midA = left + (right - left) / 2;
            int midB = k - midA;

            int l1 = (midA > 0) ? a[midA - 1] : INT_MIN;
            int l2 = (midB > 0) ? b[midB - 1] : INT_MIN;
            int r1 = (midA < n) ? a[midA] : INT_MAX;
            int r2 = (midB < m) ? b[midB] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                // Found the correct partition
                return max(l1, l2);
            }
            else if (l1 > r2) {
                // Need to move left in a
                right = midA - 1;
            }
            else {
                // Need to move right in a
                left = midA + 1;
            }
        }
        return -1; // This should never be reached if inputs are valid
    }
};


int main() {
    Solution sol;

}