// find the most and least frequent element in the arr

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> maxFreq(vector<int> &arr){
    unordered_map<int, int> map;
    for(auto it : arr) {
        map[it]++;
    }

    int maxi = 1;
    int mostFreqEl = arr[1];
    for(auto it: map) {
        if(it.second > maxi){
            maxi = it.second;
            mostFreqEl = it.first;
        } 
    }
    pair<int, int> el = {mostFreqEl, maxi};
    return el;
}

pair<int, int> leastFreq(vector<int> &arr){
    unordered_map<int, int> map;
    for(auto it : arr) {
        map[it]++;
    }

    int mini = arr.size();
    int leastFreqEl = 0;
    for(auto it: map) {
        if(it.second < mini){
            mini = it.second;
            leastFreqEl = it.first;
        } 
    }
    pair<int, int> el = {leastFreqEl, mini};
    return el;
}

int main() {
    vector<int> arr = {9, 5, 7, 9, 9, 3, 5, 7, 9, 7, 9};
    pair<int, int> highest = maxFreq(arr);
    pair<int, int> least = leastFreq(arr);
    cout << " most freq element : " << highest.first << " with freq. " << highest.second << endl;
    cout << " least freq element : " << least.first << " with freq. " << least.second << endl;

}