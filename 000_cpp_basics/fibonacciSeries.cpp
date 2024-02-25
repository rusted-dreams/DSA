#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int j = 1;
    int n;
    cout << "Fibonacci series upto: ";
    cin >> n;
    cout << "First " << n << " terms of the Fibonacci series is: "<< endl;
    cout << i << endl << j << endl; 
    for (int k=1; k<=n; k++) {
        int next = i + j;
        cout << next << endl;
        i = j;
        j = next;

    } 
}