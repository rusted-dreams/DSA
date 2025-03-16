// problem - 4. Median of Two Sorted Arrays
// link - https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

/*
    Intuition:
    - Instead of merging both arrays (O(m + n) time), we use binary search to efficiently find the median.
    - The idea is to partition the smaller array in such a way that:
        - All elements on the left half are <= all elements on the right half.
        - This ensures a valid partition, allowing us to determine the median directly.

    Key Observations:
    - Since nums1 and nums2 are sorted, we can apply binary search on the smaller array.
    - The partition should divide the combined arrays into two equal halves (or nearly equal if odd).
    - The median depends on the values around the partition:
        - If total length is odd -> Median is the max(left partition).
        - If total length is even -> Median is avg(max(left), min(right)).
    - We adjust the partition using binary search until we find the correct split.

    Approach:
    1. Ensure `nums1` is the smaller array (reducing binary search space).
    2. Perform binary search on `nums1` to find a valid partition.
    3. Define partition indices `mid1` and `mid2` ensuring correct split.
    4. Check boundary conditions using `INT_MIN` and `INT_MAX`.
    5. If partition is correct:
        - Compute and return median.
    6. If partition is incorrect, adjust search space accordingly.
*/
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Always binary search on the smaller array for efficiency
        if (m < n) return findMedianSortedArrays(nums2, nums1);

        int start = 0, end = n;
        int totalLength = n + m;
        int half = (n + m + 1) / 2;  // Left partition size

        while (start <= end) {
            int mid1 = start + (end - start) / 2;  // Partition point in nums1
            int mid2 = half - mid1;               // Partition point in nums2

            // Boundary elements (handling edge cases)
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;  // Left max of nums1
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;  // Left max of nums2
            int r1 = (mid1 < n) ? nums1[mid1] : INT_MAX;      // Right min of nums1
            int r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;      // Right min of nums2

            // If partition is correct
            if (l1 <= r2 && l2 <= r1) {
                // Odd total length -> median is max of left partition
                if (totalLength % 2 != 0) return max(l1, l2);
                // Even total length -> median is avg of max(left) and min(right)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            // If l1 is too large, move left (reduce mid1)
            else if (l1 > r2) {
                end = mid1 - 1;
            }
            // If l2 is too large, move right (increase mid1)
            else {
                start = mid1 + 1;
            }
        }
        return 0; // This case never occurs since a median always exists
    }
};


//brute force - O(m+n) time and space
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res;
//         int i =0;
//         int j = 0;
//         while(i<nums1.size() && j < nums2.size()){
//             if(nums1[i] <= nums2[j]){
//                 res.push_back(nums1[i]);
//                 cout << nums1[i] << " "; 
//                 i++;
//             }
//             else {
//                 res.push_back(nums2[j]);
//                 cout << nums2[j] << " ";
//                 j++;
//             }
//         }
//         while(i<nums1.size()) {
//             res.push_back(nums1[i]);
//             cout << nums1[i] << " "; 
//             i++;
//         }
//         while(j<nums2.size()) {
//             res.push_back(nums2[j]);
//             cout << nums2[j] << " ";
//             j++;
//         }
//         int n = res.size();
//         if(n&1) {
//             return (double) res[n/2];
//         }
//         else {
//             double ans = ((double) res[n/2 - 1] + (double)res[n/2])/2;
//             return ans;
//         }
//     }
// };

int main() {
    Solution sol;

}