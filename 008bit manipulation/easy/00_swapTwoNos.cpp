#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 7;
    int b = 8;

    a = a^b;
    b = a^b;  // => equivalent to (a^b)^b => b = a;
    a = a^b;  // => equivalent to (a^b)^a; since now b = a;
}