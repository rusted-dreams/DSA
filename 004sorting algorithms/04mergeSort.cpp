#include <iostream>
#include <vector>
using namespace std;

// sort and merge the sub arrays:
void merge(vector<int> &arr, int low, int mid, int high) {

    // take 2 ptrs left from start of left subarray & right from start of right subarray:
    // compare the two elements of both the subarrays and whichever is smaller push it to a temp array
    int left = low;
    int right = mid+1; // since right subarray starts from mid+1
    vector<int> temp;

    while(left <= mid && right <= high) { 
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if the right subarray is exhausted and the left still has values:
    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // if the left subarray is exhausted, and right one still has values
    while(right<=high) { 
        temp.push_back(arr[right]);
        right++;
    }

    // copy the sorted nos. from the temp array to the original array:
    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}



void mergeSort(vector<int> &arr, int low, int high) {
    if(low >= high) return; // base case
    int mid = low + (high-low)/2;

    mergeSort(arr, low, mid); // break the left half sub array
    mergeSort(arr, mid+1, high); // break the right half sub array
    merge(arr, low, mid, high); // merge the sub arrays
    
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
    mergeSort(num, 0, num.size()-1);
    cout << "after sorting: ";
    printArr(num);
}