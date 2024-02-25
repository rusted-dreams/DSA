// Search In Rotated Sorted Array
// problem link: https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&leftPanelTab=0

// This solution was 1 approach there are other approaches as well which we will need to explore

#include <iostream>
#include <vector>
using namespace std;


// Find the pivot element index:
int getPivot(vector<int>& arr, int n) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    
    while (s<e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s+(e-s)/2;

    }
    return s;
}


// Binary search function:
int binarySearch(vector<int>& arr, int s, int n, int k ) {
    int e = n-1;
    int mid = s+(e-s)/2;
    while (s<=e) {
        if (k == arr[mid]) {
            return mid;
        }
        else if (k > arr[mid]) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;

}

int search(vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);


    // If the k is in the right part after the array:
    if (k >= arr[pivot] && k <= arr[n-1]) {
        return(binarySearch(arr, pivot, n, k));
    }

    // If k is in left part of the pivot:
    else {
        return(binarySearch(arr, 0, pivot , k));
    }
}

int main() {
    vector<int> arr = {5, 6, 7, 1, 2, 4};
    cout << search(arr, 6, 4);
}