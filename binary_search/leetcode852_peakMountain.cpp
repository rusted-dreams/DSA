// leetcode question 852: https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/

#include <iostream>
using namespace std;

int peakElementInMountainArray(int size, int arr[]) {
    int s = 0, e = size-1;
    int mid = s + (e-s)/2;
    int peak = -1;

    // Hamara ans revolve karega s ke around; check karenge agar agar mid element agle element se chota hai to start ko agle element mein le jayenge. 
    // Aur agar mid element agle element se bada ya equal hai to end ko mid par le ayenge. last mein hamare paas start bilkul peak element par milega.
    // use return karwa denge.
    while (s<e) {

        // start ko mid+1 par right (mid+1) par le jao agar mid element agle element se chota hai.
        if (arr[mid] < arr[mid+1]){
            s = mid + 1;
        }

        // end ko mid par le jao agar agle element chota hai mid waale element se.
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}


int main() {
    int arr[5] = {1,4,6,3,1};
    int peak = peakElementInMountainArray(5, arr);
    cout << "index of the peak element in the mountain array is :" << peak;
    cout << endl << "and the peak element is :" << arr[peak];
}