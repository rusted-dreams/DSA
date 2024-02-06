// leetcode problem69: https://leetcode.com/problems/sqrtx/description/
// code studio problem: https://www.codingninjas.com/studio/problems/square-root_893351

#include <iostream>
using namespace std;


int squareRoot(int x) {
    int start = 0;
    int end = x;
    int mid = start+(end-start)/2;
    int root = 0;
    while (start <= end) {
        if (mid*mid <= x) {
            root = mid;
            start = mid+1;
        } 
        else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return root;
}

int main() {
    cout << squareRoot(9);
}