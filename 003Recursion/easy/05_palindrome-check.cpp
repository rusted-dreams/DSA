#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int l, int r, string& s) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return isPalindrome(++l, --r, s);
}
int main() {
    string s = "madaem";
    cout << isPalindrome(0, 4, s) << endl;
}