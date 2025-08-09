#include <bits/stdc++.h>
using namespace std;

void printNtimes(int n, string name) {
    if (n == 0) return;
    cout << name << endl;
    printNtimes(n - 1, name);
}

int main() {
    printNtimes(5, "sam");
}