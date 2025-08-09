#include <bits/stdc++.h>
using namespace std;

void swapArr(int l, int r, vector<int>& arr) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    swapArr(++l, --r, arr);
}
int main() {
    vector<int> arr = { 6, 5, 4, 3, 2, 1 };
    swapArr(0, 5, arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}