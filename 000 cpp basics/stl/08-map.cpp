#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

void explainMap() {

    // map stores in sorted order of keys
    map<int, int> mpp;
    map<int, pair<int, int>> mpp1;
    map<pair<int, int>, int> mpp2;

    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.insert({2, 4});
    mpp2[{2,3}] = 10;


    for(auto it : mpp) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout << it->second;

    auto it1 = mpp.find(5);

    // This is the syntax
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above
}

void explainMultimap() {
    // same as map, only it can store duplicate keys
    // only mpp[key] cannot be used here
}

void explainUnorderedMap(){
    // same as set and unordered_Set difference.
}

int main() {
    
}