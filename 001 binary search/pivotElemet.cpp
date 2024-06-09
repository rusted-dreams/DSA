#include <iostream>
using namespace std;

int pivot(int arr[], int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int pivot = -1;
    while(start < end) {
        if(arr[mid] < arr[0]){
            end = mid;
            pivot = end;
        }
        else if(arr[mid] >= arr[0]) {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return pivot;
} 

int main() {
    int arr[6] = {7, 9, 5, 6, 6, 6};
    int ans = pivot(arr, 6);
    cout << ans<< endl;

}