// link - https://leetcode.com/problems/longest-repeating-character-replacement/
// problem - 424. Longest Repeating Character Replacement

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int l = 0, r = 0, cnt = 0, maxLen = 0, maxFreq = 0;
    vector<int> hash(26, 0);
    while (r < s.length()) {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        if (r - l + 1 - maxFreq > k) {
            hash[s[l] - 'A']--;
            maxFreq = 0;
            l++;
        }
        if (r - l + 1 - maxFreq <= k) {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}
int main() {

}