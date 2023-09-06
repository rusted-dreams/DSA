/*
swap the alternate elements of the array for ex.:
{1, 2, 3, 4, 5, 6} becomes {2, 1, 4, 3, 6, 5}
*/

#include <iostream>
using namespace std;


int main() {
    int arr[100];
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    cout << "Enter the array: ";
    for (int i=0; i<size; i++){
        cin >> arr[i];
    }

    int first = 0;
    int second =1;

    while (second < size) {
        swap(arr[first], arr[second]);
        first += 2;
        second +=2;
    }
   
   //printing the swapped array:
   cout << "array after swapping the alternate elements:"<< endl;
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
   }
}