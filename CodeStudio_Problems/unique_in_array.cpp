//problem link:
// https://www.codingninjas.com/studio/problems/find-unique_625159

#include <iostream>
using namespace std;

int findUnique(int arr[], int size) {
    /*
    The logic that we are using is we are piciking each element of the array and doing X-OR operation of it
    with each element in the array, this will give zero if the element repeats, as X-OR gives 0 for same elements and 1 for distict elements.
    */

    int ans = 0; // we don't know the unique element so let it be 0;
   
    for(int i = 0; i<size; i++) {
        // cout << "i = " << i << endl;
        ans = ans^arr[i];
        // cout << "ans = " << ans << endl;


   }
//    cout << endl;
   return ans;
}
int main() {
    int arr[5] = {9, 2, 9, 3, 2};
    int size = 5;
    cout << findUnique(arr, size) << endl;
}