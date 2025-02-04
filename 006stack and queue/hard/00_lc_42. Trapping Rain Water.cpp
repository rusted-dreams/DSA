// problem - 42. Trapping Rain Water
// link - https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

// Two Pointer Approach - O(n) time, O(1) space.
int trap(vector<int>& height) {
    int totalWater = 0;
    int leftMax = 0, rightMax = 0;  // Track the max height seen so far from left and right
    int l = 0, r = height.size() - 1;  // Left and right pointers
    
    while (l < r) {  // Traverse until both pointers meet
        if (height[l] <= height[r]) {  // Process left side first if it's lower or equal
            if (leftMax > height[l]) {  // If leftMax is greater, store trapped water
                totalWater += leftMax - height[l];
            } else {  
                leftMax = height[l];  // Update leftMax if current height is greater
            }
            l++;  // Move left pointer forward
        } else {  // Process right side if it's lower
            if (rightMax > height[r]) {  // If rightMax is greater, store trapped water
                totalWater += rightMax - height[r];
            } else {  
                rightMax = height[r];  // Update rightMax if current height is greater
            }
            r--;  // Move right pointer backward
        }
    }
    return totalWater;
}

// // Prefix and Suffix Max Approach - O(n) time, O(n) space.
// int trap(vector<int>& height) {
//     int prefixMax = 0;  // Stores the max height seen so far from the left
//     vector<int> suffixMax(height.size(), 0);  // Stores the max height seen so far from the right

//     // Compute suffixMax array (right max for each index)
//     suffixMax[height.size() - 1] = height[height.size() - 1];  
//     for (int i = height.size() - 2; i >= 0; i--) {  
//         suffixMax[i] = max(suffixMax[i + 1], height[i]);  // Get max height from right side
//     }

//     int totalWater = 0;  // Stores total trapped water
//     for (int i = 0; i < height.size(); i++) {
//         prefixMax = max(prefixMax, height[i]);  // Update left max for current index
//         int water = min(prefixMax, suffixMax[i]) - height[i];  // Water trapped at current index
        
//         if (water > 0) totalWater += water;  // Add to total water if valid
//     }
//     return totalWater;
// }

int main() {
    
}