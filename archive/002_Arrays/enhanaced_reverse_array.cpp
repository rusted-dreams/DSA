#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> arr, int size) {
    int start = 0;
    int end = size-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++, end--;
    }
    return arr;
}

int main() {
    vector<int> arr;
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    cout << "Enter the array: ";
    for (int i=0; i<size; i++) {
        int entry;
        cin >> entry;
        cout << arr[i] << " - ";
    }

    vector<int> reversedArr = reverse(arr, size);
    cout << "reversed arr: ";
    for (int i=0; i<size; i++) {
        cout << "printing";
        cout << reversedArr[i] << " ";
    }
}