// 1207. Unique Number of Occurrences

#include <iostream>
using namespace std;

bool unique(int arr[], int size) {
    int ans = arr[0];
    for (int i = 1; i<size; i++) {
        if (ans^arr[i] == 0){
            return 0;
        }
        ans = arr[i];
    }
    return 1;
}

int main() {
    int arr[5] = {1, 4, 9, 8, 34};
    int size = 5;
    cout << unique(arr, size)<< endl;
}