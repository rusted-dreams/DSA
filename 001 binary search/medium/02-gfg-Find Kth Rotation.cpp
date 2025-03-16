// problem - Find Kth Rotation
// link - https://www.geeksforgeeks.org/problems/rotation4723/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findKRotation(vector<int>& arr) {
            int low = 0, high = arr.size() - 1, pivot = 0, mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                // arr is not rotated;
                if (arr[low] <= arr[high]) {
                    if (arr[pivot] < arr[low]) {
                        return pivot;
                    }
                    return low;
    
                }
    
                // left half is sorted:
                if (arr[low] <= arr[mid]) {
                    pivot = arr[pivot] < arr[low] ? pivot : low;
                    low = mid + 1;
                }
    
                // right half is sorted:
                else {
                    pivot = arr[pivot] < arr[mid] ? pivot : mid;
                    high = mid - 1;
                }
            }
            return pivot;
        }
    };

int main() {
    Solution sol;
    
}