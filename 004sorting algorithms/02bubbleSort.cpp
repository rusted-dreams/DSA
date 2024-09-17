#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr){

    bool swapped = false;

    // for round 1 to n-1
    for(int i=1; i<arr.size(); i++) {

        // process element till n-i index:
        for(int j = 0; j<arr.size()-i; j++){
            if(arr[j]> arr[j+1]) {
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
        // for best case if arr is already sorted. t.c. in this case is O(n).
        if(!swapped) break;

    }
}


int main() {
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};
    bubbleSort(arr);
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout<< endl;
}