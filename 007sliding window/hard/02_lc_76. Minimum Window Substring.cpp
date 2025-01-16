// problem - 76. Minimum Window Substring
// link - https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

// check notebook for notes and sol.
string minWindow(string s, string t) {
    int startIdx = -1, minLen = INT32_MAX;
    int l = 0, r = 0, count = 0;
    vector<int> freq(256, 0);
    for (char ch : t) {
        freq[ch]++;
    }
    while (r < s.size()) {
        if (freq[s[r]] > 0) {
            count++;
        }
        freq[s[r]]--;
        while (count == t.size()) {
            int len = r - l + 1;
            if (len < minLen) {
                minLen = len;
                startIdx = l;
            }
            freq[s[l]]++;
            if (freq[s[l]] > 0) {
                count--;
            }
            l++;
        }
        r++;
    }
    if (startIdx == -1) return "";
    else return s.substr(startIdx, minLen);
}
int main() {

}