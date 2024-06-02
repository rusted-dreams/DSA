#include <iostream>
using namespace std;

//print the first n fiboancci nos.

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    int a = 0;
    int b = 1;

    cout << a << " " << b << " ";
    for (int i=0; i<n-2; i++){
        int next = a+b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}