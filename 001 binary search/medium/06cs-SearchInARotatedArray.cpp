//  SEARCH IN A ROTATED ARRAY - https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554
// problem - 33. Search in Rotated Sorted Array
// link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (nums[mid] == target) return mid; // Found target

            // Right half is sorted
            if (nums[mid] < nums[start]) {
                // Target lies within the sorted right half
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            // Left half is sorted
            else {
                // Target lies within the sorted left half
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            mid = start + (end - start) / 2; // Update mid
        }

        return -1; // Target not found
    }
};



// first find the pivot and then apply binary search accordingly (babbar's approach):
// class Solution {
// public:
//     int findPivot(vector<int>& arr) {
//         int start = 0;
//         int end = arr.size()-1;
//         int mid = start + (end - start) / 2;
//         // int pivot = -1;
//         while (start < end) {
//             mid = start + (end - start) / 2;
//             if (arr[mid] < arr[0]) {
//                 end = mid;
//                 // pivot = end;
//             } else if (arr[mid] >= arr[0]) {
//                 start = mid + 1;
//             }
//         }
//         return start;
//     }

//     int binarySearch(vector<int>& arr, int s, int e, int key) {
//         int start = s;
//         int end = e;
//         while (start <= end) {

//             // formula  to calculate mid index:
//             int mid = (start + (end - start) / 2);
//             if (arr[mid] == key) {
//                 return mid;

//                 // if key is less than the middle element, move end to the left
//                 // of mid (i.e. mid-1):
//             } else if (key < arr[mid]) {
//                 end = mid - 1;

//                 // if key is greater than the middle element, move start to the
//                 // right of mid (i.e. mid+1):
//             } else if (key > arr[mid]) {
//                 start = mid + 1;
//             }
//         }
//         return -1;
//     }
//     int search(vector<int>& nums, int target) {
//         int pivot = findPivot(nums);
//         // cout << "pivot"<<pivot <<endl;
//         int ans = -1;
//         if (target >= nums[pivot] && target <= nums[nums.size()-1]) {
//             ans = binarySearch(nums, pivot, nums.size()-1, target);
//         } else {
//             ans = binarySearch(nums, 0, pivot - 1, target);
//         }
//         return ans;
//     }
// };

int main() {
    Solution sol;

}