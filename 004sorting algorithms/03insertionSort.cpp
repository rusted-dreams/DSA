#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    for(int i =0; i<arr.size(); i++) {
        int j = i;
        while(j>0 && arr[j]< arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}



int main() {
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};
    insertionSort(arr);
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout<< endl;
}