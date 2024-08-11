#include <iostream>
using namespace std;

bool search(int arr[], int size, int key) {
    // base case:
    if (!size)
        return false;
    if(arr[0] == key) return true;
    else{
        return search(arr+1, size-1, key);
    }
}

int main() {
    int arr[5] = {3, 6, 4, 8, 2};
    int size =5;
    int key = 69;
    bool ans = search(arr, size, key);
    if (ans) {
        cout << "found in array" << endl;
    }
    else {
        cout << "not present in array" << endl;
    }
}