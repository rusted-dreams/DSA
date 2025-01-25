#include <iostream>
#include <math.h>
using namespace std;

// bool isPowerOfTwo(int n) {
//     for (int i = 0; i < 31; i++) {
//         if (pow(2, i) == n) return true;
//         else if (pow(2, i) > n) break;
//     }
//     return false;
// }

// better approach:
bool isPowerOfTwo(int n) {
    // edge case:
    if (n <= 0) return false;

    if (n & (n - 1)) return false;
    else return true;
}
int main() {
    
}