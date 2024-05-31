#include <iostream>
using namespace std;

bool search(int arr[], int size, int key) {

// search the entire array for the key.
    for (int i =0; i<size; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    // if not found returns 0
    return 0;
}

int main() {
    int arr[1000];
    int size;
    int key;

    cout << "Enter size of array: ";
    cin >> size;
    
    cout << "Enter the array: ";
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the integer you want to search for: ";
    cin >> key;

    bool found = search(arr, size, key);
    if (found) cout << key << " found in the given array!" << endl;
    else cout<< key << " not found in the given array!" << endl;
}