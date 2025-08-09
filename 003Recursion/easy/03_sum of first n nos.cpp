#include <bits/stdc++.h>
using namespace std;

int suum(int n) {
    if (n == 1) return 1;
    return n + suum(n - 1);
}

int main() {
    int n = 5;
    cout << suum(n) << endl;
}