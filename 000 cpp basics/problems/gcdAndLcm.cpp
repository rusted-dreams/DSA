// link - https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
/*
Given two integers a and b, write a function lcmAndGcd() to compute their LCM and GCD.
The function takes two integers a and b as input and returns a list containing their LCM and GCD.

Example 1:

Input: a = 5 , b = 10
Output: 10 5
Explanation: LCM of 5 and 10 is 10, while their GCD is 5.
Input: a = 14 , b = 8
Output: 56 2
Explanation: LCM of 14 and 8 is 56, while their GCD is 2.
Expected Time Complexity: O(log(min(a, b))
Expected Auxiliary Space: O(1)

Constraints:
1 <= a, b <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> lcmAndGcd(long long a , long long b) {
        vector<long long> ans;
        long long prod = a*b;
        long long hcf = 1;
        while(a>0 && b>0) {
            if(a>=b) a = a%b;
            else b = b%a;
        }
        if(a == 0) hcf = b;
        else hcf = a;
        
        long long lcm = prod/hcf;
        
        ans.push_back(lcm);
        ans.push_back(hcf);
        return ans;
    }
};

int main() {
    
}