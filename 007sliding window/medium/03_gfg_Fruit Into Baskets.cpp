// link - https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
// problem - Fruit Into Baskets

#include <bits/stdc++.h>
using namespace std;


// this problem can be reduced to - 'finding longest substing with atmost 2 distinct elements'
// this is the implementation of it.
int totalFruits(vector<int>& arr) {
    int maxLen = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp;
    while (r < arr.size()) {
        mp[arr[r]]++;
        if (mp.size() > 2) {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0) mp.erase(arr[l]);
            l++;
        }
        if (mp.size() <= 2) maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}


int main() {

}