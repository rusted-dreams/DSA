/*
link - https://leetcode.com/problems/unique-number-of-occurrences/
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
        //sorting the vector
        sort(arr.begin(), arr.end());
        vector<int> counter;
        int c = 0;
        for(int i=0; i<arr.size(); i++){
            if(i==0) {
                c = 1;
            }
            else if(arr[i] == arr[i-1]){
                c++;
            }
            else if(arr[i] != arr[i-1]) {
                counter.push_back(c);
                c = 1;
            }
        }
        counter.push_back(c);

        // checking if counter has duplicates:
        for(int i=0; i<counter.size(); i++) {
            for(int j=i+1; j<counter.size(); j++) {
                if(counter[i]==counter[j]){
                    return false;
                }
            }
        }
        return true;
    }

int main() {
    
}