// problem - 2104. Sum of Subarray Ranges
// link - https://leetcode.com/problems/sum-of-subarray-ranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the Next Smaller Element (NSE) for each index
    // NSE[i] stores the index of the first smaller element to the right of nums[i]
    vector<int> getNse(vector<int> &nums){
        int n = nums.size();
        vector<int> res(n, n); // Default value is 'n' (out of bounds)
        stack<int> st;
        
        // Traverse from right to left
        for(int i=n-1; i>=0; i--) {
            // Pop elements that are greater than or equal to nums[i] (monotonic increasing stack)
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            res[i] = st.empty()? n : st.top(); // If stack is empty, there is no smaller element
            st.push(i);
        }
        return res;        
    }

    // Function to find the Previous Smaller Element (PSE) for each index
    // PSE[i] stores the index of the first smaller element to the left of nums[i]
    vector<int> getPse(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1); // Default value is '-1' (out of bounds)
        
        // Traverse from left to right
        for(int i=0; i<n; i++) {
            // Pop elements that are greater than nums[i] (monotonic increasing stack)
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            res[i] = st.empty()? -1 : st.top(); // If stack is empty, there is no smaller element
            st.push(i);
        }
        return res;
    }

    // Function to find the Next Greater Element (NGE) for each index
    // NGE[i] stores the index of the first greater element to the right of nums[i]
    vector<int> getNge(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, n); // Default value is 'n' (out of bounds)
        
        // Traverse from right to left
        for(int i=n-1; i>=0; i--) {
            // Pop elements that are smaller than or equal to nums[i] (monotonic decreasing stack)
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            res[i] = st.empty()? n : st.top(); // If stack is empty, there is no greater element
            st.push(i);
        }
        return res;
    }

    // Function to find the Previous Greater Element (PGE) for each index
    // PGE[i] stores the index of the first greater element to the left of nums[i]
    vector<int> getPge(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1); // Default value is '-1' (out of bounds)
        
        // Traverse from left to right
        for(int i=0; i<n; i++) {
            // Pop elements that are smaller than nums[i] (monotonic decreasing stack)
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            res[i] = st.empty()? -1 : st.top(); // If stack is empty, there is no greater element
            st.push(i);
        }
        return res;
    }

    // Function to calculate the sum of subarray ranges
    // Range = (Max element in subarray) - (Min element in subarray)
    long long subArrayRanges(vector<int>& nums) {
        long long minSum = 0; // Contribution of nums[i] as the min element in subarrays
        long long maxSum = 0; // Contribution of nums[i] as the max element in subarrays
        
        vector<int> nse = getNse(nums); // Next Smaller Element indices
        vector<int> pse = getPse(nums); // Previous Smaller Element indices
        vector<int> nge = getNge(nums); // Next Greater Element indices
        vector<int> pge = getPge(nums); // Previous Greater Element indices

        // Iterate over all elements to compute the range contribution
        for(int i=0; i<nums.size(); i++) {
            // Contribution of nums[i] as the smallest element in subarrays
            minSum += (long long)(nse[i] - i) * (i - pse[i]) * nums[i];
            // Contribution of nums[i] as the largest element in subarrays
            maxSum += (long long)(nge[i] - i) * (i - pge[i]) * nums[i];
        }
        
        // The total subarray range sum is the difference between maxSum and minSum
        return maxSum - minSum;
    }
};


int main() {
    
}