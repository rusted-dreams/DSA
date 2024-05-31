#include <iostream>
using namespace std;

int PivotElement(int size, int arr[]) {
    int start = 0, end = size -1;
    int mid = start + (end-start)/2;

    while (start < end) {
        if (arr[mid] >= arr[0]) {
            start = mid+1;
        }
        else {
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    // cout << start;
    return start;
}

int main() {
    int arr[5] = {7, 9, 1, 2, 3 };
    int pivot = PivotElement(5, arr);
    cout << pivot;
    // PivotElement(5, arr);
}