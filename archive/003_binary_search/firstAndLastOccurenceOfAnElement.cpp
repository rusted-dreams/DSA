// find the first and last occurence of an element in an array.
// problem link: https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2

#include<iostream>
#include<vector>
using namespace std;

int firstPosition(vector<int>& arr, int n, int k)
{
    int first = -1;

    // for first position:
    int start = 0, end = n-1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (arr[mid] == k) {
            first = mid;
            end = mid - 1;
            }
        else if(k > arr[mid]) {
            start = mid+1;
        }
        else if (k<arr[mid]) {
            end = mid-1;
        }
    }    
    return first;
    
}

int LastPosition(vector<int>& arr, int n, int k)
{
    int last = -1;

    // for last position:
    int start = 0, end = n-1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (arr[mid] == k) {
            last = mid;
            start = mid+1;
            }
        else if(k > arr[mid]) {
            start = mid+1;
        }
        else if (k<arr[mid]) {
            end = mid-1;
        }
    }    
    return last;
    
}


int main() {
    vector<int> arr = {3, 8, 8, 8, 8, 13};    
    cout << "first and last occurence of 8 is at index "<< firstPosition(arr, 6, 8)<<endl;
    cout << "last occurence of 8 is at index " << LastPosition(arr, 6, 8);
}
