// problem - Count total set bits
// link - https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    if (n == 0) return 0;

    int x = 0;
    int a = n;

    // Find the largest power of 2 less than or equal to n
    while (a) {
        x++;
        a = a >> 1;
    }
    x = x - 1;

    // Total set bits in numbers from 1 to 2^x - 1
    int count1 = x * (1 << (x - 1));

    // Total set bits contributed by MSB from 2^x to n
    int count2 = n - (1 << x) + 1;

    // Recursive call for the remaining numbers
    int count3 = countSetBits(n - (1 << x));

    return count1 + count2 + count3;
}


int main() {

}