#include <iostream>
using namespace std;

/*
- program uses 2 types of mem. stack mem. and heap mem.
- when a var uses stack mem. its static mem. allocation.
- when a var uses heap mem. its called dynamic mem. allocation.
*/

void readArr(int *arr, int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " , ";
    }
    cout << endl;
}


int main() {
    // creating a var. in heap
    int *num = new int;
    *num = 69;
    cout << "num in heap memory : " << *num << endl;

    // creating a dynamic array in heap:
    int n;
    cout << "enter dynamic size of arr ";
    cin >> n;
    
    int *arr = new int[n];

    // taking input in arr:
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // reading the array
    readArr(arr, n);


    // since num and arr are created in heap, we need to manually release them from the memory
    delete num;
    delete []arr;

    // try reading after deleting:
    cout << *num << endl;
}