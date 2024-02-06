#include <iostream>
using namespace std;

int binary(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid;
    while (start <= end) {

        // formula for calculating mid element.
        mid = start + ((end-start)/2);
        if (arr[mid] == key) {
            return mid;
        }

        // if key is greater than mid element, then we move start to right of mid i.e. (mid+1)
        else if (key > arr[mid]) {
            start = mid + 1;
        }

        //if key is less than mid element, then we move end to left of mid i.e. (mid-1)
        else if (key < arr[mid]) {
            end = mid-1;
        }
    }
    return -1;
};

int main() {
    int even[6] = {2, 7, 9, 13, 17, 34};
    int odd[5] = {3, 98, 102, 154, 320};

    cout << binary(odd,5,3);
}