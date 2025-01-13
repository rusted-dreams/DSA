// problem - 1358. Number of Substrings Containing All Three Characters
// link - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int result = 0;
    vector<int> lastSeen(3, -1);
    for (int i = 0; i < s.length(); i++) {
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            result = result + (min(min(lastSeen[0], lastSeen[1]), lastSeen[2])) + 1;
        }
    }
    return result;
}
int main() {

}