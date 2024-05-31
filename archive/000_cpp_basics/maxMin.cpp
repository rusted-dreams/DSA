#include <iostream>
using namespace std;

int maxMin(int arr[], int n) {
    int max = INT32_MIN;
    int min =
    for(int i = 0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;

}

int main() {
    cout << "Enter size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "enter the array" << endl;
    for(int i =0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "max in your array is " << maxMin(arr, n)<< endl;
}