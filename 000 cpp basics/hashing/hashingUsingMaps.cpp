#include <iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

/*
time complexity of map is O(logN) - best, avg, worst;
time complexity of unordered_map is O(1) - best, avg & O(n) -> worst case.

always use unordered_map for hashing as the worst case is very rare and thus gives gives the result in constant time.
*/

int countNum(vector<int> &arr, int key){
    unordered_map<int, int> map;
    // store the frequencies
    for(auto it : arr) {
        map[it]++;
    }

    // fetch the frequency
    return map[key];
}

int main() {
    vector<int> arr = {5, 5, 9, 4, 4, 2, 9, 9, 9, 5};
    cout << "frequency of 9 in arr : " << countNum(arr, 9) << endl;
}