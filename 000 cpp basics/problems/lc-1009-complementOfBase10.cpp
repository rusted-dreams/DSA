
/*
link: https://leetcode.com/problems/complement-of-base-10-integer/description/

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.

 

Example 1:

Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
Example 2:

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
Example 3:

Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 

Constraints:

0 <= n < 109
*/



#include <iostream>
using namespace std;


int bitwiseComplement(int n) {
        /*
        logic: 
        let n = 5 = 0b101
        ~5 = 0b1111111......010
        we only need the last 3 bits of ~5 which is 010 this is the complement of 5;

        so in order to extract it we need to create a mask 0b0000000.....111 such that if we do ~5 & mask we get our 
        no. which which is 0b000000......010 =2;
        */
        if (n==0) return 1;
        int m = n;
        int mask = 0;
        while (m) {
            mask = (mask << 1) | 1;
            // mask = mask << 1;
            m = m>>1;
        }
        return ((~n) & mask);
    }


int main() {
    int n;
    cin >> n;
    cout << bitwiseComplement(n) << endl;
}