// problem - 260. Single Number III
// link - https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>
using namespace std;

//concept of buckets:
vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (int i : nums) {
        xorAll = xorAll ^ i;
    }
    int rightSetBit = 0;
    while ((xorAll & 1) != 1) {
        rightSetBit++;
        xorAll = xorAll >> 1;
    }
    int bucket1 = 0;
    int bucket2 = 0;

    for (int i : nums) {
        if (i & (1 << rightSetBit)) bucket1 = bucket1 ^ i;
        else bucket2 = bucket2 ^ i;
    }
    return { bucket1, bucket2 };
}


// using hashing:

// vector<int> singleNumber(vector<int>& nums) {
//     unordered_map<int, int> freq;
//     for (int i : nums) {
//         freq[i]++;
//     }

//     vector<int> ans;
//     for (auto it : freq) {
//         if (it.second == 1) ans.push_back(it.first);
//     }

//     return ans;
// }

int main() {

}