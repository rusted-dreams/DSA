#include <bits/stdc++.h>
using namespace std;

char closestSquare(char ch) {
    vector<int> squares = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225 };
    int diff = INT_MAX;
    char square;
    for (int i : squares) {
        int a = ch;
        if (abs(a - i) < diff) {
            diff = abs(a - i);
            square = i;
        }
    }
    return (char)square;

}

string squareOff(string s) {
    string res = "";
    for (char ch : s) {
        char closest = closestSquare(ch);
        res += closest;
    }
    return res;
}

int main() {
    string s = "ZOPSMART";
    string res = squareOff(s);
    cout << res << endl;
}