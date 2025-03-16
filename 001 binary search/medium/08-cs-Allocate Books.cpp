// problem - Allocate Books
// link - https://www.naukri.com/code360/problems/allocate-books_1090540

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int pages, int m) {
    int n = arr.size();
    int page = arr[0];
    int students = 1;
    for(int i=1; i<n; i++) {
        if(page + arr[i] > pages){
            students++;
            page = arr[i];
        }
        else page += arr[i];
        if(students > m) return false;
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int start = *max_element(arr.begin(), arr.end());
    int totalPages = accumulate(arr.begin(), arr.end(), 0);
    int end = totalPages;
    int mid;
    while(start <= end) {
        mid = start + (end - start)/2;
        if(check(arr, mid, m) ) {
            end = mid-1;
        }
        else start = mid+1;
    }
    return start;
}

int main() {
    
}