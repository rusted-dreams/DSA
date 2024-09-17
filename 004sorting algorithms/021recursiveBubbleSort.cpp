#include <iostream>
using namespace std;

void recursiveBubbleSort(int arr[], int n){
    //base case:
    if (n == 1 || n == 0) return;

    for(int i=0; i<n-1; i++){
        if(arr[i] >arr [i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    recursiveBubbleSort(arr, n-1);
}


int main() {
    int arr[6] = {8, 4, 7, 9, 2, 1};
    int n = 6;
    recursiveBubbleSort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] <<" ";
    cout<< endl;
}