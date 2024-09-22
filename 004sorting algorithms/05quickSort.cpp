#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low]; // taking 1st element as pivot
    int i = low;
    int j = high;
    while(i<j) {
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    
    if (low >= high) return; // base case
        
    int pivot = arr[low];
    int pivotPosition = partition(arr, low, high); // move the pivot to its corect position.
    quickSort(arr, low, pivotPosition-1); // apply quick sort in the left sub array left to the pivot.
    quickSort(arr, pivotPosition+1, high); // apply quick sort in the right subarray after pivot

}


void printArr(vector<int> num) {
    for(int i=0; i<num.size(); i++){
        cout<< num[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> num = {2, 9, 3, 8, 1, 4, 8, 5};
    cout << "before sorting: ";
    printArr(num);
    quickSort(num, 0, num.size()-1);
    cout << "after sorting: ";
    printArr(num);
}