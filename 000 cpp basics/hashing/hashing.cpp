#include <iostream>
#include<vector>
using namespace std;

int countNum(vector<int> &arr, int n, int k, int key){
    vector<int> count(k+1, 0);
    //store the counts of each element
    for(int i : arr){
        count[i]++;
    }

    // return the count of the key
    return count[key];
}


int charHashing(string &s, char ch){
    vector<int> charFrequency(26, 0);
    for(char i : s){
        charFrequency[i - 'a']++;
    }

    return charFrequency[ch - 'a'];
}


int main() {
    vector<int> arr = {1, 2, 1, 3, 3};
    cout << "frequency ok 3 in arr: " << countNum(arr, 5, 3, 3) << endl;

    string a = "fldshfgaslxflkahrwosnlcknfsalkf";
    cout << "frequency of s in the string a: " << charHashing(a, 's') << endl;
}