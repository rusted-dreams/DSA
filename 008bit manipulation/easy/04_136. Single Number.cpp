// problem - 136. Single Number
// link - https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int unique = 0;
    for (int i = 0; i < nums.size(); i++) {
        unique ^= nums[i];
    }
    return unique;
}
int main() {

}