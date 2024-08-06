#include <iostream>
using namespace std;


//parameterised recursion
void printNnos(int x, int start) {
    if (start > x)
        return;
    cout << start << endl;
    printNnos(x, start+1);

}

//using backtracking
void printNos(int n) {
    if (n<1) {
        return;
    }
    printNos(n-1);
    cout << n << endl;
}

int main() {
    int x = 6, start = 1;
    printNos(x);
}