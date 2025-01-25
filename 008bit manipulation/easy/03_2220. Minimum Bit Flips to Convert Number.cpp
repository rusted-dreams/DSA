// problem - 2220. Minimum Bit Flips to Convert Number
// link - https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    // no of bits need to be flipped = no. of set bits in start^goal;
    int a = start ^ goal;
    int count = 0;
    while (a) {
        a = a & (a - 1);
        count++;
    }
    return count;
}

int main() {

}