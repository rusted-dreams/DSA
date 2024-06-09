/*
https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

FIRST AND LAST OCCURENCE IN AN ARRAY

Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.


Example:
Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8 2
0 0 1 1 2 2 2 2


Sample output 1:
4 7


Explanation of Sample output 1:
For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.


Sample Input 2:
4 2
1 3 3 5


Sample output 2:
-1 -1


Expected Time Complexity:
Try to do this in O(log(n)).


Constraints:
1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit : 1 second
*/


#include <iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key){
    int start = 0, end = size-1;
    int result = -1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        if (arr[mid] == key) {
            result = mid;
            end = mid-1;
        }
        else if(key < arr[mid]) {
            end = mid -1;
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
    }
    return result;
}

int lastOccurence(int arr[], int size, int key){
    int start = 0, end = size-1;
    int result = -1;

    while (start <= end) {
        int mid = start + (end-start)/2;
        if (arr[mid] == key) {
            result = mid;
            start = mid+1;
        }
        else if(key < arr[mid]) {
            end = mid -1;
        }
        else if (key > arr[mid]) {
            start = mid + 1;
        }
    }
    return result;
}


int main() {
    int arr[8] = {0,0,1,1,2,2,2,2};
    int size = 8;
    int first =  firstOccurence(arr, size, 2);
    int last = lastOccurence(arr,size, 2);

    cout << "first: " << first << endl;
    cout << "last: " << last<< endl;
}