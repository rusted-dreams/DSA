#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int miniIndex = 0;
    for(int i=0; i<arr.size()-1; i++){
        miniIndex = i;
        for(int j=i; j<arr.size(); j++) {
            if(arr[j] < arr[miniIndex]) {
                miniIndex = j;
            }
        }
        swap(arr[i], arr[miniIndex]);
    }
}

int main() {
    vector<int> arr = {5, 3, 2, 8};
    selectionSort(arr);
    for (int i=0; i<arr.size(); i++){
        cout << arr[i]<<" ";
    }
    cout<< endl;
    
}