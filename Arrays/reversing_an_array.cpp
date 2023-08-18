#include <iostream>
#include <vector>
using namespace std;

// vector<int> reverse(vector<int> arr, int size) {
//     int start =0;
//     int end = size-1;

//     while (start<=end) {
//         int temp = arr[end];

//         arr[end] = arr[start];
//         arr[start] = arr[temp];

//         start++, end--;
//     }
//     return arr;
// }

// int main() {
//     int size;
//     vector<int> arr;
//     cout << "Enter size of the array: ";
//     cin >> size;
//     cout << "Enter the array: ";
//     for (int i=0; i<size; i++) {
//         cin >> arr[i];
//     }
//     vector<int> revercedArray = reverse(arr, size);
//     cout << "Reverced array: " << revercedArray << endl;
// }

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[1000];
    for (int i=0; i<size; i++) {
        cin >> arr[i];

    }

    int start =0;
    int end = size-1;

    while (start<end) {

        swap(arr[start], arr[end]);
        // int temp = arr[start];

        // arr[start] = arr[end];
        // arr[end] = temp;

        start++, end--;
    }
    cout << "reversed array = ";
    for(int i=0; i<size; i++) {
        cout << arr[i];
    }
}