// https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1


#include <iostream>
using namespace std;

/*
The logic that we will be using is 1 se n-1 tak elements hai aur koi ek element hai jo repeat ho rha hai to array ke saare elements ka x-or kara denge with each other
and again with all nos. from 1 to n-1. usse saare elements 2 baar repat ho jayenge to x-or 0 ho jayega aur jo hamara no. hai wo 3 baar repeat ho jayega to x-or karne ke
baad last me whi no. bachega to usko return karva denge.
*/


int getDuplicate(int arr[], int size){

    int ans = 0;
    for (int i = 1; i<size; i++) {
        ans = ans^i;
    }

    for (int i = 0; i<size; i++) {
        ans = ans^arr[i];
    }

    return ans;
}

int main() {
    int arr[100] = {1,2,3,2};
    int size = 4;

    cout << getDuplicate(arr, size) << endl;
}