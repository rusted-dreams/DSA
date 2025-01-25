// problem - Find XOR of numbers from L to R
// link - https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1


// check notebook for pattern:
int xorToN(int n) {
    if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else if (n % 4 == 3) return 0;
    else if (n % 4 == 0) return n;
}

int findXOR(int l, int r) {
    return xorToN(l - 1) ^ xorToN(r);
}

#include <bits/stdc++.h>
using namespace std;


int main() {

}