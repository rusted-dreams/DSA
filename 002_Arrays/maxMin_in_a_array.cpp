#include <iostream>
using namespace std;


int getMax(int arr[], int len) {
    
    int max = INT32_MIN; //The minumum int value that can be hold by int type.

    for(int i = 0; i < len; i++) {
        // checks if the i'th element is greater than current max
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int arr[], int len) {

    int min = INT32_MAX;

    for(int i = 0; i< len; i++) {
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int main() {
    cout << "enter length of array: ";
    int arr[1000];
    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << "largest no. in the array is: " << getMax(arr, len) << endl;
    cout << "smallest no. in the array is: "<< getMin(arr, len) << endl;

}