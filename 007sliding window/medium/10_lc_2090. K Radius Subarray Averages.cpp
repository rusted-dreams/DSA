// problem - 2090. K Radius Subarray Averages
// link - https://leetcode.com/problems/k-radius-subarray-averages/

#include <bits/stdc++.h>
using namespace std;

vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size(); // Get the size of the input array
    vector<int> ans(n, -1); // Initialize the result array with -1
    int window = 2 * k + 1; // Define the sliding window size

    // If the window size is greater than the array size, return the result as is
    if (window > nums.size()) return ans;

    long sum = 0; // Variable to store the sum of the current window

    // Calculate the sum of the first window
    for (int i = 0; i < window; i++) {
        sum += nums[i];
    }

    // Set the average for the center of the first window
    ans[k] = sum / window;

    // Initialize left and right pointers for the sliding window
    int l = 1, r = window;

    // Slide the window across the array
    while (r < n && r - l + 1 == window) {
        sum -= nums[l - 1]; // Subtract the element that goes out of the window
        sum += nums[r]; // Add the element that comes into the window
        ans[r - k] = sum / window; // Compute the average for the new window center
        l++; // Move the left pointer
        r++; // Move the right pointer
    }

    return ans; // Return the result array
}

int main() {

}