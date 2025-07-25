#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = (size - 1);
    while (start <= end) {

        // formula  to calculate mid index:
        int mid = (start + (end - start) / 2);
        if (arr[mid] == key) {
            return mid;

            // if key is less than the middle element, move end to the left of mid (i.e. mid-1):
        }
        else if (key < arr[mid]) {
            end = mid - 1;

            // if key is greater than the middle element, move start to the right of mid (i.e. mid+1):
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
    }
    return -1;
}

int recursiveBs(vector<int>& nums, int start, int end, int key) {
    if (start > end) return -1;
    int mid = start + (end - start) / 2;
    if (nums[mid] == key) return mid;
    else if (key > nums[mid]) return recursiveBs(nums, mid + 1, end, key);
    else return recursiveBs(nums, start, mid - 1, key);
}

int main() {
    int arr[6] = { 12, 23, 43, 57, 69, 72 };
    int even[6] = { 2, 7, 9, 13, 17, 34 };
    int odd[5] = { 3, 98, 102, 154, 320 };


    vector<int> arr2 = { 12, 23, 43, 57, 69, 72 };
    int ans = recursiveBs(arr2, 0, 5, 89);
    cout << "recursive ans : " << ans << endl;
    cout << "----------------------------------------" << endl;


    int index = binarySearch(arr, 6, 69);
    if (index != -1) {
        cout << "found at index: " << index << endl;
    }
    else cout << "key not found in array" << endl;

    cout << "----------------------------------------" << endl;
    index = binarySearch(even, 6, 2);
    if (index != -1) {
        cout << "found at index: " << index << endl;
    }
    else cout << "key not found in array" << endl;

    cout << "----------------------------------------" << endl;
    index = binarySearch(odd, 5, 320);
    if (index != -1) {
        cout << "found at index: " << index << endl;
    }
    else cout << "key not found in array" << endl;

}