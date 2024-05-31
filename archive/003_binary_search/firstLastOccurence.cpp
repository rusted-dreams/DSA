#include <iostream>
using namespace std;



int firstOccurence (int arr[], int len, int key) {
    int first = -1;
    int start = 0;
    int end = len-1;
    int mid = start + (end-start)/2;
    while (start <= end) {
        if (key == mid) {
            first = mid;
            end = mid-1;
        } else if (key < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return first;
}
int lastOccurnce(int arr[], int len, int key) {
    int last = -1;
    int start = 0;
    int end = len-1;
    int mid = start + (end-start)/2;
    while (start <= end) {
        if (key == mid) {
            last = mid;
            start = mid+1;
        } else if (key < arr[mid]) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return last;
}

int main() {
    int arr[5] = {1, 2, 2, 2, 2};
    cout << firstOccurence(arr, 5, 2)<<endl;
    cout << lastOccurnce(arr,5,2);
}