#include <iostream>
using namespace std;

// passing the array and size of the array as arguments.
int sumOfArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;

    int arr[1000];
    cout << "Enter the array: ";
    for (int i = 0; i<size; i++) {
        cin >> arr[i];
    }

    cout << "Sum of the elements of the given array = " << sumOfArray(arr, size);
    
}