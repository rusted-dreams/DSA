#include <iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int i, int n) {
    if (i==n) return; // base case

    int j = i;
    while(j>0 && arr[j-1] > arr[j]){
        swap(arr[j], arr[j-1]);
        j--;
    }
    recursiveInsertionSort(arr, i+1, n);
}

int main() {
    int arr[6] = {8, 4, 7, 9, 2, 1};
    int n = 6;
    int i = 0;
    recursiveInsertionSort(arr, i, n);
    for(int i=0; i<n; i++) cout << arr[i] <<" ";
    cout<< endl;
}