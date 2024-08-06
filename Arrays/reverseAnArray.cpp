#include <iostream>
using namespace std;


void reverse(int arr[], int size) {
    int start = 0, end = size-1;
    while (start<end) {
        swap(arr[start], arr[end]);
        start ++;
        end --;
    }
}

void fillArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
}

void printArr(int arr[], int size){
    for (int i=0; i<size; i++) {
        cout << arr[i]<< " ";
    }
    cout << endl;
    
}


int main() {
    int size;
    cin >> size;
    int arr[100000];

    fillArray(arr, size);
    cout << "original array: ";
    printArr(arr, size);
    reverse(arr, size);
    cout << "reversed array: ";
    printArr(arr, size);

}