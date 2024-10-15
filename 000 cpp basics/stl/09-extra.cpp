#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// comparator for custom sorting
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    else if(p1.second == p2.second) {
        if(p1.first > p2.second) return true;
    }
    return false;
}

void explainExtra(){
    sort(a, a+n);
    sort(v.begin(), v.end());

    sort(a+2, a+4);
    
    // sort in decreasing order:
    sort(a, a+n, greater<int>);

    vector<pair<int, int>> a = {{1,2}, {2, 1}, {4,1}};
    // custom sorting a:
    // sort it acc. to second element
    // if second element is same, then sort
    // it acc. to first element but in decreasing.
    sort(a, a+n, comp);
    // {{4, 1}, {2, 1}, {1, 2}};

    int num = 7;
    // returns no. of set bits (1s).
    int cnt = __builtin_popcount(num);

    long long num = 1765786578687;
    int cnt = __builtin_popcountll(num);

    string s = "123";
    do {
        cout << s <<endl;
    } while(next_permutation(s.begin(), s.end()));

    int maxi = *max_element(v.begin(), v.end());
}

int main() {
    
}