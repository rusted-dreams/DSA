// find the maximum and minimum value in an array.

#include <iostream>
using namespace std;

int maxi(int arr[], int size) {
    int maxx = INT32_MIN;
    for (int i=0; i<size; i++) {
        if (arr[i] > maxx) maxx = arr[i];
    }
    return maxx;
}

int mini(int arr[], int size) {
    int minn = INT32_MAX;
    for (int i=0; i<size; i++) {
        if (arr[i] < minn) minn = arr[i];
    }
    return minn;
}

void fillArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
}


int main() {
    int arr[100];
    int size;
    cin >> size;
    fillArray(arr, size);

    int maxx = maxi(arr, size);
    int minn = mini(arr, size);

    cout << "max in arr : " << maxx<< endl;
    cout << "min in arr : " << minn<< endl;

}