#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int uniqueSum(vector<int> &arr){
    unordered_map<int, int> mpp;
    int ans = 0;
    for(auto i:arr) {
        mpp[i]++;
    }
    for(auto& num: mpp) {
        if(num.second == 1) ans += num.first;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 2};
    int s = uniqueSum(arr);
    cout << s << endl;
}