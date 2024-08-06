#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    int mid = start + (end-start)/2;

    // base case
    if (start>end) return -1;

    if(arr[mid] == key) {
        return mid;
    } 
    else if (key > arr[mid]) {
        return binarySearch(arr, mid+1, end, key);
    }
    else
    {
        return binarySearch(arr, start, mid-1, key);
    }
    // return -1;
    
}

int main() {

    int arr[100] = {2, 3, 4, 6, 8, 9}; 
    cout << binarySearch(arr, 0, 5, 3) << endl;
}