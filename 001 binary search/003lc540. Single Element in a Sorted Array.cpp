// leetcode - 540. Single Element in a Sorted Array
// link - https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        // edge cases:
        if(end == 0) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[end] != nums[end-1]) return nums[end];

        /*
        logic => the repeating pairs are on (even, odd) positions if the single element has not appeared,
            after the single element has appeared, the the repeating elements are on position(odd, even).
            accordingly move to right or left halves.
        */ 
        while(start <= end) {
            if(nums[mid-1]!= nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(mid%2 == 0) {
                if(nums[mid] == nums[mid-1]) end = mid-1;
                else start = mid;
                }
            else {
                if (nums[mid] == nums[mid+1]) end = mid-1;
                else start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
};