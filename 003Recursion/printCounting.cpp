#include <iostream>
using namespace std;


// prints the nos. in reverse order (first prints and then recalls)
void count(int n) {
    if (n<1) return;
    cout << n << endl;
    count(n-1);
}

// prints the nos. in increasing order, does backtracking. (first recalls and then prints)
void countBacktrack(int n) {
    if (n<1) return;
    countBacktrack(n-1);
    cout << n << endl;
}

int main() {
    count(10);
}