#include <iostream>
using namespace std;


int sumOfArr(int arr[], int size) {
    //base case:
    if (size==1) return arr[0];

    return (arr[0] + sumOfArr(arr+1, size-1));
}

int main() {
    int arr[5] = {6, 8,3,7,4};
    int size =5;

    cout << sumOfArr(arr, size) << endl;
}