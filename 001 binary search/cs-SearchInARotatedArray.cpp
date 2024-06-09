/*
 SEARCH IN A ROTATED ARRAY - https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554

 Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now the array is rotated at some pivot point unknown to you.

For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].

Now, your task is to find the index at which ‘k’ is present in 'arr'.

Note :
1. If ‘k’ is not present in 'arr', then print -1.
2. There are no duplicate elements present in 'arr'. 
3. 'arr' can be rotated only in the right direction.

Example:

Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2

Output: 3

Explanation:
If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 3
8 9 4 5

Sample output 1:
-1 

Explanation of Sample Output 1:
For the test case, 3 is not present in the array. Hence the output will be -1.

Sample Input 2:
4 3
2 3 5 8

Sample output 2:
1

Expected Time Complexity:
Try to do this in O(log(n)). 

Constraints:
1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit: 1 second
*/




#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>& arr, int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    // int pivot = -1;
    while(start < end) {
        mid = start + (end-start)/2;
        if(arr[mid] < arr[0]){
            end = mid;
            // pivot = end;
        }
        else if(arr[mid] >= arr[0]) {
            start = mid+1;
        }
    }
    return start;
}

int binarySearch(vector<int>& arr, int s, int e, int key){
    int start = s;
    int end = e;
    while(start<=end) {

        // formula  to calculate mid index:
        int mid = (start + (end-start)/2);
        if (arr[mid] == key){
            return mid;

        // if key is less than the middle element, move end to the left of mid (i.e. mid-1):
        }else if(key < arr[mid]){
            end = mid -1;

        // if key is greater than the middle element, move start to the right of mid (i.e. mid+1):
        }else if(key > arr[mid]) {
            start = mid+1;
        }
    }
    return -1;
}


int search(vector<int>& arr, int n, int k)
{
    int pivot = findPivot(arr, n);
    // cout << "pivot"<<pivot <<endl;
    int ans = -1;
    if (k>=arr[pivot] && k<=arr[n-1]){ 
        ans = binarySearch(arr, pivot, n-1, k);
    }
    else{
        ans = binarySearch(arr, 0, pivot-1, k);
    }
    return ans;
}

int main() {

}
