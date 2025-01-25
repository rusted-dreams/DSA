// link - https://leetcode.com/problems/single-number-ii/description/
// problem - 137. Single Number II


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos = 0;
        for(int i=0; i<nums.size(); i++) {
            ones = (ones^nums[i]) & ~twos;
            twos = (twos^nums[i]) & ~ones;
        }
        return ones;
    }

    //O(nlog(n)) T.C and O(1) space. - sorting.....
    // int singleNumber(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     for(int i=1; i<nums.size(); i+=3) {
    //         if(nums[i] != nums[i-1]) return nums[i-1];
    //     }
    //     return nums[nums.size()-1];
    // }

    //O(32n)T.C and O(1)space compl
    // int singleNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans =0;
    //     for(int i=0; i<=31; i++){
    //         int setBits =0;
    //         for(int j=0; j<n; j++) {
    //             if((nums[j] & (1<<i)) != 0) setBits++;
    //         }
    //         if(setBits % 3 != 0) {
    //             ans = ans | (1<<i);
    //         }
    //     } 
    //     return ans;
    // }

    //using set O(n/3) space.
    // int singleNumber(vector<int>& nums) {
    //     int ans = 0;
    //     unordered_set<int> st;

    //     for(int i:nums) {
    //         if(st.find(i) != st.end()){
    //             st.erase(i);
    //         }
    //         else {
    //             st.insert(i);
    //             ans = ans^i;
    //         }
    //     }
    //     return ans;
    // }
};


int main() {
    
}