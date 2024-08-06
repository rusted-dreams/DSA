#include <iostream>
using namespace std;


void inputArray(int arr[], int size) {
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

void sort01(int arr[], int n){
    int i = 0;
    int j = n-1;
    while(i<=j){
        while(arr[i] == 0){
            i++;
        }
        while(arr[j] == 1){
            j--;
        }

        // agar yha tak aa gye matlab:
        // arr[i] == 1 && arr[j] == 0
        if(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}


int main() {
    int n; int arr[1000];
    cin >> n;
    inputArray(arr, n);
    cout << "original array: ";
    printArr(arr, n);
    cout << "sorted array: ";
    sort01(arr, n);
    printArr(arr, n);

}