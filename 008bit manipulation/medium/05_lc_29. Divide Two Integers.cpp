// problem - 29. Divide Two Integers
// link - https://leetcode.com/problems/divide-two-integers/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    // Edge case: if dividend is equal to divisor, the result is always 1
    if (dividend == divisor) return 1;

    // The result is positive only if both dividend and divisor have the same sign
    bool isPositive = true;
    if ((divisor < 0 && dividend >= 0) || (dividend < 0 && divisor > 0))
        isPositive = false;

    // Convert both dividend and divisor to positive long integers to avoid overflow
    long n = abs((long)dividend), d = abs((long)divisor);
    long ans = 0;

    // Loop until the dividend (n) is greater than or equal to the divisor (d)
    while (n >= d) {
        int count = 0;

        // Find the maximum power of 2 such that d * 2^count <= n
        while (d * (1L << (count + 1)) <= n) {
            count++;
        }

        // Add 2^count to the result and reduce n by d * 2^count
        ans += (1L << count);
        n -= d * (1L << count);
    }

    if (!isPositive) ans = -ans;

    // Handle overflow: if the result exceeds INT_MAX, return INT_MAX
    if (ans > INT_MAX) return INT_MAX;

    return ans;
}


int main() {

}