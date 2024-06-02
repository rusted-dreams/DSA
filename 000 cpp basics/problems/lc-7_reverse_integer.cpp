/*
link - https://leetcode.com/problems/reverse-integer/description/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21

Constraints:

-231 <= x <= 231 - 1
*/


#include <iostream>
using namespace std;

int reverse(int x) {
        // int multiplier = 1;
        int reversed_x = 0;
        while (x) {
            if (reversed_x > INT32_MAX/10 || reversed_x < INT32_MIN/10)
            return 0;
            reversed_x = reversed_x*10 + (x%10);
            x /= 10;
        }
        return reversed_x;
    }

int main() {
    int x;
    cin >> x;
    cout << reverse(x) << endl;
}