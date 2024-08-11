#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    // base case:
    if (size == 0 || size == 1) return true;

    if(arr[0] > arr[1]) return false;
    else {
        return isSorted(arr+1, size-1);
    }
}


int main() {
    int arr[5] = {3, 5, 13, 9, 23};
    int size = 5;

    int ans = isSorted(arr, 5);

    if (ans) {
        cout << "array is sorted!" << endl;
    }
    else{
        cout << "array is not sorted" << endl;
    }

}