#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size) {
    for(int i=0; i+1<size; i+=2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
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
    int arr[1000]; 
    int size;
    cin >> size;
    fillArray(arr, size);

    cout << "original arr : ";
    printArr(arr, size);

    cout << "swapped arr : ";
    swapAlternate(arr, size);
    printArr(arr, size);
}