// link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// problem - 3. Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;


// this is my own solution
// int lengthOfLongestSubstring(string s) {
        // int maxLength = 1;
        // if (s == "") return 0;
        // unordered_set<char> st;
        // int l=0,r = 0;
        // while(r<s.length()){
        //     if(st.find(s[r]) == st.end()){
        //         st.insert(s[r]);
        //         maxLength = max(maxLength, r-l+1);
        //         r++;
        //         continue;
        //     }
        //     while(s[l] != s[r]  && l<r){
        //         st.erase(s[l]);
        //         l++;
        //     }
        //     st.erase(s[l]);
        //     l++;
        // }
        // return maxLength;
    // }

    // slightly optimised:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(s == "") return 0;
        int ans = 0;
        unordered_map<int, int> mp;
        int l=0, r=0;
        while(r<n){
            if(mp.find(s[r]) == mp.end() || mp[s[r]]<l){
                mp[s[r]] = r;
                ans = max(ans, r-l+1);
                r++;
            }else l = mp[s[r]] + 1;
        }
        return ans;
    }

int main() {
    
}