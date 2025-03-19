// problem - 860. Lemonade Change
// link - https://leetcode.com/problems/lemonade-change/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int fives = 0, tens = 0;
            for(int i:bills) {
                if(i == 5) fives++;
                else if(i == 10) {
                    tens++;
                    if(fives) fives--;
                    else return false;
                }
                else {
                    if(tens && fives) {
                        tens--;
                        fives--;
                    }
                    else if(fives >= 3) {
                        fives -= 3;
                    }
                    else return false;
                }
            }
            return true;
        }
    };

int main() {
    Solution sol;
    
}